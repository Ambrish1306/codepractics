#include <iostream>
using namespace std;

class MyCopyConst
{
    int* data;

public:
    // Constructor
    MyCopyConst(int a)
    {
        data = new int(a);
    }

    // Copy Constructor (Deep Copy)
    MyCopyConst(const MyCopyConst& obj)
    {
        data = new int(*(obj.data));
    }

    // Copy Assignment Operator
    MyCopyConst& operator=(const MyCopyConst& obj)
    {
        if (this != &obj)
        {
            delete data;  
            data = new int(*(obj.data));
        }
        return *this;
    }

    // Move Constructor
    MyCopyConst(MyCopyConst&& obj) noexcept
    {
        data = obj.data;
        obj.data = nullptr;
    }

    // Move Assignment Operator
    MyCopyConst& operator=(MyCopyConst&& obj) noexcept
    {
        if (this != &obj)
        {
            delete data;
            data = obj.data;
            obj.data = nullptr;
        }
        return *this;
    }

    // Destructor
    ~MyCopyConst()
    {
        delete data;
    }

    void print() const
    {
        if (data)
            cout << *data << endl;
        else
            cout << "nullptr" << endl;
    }
};

int main()
{
    MyCopyConst obj(10);
    MyCopyConst obj1 = obj;   // Copy constructor

    MyCopyConst obj2 = std::move(obj);  // Move constructor

    obj.print();   // nullptr
    obj1.print();  // 10
    obj2.print();  // 10
}