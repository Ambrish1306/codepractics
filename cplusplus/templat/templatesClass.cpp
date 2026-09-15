#include <iostream>
using namespace std;
template <typename T>
class Test{ 
    T data;
public:
    Test(T val) : data(val) {}  
    void display() {
        cout << "Data: " << data << endl;
    }

}

int main() {
    Test<int> intObj(42);
    intObj.display();

    Test<double> doubleObj(3.14);
    doubleObj.display();

    Test<string> stringObj("Hello, Templates!");
    stringObj.display();

    return 0;
}