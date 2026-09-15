#include <iostream>
using namespace std;
class RuleOfFive {
    int* data;

public:
    /// initialize data member in member initializer list
    RuleOfFive(int val) : data(new int(val)) {}
    
    // Alternative way to initialize in constructor body
     /*RuleOfFive(int val) {
         data = new int(val);
    }*/
    // 1️⃣ Destructor
    ~RuleOfFive() {
        delete data;
    }
    // 2️⃣ Copy constructor
    RuleOfFive(const RuleOfFive& other) {
        data = new int(*other.data);
    }

    // 3️⃣ Copy assignment
    RuleOfFive& operator=(const RuleOfFive& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
            //other.data = nullptr;//not correct as accessed through const object.
        }
        return *this;
    }

    // 4️⃣ Move constructor
    RuleOfFive(RuleOfFive&& other) noexcept {
        data = other.data;
        other.data = nullptr;
    }

    // 5️⃣ Move assignment
    RuleOfFive& operator=(RuleOfFive&& other) noexcept {
        if (this != &other) {
            delete data;// Free existing resource
            data = other.data;// Transfer ownership
            other.data = nullptr;// Leave other in a valid state
        }
        return *this;// Return *this to allow chained assignments
    }
    void print() 
    {
        cout<<"this is RuleOffiv class";
    }
};


int main(){
    RuleOfFive obj1(10);
    RuleOfFive obj2 = obj1; // Calls copy constructor
    RuleOfFive obj3(20);
    obj3 = obj1;        // Calls copy assignment operator
    RuleOfFive obj4 = std::move(obj1); // Calls move constructor
    obj1.print();
    RuleOfFive obj5(30);
    obj5 = std::move(obj3); // Calls move assignment operator

    return 0;
}
