#include <iostream>
#include <exception>
using namespace std;

// Custom exception class
class NegativeValueException : public exception {
private:
    int value;
public:
    // Constructor
    NegativeValueException(int val) : value(val) {}

    // Override what() method
    const char* what() const noexcept override {
        return "Negative value error occurred!";
    }
};

// Function that throws the custom exception
void checkValue(int x) {
    if (x < 0) {
        throw NegativeValueException(x);
    }
    else {
        cout << "Value is: " << x << endl;
    }
}

int main() {
    int numbers[] = {10, -5, 20};

    for (int n : numbers) {
        try {
            checkValue(n);
        }
        catch (const NegativeValueException &e) {
            cout << "Exception caught: " << e.what() << endl;
        }
    }

    return 0;
}

/*Use exceptions only for exceptional situations.
Catch exceptions by const reference.
Prefer standard exception classes when possible.
Use RAII for resource management.
Avoid generic catch(...) unless necessary.
*/