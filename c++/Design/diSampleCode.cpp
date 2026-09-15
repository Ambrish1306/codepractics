class Engine {
public:
    virtual void start() = 0;
};

class PetrolEngine : public Engine {
public:
    void start() override { cout << "Petrol Engine\n"; }
};

class Car {
    Engine* engine;
public:
    Car(Engine* e) : engine(e) {}   // ✅ injected via constructor

    void drive() {
        engine->start();
    }
};
//===================================================================================================
class Car2 {
    Engine* engine;
public:
    void setEngine(Engine* e) {   // ✅ injected later
        engine = e;
    }

    void drive() {
        if(engine) engine->start();
    }
};
//===========================================================================================================================
class Car3 {
public:
    void drive(Engine* engine) {   // ✅ passed per call
        engine->start();
    }
};
//=====================================================================================
int main() {
    PetrolEngine p;

    // Constructor Injection
    Car c1(&p);
    c1.drive();
//===========================================
    // Setter Injection
    Car2 c2;
    c2.setEngine(&p);
    c2.drive();
//=============================================================
    // Method Injection
    Car3 c3;
    c3.drive(&p);
}