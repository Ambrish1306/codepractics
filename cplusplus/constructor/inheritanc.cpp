#include<iostream>
using namespace std;
class A{
    int x;
    public:
    A(int x):x(x)
    {
        cout<<"Constructor A called, x = "<<x<<endl;
    }
   virtual ~A()
    {
        cout<<"distructor A called"<<endl;
    }

};
class B : virtual public A { //to avoid ambiguity in diamond problem we are using vitual inheritance
    const int x;
    public:
    B(int x):x(x),A(x)
    {
        cout<<"Constructor B called, x = "<<x<<endl;
    }
    ~B()
    {
        cout<<"distructor B called"<<endl;
    }
};
class C: virtual public A,public B{/// this order matter for object
    const int x;
    public:
    C(int x):x(x),B(x),A(x)
    {
        cout<<"Constructor C called, x = "<<x<<endl;
    }
    ~C()
    {
        cout<<"distructor C called"<<endl;
    }
};
int main()
{
    C objC(10); 
    return 0;
}

/***************************LEARNING*****************************************/
