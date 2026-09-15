#include <iostream>
#include <stdexcept>

using namespace std;

// Single interface for all shapes (Violates ISP)
/*class Shape {
public:
    virtual double area() = 0;
    virtual double volume() = 0; // 2D shapes don't have volume!
};*/
class TwoDShape{
public: 
        virtual double area() = 0;
};
class ThreeDShapw{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

// Square is a 2D shape but is forced to implement volume()
class Square : public TwoDShape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override {
        return side * side;
    }
/*
    double volume() override {
        throw logic_error("Volume not applicable for Square"); // Unnecessary method
    }*/
};

// Rectangle is also a 2D shape but is forced to implement volume()
class Rectangle : public TwoDShape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }

   /*double volume() override {
        throw logic_error("Volume not applicable for Rectangle"); // Unnecessary method
    }*/
};

// Cube is a 3D shape, so it actually has a volume
class Cube : public ThreeDShapw {
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double area() override {
        return 6 * side * side;
    }

    double volume() override {
        return side * side * side;
    }
};

int main() {
    TwoDShape* square = new Square(5);
    TwoDShape* rectangle = new Rectangle(4, 6);
    ThreeDShapw* cube = new Cube(3);

    cout << "Square Area: " << square->area() << endl;
    cout << "Rectangle Area: " << rectangle->area() << endl;
    cout << "Cube Area: " << cube->area() << endl;
    cout << "Cube Volume: " << cube->volume() << endl;

    /*try {
        cout << "Square Volume: " << square->volume() << endl; // Will throw an exception
    } catch (logic_error& e) {
        cout << "Exception: " << e.what() << endl;
    }*/
    
    return 0;
}