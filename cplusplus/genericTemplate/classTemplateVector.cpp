#include<iostream>
using namespace std;
template<typename T>
class MyVector{
    T *arr; 
    int mcapacity;

    public:
    int capacity() const {
        return mcapacity;
    }
    MyVector(int c):mcapacity(c){
        arr = new T[mcapacity];
    }
     void push_back(const T& value){
        if(capacity() == 0) {
            cout << "Vector is full. Cannot add more elements." << endl;
            return;
        }
        arr[capacity() - 1] = value; // Add the new element at the end of the array
        mcapacity--; // Decrease the capacity after adding an element                                   
     }
     T& deleteElement(int index) {
        if (index < 0 || index >= capacity()) {
            cout << "Invalid index. Cannot delete element." << endl;
            return T(); // Return default-constructed T to indicate an error
        }
        T deletedValue = arr[index]; // Store the value to be deleted
        for (int i = index; i < capacity() - 1; ++i) {
            arr[i] = arr[i + 1]; // Shift elements to the left
        }
        mcapacity++; // Increase the capacity after deleting an element
        return deletedValue; // Return the deleted value
    }
    T getElement(int index) const {
        if (index < 0 || index >= capacity()) {
            cout << "Invalid index. Cannot access element." << endl;
            return -1; // Return -1 to indicate an error
        }
        return arr[index]; // Return the element at the specified index
    }
    ~MyVector() {
        delete[] arr;
    }
};

int main() {
    MyVector<int> myvectors(5); // Create a MyVector object for integers with capacity 5
    myvectors.push_back(10);
    myvectors.push_back(20);
    myvectors.push_back(30);
    myvectors.push_back(40);
    myvectors.push_back(50);    
    int deletedValue = myvectors.deleteElement(2); // Delete the element at index 2 (30)
    if (deletedValue != -1) {
        cout << "Deleted value: " << deletedValue << endl;  
    }       
    cout << "Elements in the vector after deletion:" << endl;

    for (int i = 0; i < myvectors.capacity()-1; ++i) {
        int element = myvectors.getElement(i);              

        if (element != -1) {
            cout << element << " "; // Print the elements in the vector
        }                       
    }
    cout << endl;
}

