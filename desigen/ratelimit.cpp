#include <iostream>
#include <chrono>
#include <mutex>

class FixedWindowRateLimiter
{
private:
    int maxRequests;
    std::chrono::seconds windowSize;

    int requestCount;
    std::chrono::steady_clock::time_point windowStart;

    std::mutex mtx;

public:
    FixedWindowRateLimiter(int limit, int seconds): maxRequests(limit),windowSize(seconds),requestCount(0)
    {
        windowStart = std::chrono::steady_clock::now();
    }

    bool allowRequest()
    {
        std::lock_guard<std::mutex> lock(mtx);

        auto now = std::chrono::steady_clock::now();

        // Window expired
        if (now - windowStart >= windowSize)
        {
            requestCount = 0;
            windowStart = now;
        }

        if (requestCount < maxRequests)
        {
            ++requestCount;
            return true;
        }

        return false;
    }
};
int main()
{
    FixedWindowRateLimiter limiter(5, 60);

    for(int i = 1; i <= 7; i++)
    {
        if(limiter.allowRequest())
            std::cout << "Request " << i << " Allowed\n";
        else
            std::cout << "Request " << i << " Rejected\n";
    }
}