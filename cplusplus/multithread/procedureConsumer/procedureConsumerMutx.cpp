#include<mutex>
#include<iostream>
#include<condition_variable>
#include<queue>
#include<thread>

using namespace std; 

mutex mtx; 
condition_variable cv; 
queue<int> q;
const int MAX_SIZE =5; 
int number =1;
void procedure()
{
    int i=0;
    while(number <= 10)
    {
        {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, []{return q.size() < MAX_SIZE;});
            q.push(number++);
            cv.notify_one();
        }
       this_thread::sleep_for(chrono::milliseconds(100));
    }
}
void consumer()
{
    while(number <= 10)
    {
        int value;
        {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, []{return !q.empty();});
            value = q.front();
            q.pop();
            //cout<<"consumer"<<value;
            cv.notify_one();
        }
        
        cout<<"consumer"<<value;
       this_thread::sleep_for(chrono::milliseconds(100));
    }
}
int main() {
    std::thread t1(procedure);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}


