#include <iostream>
#include <memory>
using namespace std;

class MyClass {
public:
    void show() {
        cout << "Object created\n";
    }

private:
    MyClass() = default; // private constructor
    MyClass(const MyClass&) = delete;
    MyClass& operator=(const MyClass&) = delete;
};

int main() {
    unique_ptr<MyClass> p1 = make_unique<MyClass>();
    p1->show();

    // unique_ptr cannot be copied
    // unique_ptr<MyClass> p2 = p1;   // ERROR: copy constructor is deleted

    return 0;
}
//*********example of unique_ptr *********/
class Logger {
public:
    static Logger& getInstance() {
        static unique_ptr<Logger> instance = make_unique<Logger>();
        return *instance;
    }

    void log(string msg) {
        cout << msg << endl;
    }

private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

int main() {
    Logger& l1 = Logger::getInstance();
    Logger& l2 = Logger::getInstance();

    l1.log("First log");
    l2.log("Second log");

    cout << (&l1 == &l2) << endl; // 1 -> same object
}
/*simple rule 
unique_ptr<MyClass> p = make_unique<MyClass>();
MyClass(const MyClass&) = delete;
MyClass& operator=(const MyClass&) = delete;
*/