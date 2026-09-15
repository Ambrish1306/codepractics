#include <memory>
using namespace std;
class B;
class A
{
    public:
    shared_ptr<B> objectB;//hold the shared pointer of class B
    void print() {

    }   
   

}; 
class B 
{
    public:
    shared_ptr<A> objectA;
    void print() {

    }


};
class NoDefault {
    int _x;
public:
    NoDefault() {
        _x = 0;
    }
    NoDefault(int x) 
     {_x = x;} // Only has a parameterized constructor
};

class MyClass {
    NoDefault _member;
public:
    // ❌ FAIL: Compilers tries to call NoDefault() here before the body runs
    MyClass(int val) { 
        _member = NoDefault(val); 
    }

    //  SUCCESS: Member is initialized directly with arguments
    MyClass(int val) : _member(val) { } 
};

class Base{
    int _x;
    public: 
    Base(int x): _x(x){} //parameterized constructor
    virtual ~Base(){}
};
class Drived : public Base{
    int _y;
    int *number;
public:
    Drived(int x, int y): Base(x), _y(y), number(new int(0)){} //parameterized constructor
    ~Drived() { delete number; }

};
int main ()
{
    auto objA = make_shared<A>();
    auto objB = make_shared<B>();
    objA->objectB = objB;
    objB->objectA = objA;

    //**************** */
    Base *obj = new Drived(10, 20);
    delete obj; // Calls the destructor of Drived and then Base

    Drived &doj= *new Drived(10, 20);

    Base &baseRef = doj;
     delete &baseRef; // ❌ Don't delete stack-allocated object

    return 0;
}