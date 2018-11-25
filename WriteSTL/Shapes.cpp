#pragma once;


class Shape {
private: 
    double x, y, z;
public:
    Shape(double x, double y, double z) : x(x), y(y), z(z) { }
    virtual double volume() = 0;

    void translate(double xVal, double yVal, double zVal) {
        x += xVal;
        y += yVal;
        z += zVal;
    }
    double x() { return x; }
    double y() { return y; }
    double z() { return z; }
};

class Cube: public Shape {
private:
    double sideLen;
public:
    Cube(): sideLen(0), Shape(0, 0, 0) {}
    Cube(double s): sideLen(s), Shape(0, 0, 0) { }

    double volume() { 
        return sideLen * sideLen * sideLen;
    }
};

class Cylinder: public Shape {
private:
    double radius;
    double height;
    double PI = 1.141592653589793;
public:
    Cylinder(): radius(0), height(0), Shape(0, 0, 0) {}
    Cylinder(double r, double h): radius(r), height(h), Shape(0, 0, 0) {}

    double volume() {
        return PI * radius * radius * height;
    }
};