#include<iostream>
#include<mutex> 

using namespace std;
/*
[capture](parameters) -> return_type
{
    body
};
*/
int main()
{
    int x=7;
    auto evenNumber = [x](int a)
    {
        return a % 2 == 0;
    };
    if(evenNumber(x))
    {
        cout<<"number is even"<<endl;
    }else 
    cout<<"noteven"<<endl;

    //2nd ex 
    auto sum = [](int a , int b)
    {
        return a + b;
    }; 

    cout<<sum(10,20);

    // 2rd example *******
    // in other function captured list can not be access like 
    /* int x=10*/
    int x = 10; 
    int y = 20; 
    auto f = [=](){ //cature everythings 
        cout<< x + y;
    };
    
    f(); // lambda f already prints the result, no need to cout it
    ///not lambda
    int number = 123;

    while(number > 0)
    {
        int number1 = number%10;
        number = number/10;
        cout<<endl<<"number:"<<number1;
    }

    return 0;
}