#include <iostream>
using namespace std; 

class Animal 
{
    static int counte;
    public :
    static void countAnimal()
    {
        cout<<"Number of animal" << counte<<endl;
    }
    virtual void speak(){
        cout<<"Animal Sound"<<endl; 
    }
    Animal()
    {
        counte++;
    }
    virtual ~Animal(){};

};

class Dog : public Animal
{
    public:
    void speak() override {
        cout<<"Dog is bearking Waf waf"<<endl;
    }

};

class Cat: public Animal
{
 public:
    void speak() override {
        cout<<"Cat is bearking Mom Mon"<<endl;
    }

} ;

Animal::counte=0;

int main()
{
    Animal::countAnimal();
    Dog myDog; 
    Cat myCat;

    Animal *a1 = &myDog;//using pointer
    Animal *a2 = &myCat;


    a1->speak();
    a2->speak();

    delete a1; 

    Animal &aref = * new Cat();
    aref.speak();
    delete &aref;

    return 0;

}
