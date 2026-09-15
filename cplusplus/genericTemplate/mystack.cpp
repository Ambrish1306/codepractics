#include<iostream>
using namespace std;
template<typename T>
class MyStack{
     T *arr;
     int maxSize;
     int topIndex;
    public:
    MyStack(int size):maxSize(size),topIndex(-1){
        arr = new T[maxSize];           
    }
    int size() const {
        return topIndex + 1;
    }
    void push(const T& value)
    {
        if(size() == maxSize) {
            throw std::overflow_error("Stack is full. Cannot push more elements.");
        }
        arr[++topIndex] = value; // Add the new element at the top of the stack
    }
    T pop(){
        if(size() == 0) {
            throw std::underflow_error("Stack is empty. Cannot pop elements.");
        }
        return arr[topIndex--]; // Return the top element and decrease the top index    
    }
    ~MyStack() {
        delete[] arr;
    }
};

int main() {
    MyStack<int> stack(5); // Create a MyStack object for integers with size 5
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Popped element: " << stack.pop() << endl; // Pop the
    int top = stack.pop(); // Pop the top element
    if (top != 0) { // Check if the popped element is valid
        cout << "Popped element: " << top << endl;  
    }
    if(stack.size() >0) {
        cout << "Current stack size: " << stack.size() << endl; // Display the current size of the stack
    } else {
        cout << "Stack is empty." << endl;
    }
    cout<<"Tell Hello to Innaya Pandey" << endl;
    return 0;
}