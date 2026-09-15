///memory_order_relaxed example: Alternating Odd and Even Number Printing using Atomic Variables in C++
//fetch_add.
//yield is used to avoid busy-waiting consuming too much CPU while waiting for the condition to change.
#include <iostream>
#include <thread>
#include <atomic>
using namespace std;//group related name and identifier in a single unit

atomic<int> num{1};
const int MAX = 10;
mutex mtx; // Mutex to protect the atomic variable during printing

void printOdd() {
    while (true) {
        int value = num.load(memory_order_relaxed);
        if (value > MAX)
            break;
        if (value % 2 == 1) {
            {
            lock_guard<mutex> lock(mtx); // Locking the atomic variable to ensure thread safety
            cout << "Odd  : " << value << endl;
            }
            num.fetch_add(1, memory_order_relaxed);
        } else {
            // busy-wait until it's odd
            this_thread::yield();
        }
    }
}

void printEven() {
    while (true) {
        int value = num.load(memory_order_relaxed);
        if (value > MAX)
            break;
        if (value % 2 == 0) {
            {
            lock_guard<mutex> lock(mtx); // Locking the atomic variable to ensure thread safety
            cout << "Even : " << value << endl;
            }
            num.fetch_add(1, memory_order_relaxed);
        } else {
            // busy-wait until it's even
            this_thread::yield();
        }
    }
}

int main() {
    thread t1(printOdd);
    thread t2(printEven);
    

    t1.join();
    t2.join();

    return 0;
}
