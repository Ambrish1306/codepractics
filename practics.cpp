#include<iostream>
#include<vector>
using namespace std;
class Vehicle {
    public:
    virtual void start()=0;
    virtual void stop()=0;
    virtual void capacity()=0;
};
class TwoWheeler: public Vehicle {
    public: 
    void start() override {
        cout<<"Two Wheeler started"<<endl;
    }
    void stop() override {
        cout<<"Two Wheeler stopped"<<endl;
    }
    void capacity() override {
        cout<<"Two Wheeler capacity is 2"<<endl;
    }
};
class FourWheeler: public Vehicle {
    public:
    void start() override {
        cout<<"Four Wheeler started"<<endl;
    }
    void stop() override {
        cout<<"Four Wheeler stopped"<<endl;
    }
    void capacity() override {
        cout<<"Four Wheeler capacity is 5"<<endl;
    }
};
int main() {
    vector<shared_ptr<Vehicle>> vehicles;

    vehicles.push_back(make_shared<TwoWheeler>());
    vehicles.push_back(make_shared<FourWheeler>());
    for(const auto& v: vehicles) {
        v->start();
        v->capacity();
        v->stop();
    }
    return 0;
}