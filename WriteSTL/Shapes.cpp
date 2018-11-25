class Shape {
private: 
    double x, y, z;
public:
    virtual void translate(double xVal, double yVal, double zVal) = 0;
};

class Cube: public Shape {

};

class Cylinder: public Shape {

};