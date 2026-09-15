// Spinlock sample problem: Multiple threads increment a shared counter using a custom spinlock
#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

class SpinLock {
	atomic_flag flag = ATOMIC_FLAG_INIT;
public:
	void lock() {
		while (flag.test_and_set(std::memory_order_acquire)) {
			// spin (busy-wait)
		}
	}
	void unlock() {
		flag.clear(std::memory_order_release);
	}
};

int main() {
	const int numThreads = 4;
	const int incrementsPerThread = 100000;
	int counter = 0;
	SpinLock spinlock;

	auto worker = [&]() {
		for (int i = 0; i < incrementsPerThread; ++i) {
			spinlock.lock();
			++counter;
			spinlock.unlock();
		}
	};

	thread threads[numThreads];
	for (int i = 0; i < numThreads; ++i) {
		threads[i] = thread(worker);
	}
	for (int i = 0; i < numThreads; ++i) {
		threads[i].join();
	}

	cout << "Final counter value: " << counter << endl;
	cout << "Expected value: " << numThreads * incrementsPerThread << endl;
	return 0;
}
