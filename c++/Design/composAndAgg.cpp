#include <iostream>
using namespace std;
//==============================================================|
//Created inside → Composition                                  |
//Passed from outside → Aggregation                             |   
//✅ Composition                                                |
//===============================================================|
class Engine {
public:
    Engine() { cout << "Engine Created\n"; }
    ~Engine() { cout << "Engine Destroyed\n"; }
};

class Car {
    Engine engine;   // ✅ Composition ->tightly coupled 
public:
    Car() { cout << "Car Created\n"; }
    ~Car() { cout << "Car Destroyed\n"; }
};

int main() {
    Car c;
}
/*Output :
Engine Created
Car Created
Car Destroyed
Engine Destroyed*/

//Aggregation
class Engine {
public:
    void start() { cout << "Engine Started\n"; }
};

class Car {
    Engine* engine;   // ⚠️ Aggregation->Independent Enginee can exit Independent to the car
    int engNumber; 
public:
    Car(Engine* e) : engine(e),engNumber(1777) {}

    void drive() {
        engine->start();
    }
};

int main() {
    Engine e;
    Car c(&e);
    c.drive();
}
/*“Aggregation is a relationship, 
while dependency injection is a technique to achieve loose coupling, often implemented using aggregation.”/

