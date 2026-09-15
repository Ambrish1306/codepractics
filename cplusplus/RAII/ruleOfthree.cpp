#include <iostream>
using namespace std;
class RuleOfThree {
    int* data;

public:
    RuleOfThree(int val) {
        data = new int[val];
        cout << "Resource allocated of size " << val << std::endl;
    }

    // 1️⃣ Destructor
    ~RuleOfThree() {
        delete[] data;
        cout << "Resource deallocated" << std::endl;
    }

    // 2️⃣ Copy constructor (deep copy)
    RuleOfThree(const RuleOfThree& other) {
        data = new int[*other.data];
        cout << "Copy constructor called" << std::endl;
    }

    // 3️⃣ Copy assignment operator
    RuleOfThree& operator=(const RuleOfThree& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        cout << "Copy assignment operator called" << std::endl;
        return *this;
    }
};
int main() {
    RuleOfThree obj1(10);
    RuleOfThree obj2 = obj1; // Calls copy constructor
    RuleOfThree obj3(20);
    obj3 = obj1;        // Calls copy assignment operator

    return 0;
}