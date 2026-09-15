#include<iostream> 
#include<string>
using namespace std;
/*  Failure Threshold Reached
        +------------------------------------------+
        |                                          |
        |                                          v
+---------------+                          +---------------+
|    CLOSED     |------------------------->|     OPEN      |
| Requests flow |                          | Requests fail |
+---------------+                          +---------------+
        ^                                          |
        |                                          |
        |      Timeout Expired                     |
        |                                          |
        |                                          v
        |                                  +---------------+
        +----------------------------------|   HALF OPEN   |
           Success Threshold Reached       | Allow few req |
                                           +---------------+
                                                  |
                             Failure              | Success
                                                  |
                                                  v
                                               CLOSED*/
//closed means continue to send txn 
//open no request reach to the server No network call.(wait for recover time)
//Half open Allow only a small number of requests.
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

class CircuitBreaker {
public:
    enum class State {
        CLOSED,
        OPEN,
        HALF_OPEN
    };

private:
    State state;

    int failureCount;
    int failureThreshold;

    int successCount;
    int successThreshold;

    std::chrono::seconds recoveryTimeout;

    std::chrono::steady_clock::time_point lastFailureTime;

public:

    CircuitBreaker(
            int failThreshold = 3,
            int successThreshold = 2,
            int timeout = 5)
        :
        state(State::CLOSED),
        failureCount(0),
        failureThreshold(failThreshold),
        successCount(0),
        successThreshold(successThreshold),
        recoveryTimeout(timeout)
    {}

    template<typename Func>
    bool execute(Func serviceCall)
    {
        updateState();

        if(state == State::OPEN)
        {
            std::cout << "Circuit OPEN. Request blocked.\n";
            return false;
        }

        try
        {
            bool result = serviceCall();

            if(result)
            {
                onSuccess();
                return true;
            }
            else
            {
                onFailure();
                return false;
            }
        }
        catch(...)
        {
            onFailure();
            return false;
        }
    }

private:

    void updateState()
    {
        if(state == State::OPEN)
        {
            auto now = std::chrono::steady_clock::now();

            if(now - lastFailureTime >= recoveryTimeout)
            {
                state = State::HALF_OPEN;
                successCount = 0;

                std::cout << "Transition -> HALF_OPEN\n";
            }
        }
    }

    void onSuccess()
    {
        if(state == State::HALF_OPEN)
        {
            successCount++;

            if(successCount >= successThreshold)
            {
                state = State::CLOSED;
                failureCount = 0;

                std::cout << "Transition -> CLOSED\n";
            }
        }
        else
        {
            failureCount = 0;
        }
    }

    void onFailure()
    {
        lastFailureTime = std::chrono::steady_clock::now();

        if(state == State::HALF_OPEN)
        {
            state = State::OPEN;

            std::cout << "HALF_OPEN Failure -> OPEN\n";
            return;
        }

        failureCount++;

        if(failureCount >= failureThreshold)
        {
            state = State::OPEN;

            std::cout << "Transition -> OPEN\n";
        }
    }
};

int main()
{
    CircuitBreaker cb(3, 2, 5);

    int count = 0;

    auto service = [&]() -> bool {

        count++;

        if(count <= 4)
        {
            std::cout << "Service Failed\n";
            return false;
        }

        std::cout << "Service Success\n";
        return true;
    };

    // Cause failures
    for(int i=0;i<5;i++)
    {
        cb.execute(service);
    }

    std::cout << "\nWaiting...\n";

    std::this_thread::sleep_for(std::chrono::seconds(6));

    cb.execute(service);
    cb.execute(service);

    return 0;
}