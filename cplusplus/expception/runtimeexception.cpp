#include<iostream>
using namespace std;
void checkage(int age) {
    if(age < 18){
        throw runtime_error("Age must be at least 18.");
    } else {
        cout << "Age is valid." << endl;
    }
}
int main () {
    try{
        checkage(15);
    }catch (const runtime_error& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }
    return 0;
}

//logic_error 
//like invalid_argument, 
//domain_error, 
//length_error, 
//out_of_range
//runtime_error like range_error, overflow_error, underflow_error