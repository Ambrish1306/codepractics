#include<memory>
#include<iostream>      
using namespace std;
template <typename T>
class UniquePtrDemo {
    unique_ptr<T> ptr;
    public:
    UniquePtrDemo(T val){
        ptr = make_unique<T>(val);
    }
};
int main()
{
    // Create a unique_ptr that manages an integer
    unique_ptr<int> ptr1(new int(42));
    auto ptr3 = make_unique<int>(55);
    cout << "Value managed by ptr1: " << *ptr1 << endl;
    
    //create unique_ptr of class type
    unique_ptr<UniquePtrDemo<int>> uptrDemo = make_unique<UniquePtrDemo<int>>(10);

    // Transfer ownership from ptr1 to ptr2 using std::move
    unique_ptr<int> ptr2 = std::move(ptr1);
    if (!ptr1) {
        cout << "ptr1 is now null after move." << endl;
    }
    cout << "Value managed by ptr2: " << *ptr2 << endl;

    // Create a shared_ptr that manages an integer
    shared_ptr<int> sptr1 = make_shared<int>(100);
    cout << "Value managed by sptr1: " << *sptr1 << endl;
    cout << "Reference count of sptr1: " << sptr1.use_count() << endl;

    // Create another shared_ptr that shares ownership with sptr1
    shared_ptr<int> sptr2 = sptr1;
    cout << "Value managed by sptr2: " << *sptr2 << endl;
    cout << "Reference count after sharing ownership: " << sptr1.use_count() << endl;

    return 0;
}