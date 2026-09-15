#include <iostream>
using namespace std;

class Vichle {
    int engineNo; 
    string engineType;
    public:
    Vichle():engineNo(12345),engineType("Petrol"){};//default constructor
    virtual void show(){
           cout<<"Engine No: "<<engineNo<<endl;
           cout<<"Engine Type: "<<engineType<<endl;
    }
   virtual void startEngine() =0;//pure virtual function

   virtual ~Vichle(){
        cout<<"Base class destructor called"<<endl;
    }
};
class Car : public Vichle {
    int wheels;
    int seats;
    public:
    Car():wheels(4),seats(5),Vichle(){};//constructor call order: base class first then derived class
    void show () override {
        cout<<"Car class derived from Vehicle class"<<wheels<<" wheels and "<<seats<<" seats"<<endl;
    }   

    void startEngine() override {
        cout << "Car engine started" << endl;
    }
    ~Car(){
        cout<<"Derived class destructor called"<<endl;
    }

};

int main(){
    Vichle *v=new Car();
    v->show();//call car class 
    v->Vichle::show(); //class preant class “Ignore polymorphism and explicitly call base class version”
    v->startEngine(); //call pure virtual function implemented in derived class
    delete v;
    return 0;
}
