#include<mutex>
#include<iostream>
#include<condition_variable>
#include<queue>
#include<thread>

using namespace std; 

mutex mtx; 
condition_variable cv; 
int num =1; 

void printA()
{
   while (num <= 10)
   {
     unique_lock<mutex> lock(mtx);
     cv.wait(lock,[]{return num > 10 || num % 3 == 0;});
     if(num > 10 ) break;
     cout<<"PrintA:"<<num++;
     cv.notify_all();
   }
}
void printB()
{
   while (num <= 10)
   {
     unique_lock<mutex> lock(mtx);
     //If condition is false → thread sleeps
     //If condition is true → thread continues
     cv.wait(lock,[]{return num > 10 || (num % 2==0 && num % 3 != 0);});
     if(num > 10 ) break;
     cout<<"PrintB:"<<num++;
     cv.notify_all();
   }
}
void printC()
{
  while (num <= 10)
   {
     unique_lock<mutex> lock(mtx);
     cv.wait(lock,[]{return num > 10 || (num % 2 !=0 && num % 3 != 0);});
     if(num > 10 ) break;
     cout<<"PrintC:"<<num++;
     cv.notify_all();
   }
}
int main()
{
    thread t1(printA);
    thread t2(printB);
    thread t3(printC);
    t1.join();
    t2.join();
    t3.join(); 
    return 0;
}

