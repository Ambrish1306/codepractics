#include<thread>
#include<atomic>    
#include<iostream>

std::atomic<int> atomicCount=1;
void printNumber()
{
    for(int i=0;i<5;i++)
    {
        std::cout<<++atomicCount<<std::endl;
    }
}

int main()
{
    std::thread t1(printNumber); 
    std::thread t2(printNumber);
    t1.join();
    t2.join();
}