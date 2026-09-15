#include<iostream>
#include<memory>
using namespace std;
int main () 
{
unique_ptr<int> uniqPtr = make_unique<int>(42);
cout << "Unique Pointer Value: " << *uniqPtr << endl;
shared_ptr<int> sharedPtr1 = make_shared<int>(100);
shared_ptr<int> sharedPtr2= sharedPtr1;
cout <<"sharedPtr1 vlaue : "<<*sharedPtr1<<endl;
cout <<"sharedPtr2 vlaue : "<<*sharedPtr2<<endl;    


    return 0;
}