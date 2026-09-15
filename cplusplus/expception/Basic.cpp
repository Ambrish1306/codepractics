#include<iostream>
using namespace std;
int main () 
{
    int m=0; 
    try {
        if(m == 0) {
            throw "Division by zero error";
        }cout<<"I am after throw statement"<<endl;//this will not execute 
    }catch (const char* e) {
        cout << "Caught an exception: " << e << endl;
    }
    return 0;
}