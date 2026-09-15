#include <iostream>
using namespace std;    
//function template to add two values of any data type
template <typename T>
T avg(T a, T b) {
    return (a + b) / 2;
}


int main () { 
  int a = 5, b = 10;
    double x = 5.5, y = 10.5;
    cout << "Average of integers: " << avg<int>(a, b) << endl;
    cout << "Average of doubles: " << avg<double>(x, y) << endl;

    return 0;
}