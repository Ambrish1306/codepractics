#include<iostream>
using namespace std;

template<typename T>
void addTwoNumbers(T a, T b)
{
    cout<<"Sum of two numbers is: "<<a+b<<endl;
}

int main() 
{
    addTwoNumbers(5, 10); // Calling the function with integer arguments
    addTwoNumbers(3.5, 2.5); // Calling the function with double arguments
}