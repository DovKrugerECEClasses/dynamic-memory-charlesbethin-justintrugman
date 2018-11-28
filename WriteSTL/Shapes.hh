#pragma once

#include <string>
#include "Vec3d.hh"

class Shape {
private: 
    double x, y, z;
public:
    Shape(double x, double y, double z) : x(x), y(y), z(z) { }
    virtual double volume() = 0;
    virtual std::string stl() = 0;

    void translate(double xVal, double yVal, double zVal) {
        x += xVal;
        y += yVal;
        z += zVal;
    }
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }
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

    std::string stl() {
        Vec3d sides[8] = {
            Vec3d(0, 0, 0).scaledBy(sideLen),
            Vec3d(0, 0, 1).scaledBy(sideLen),
            Vec3d(0, 1, 0).scaledBy(sideLen),
            Vec3d(0, 1, 1).scaledBy(sideLen),
            Vec3d(1, 1, 0).scaledBy(sideLen),
            Vec3d(1, 1, 1).scaledBy(sideLen),
            Vec3d(1, 0, 0).scaledBy(sideLen),
            Vec3d(1, 0, 1).scaledBy(sideLen)
        };

        std::string output = "";

        for(int i = 0; i < 4; i++) {
            Vec3d normalVector = findNormalVector(sides[2*i] - sides[2*i+1], sides[(2*i+1)%8] - sides[(2*i+2)%8]);

            output += "facet normal " + normalVector.toString() + "\n";
            output += "    outer loop\n";
            output += "        vertex " + sides[(2*i) % 8].toString() + "\n";
            output += "        vertex " + sides[(2*i + 1) % 8].toString() + "\n";
            output += "        vertex " + sides[(2*i + 2) % 8].toString() + "\n";
            output += "    endloop\nendfacet\n";

            output += "facet normal " + normalVector.toString() + "\n";
            output += "    outer loop\n";
            output += "        vertex " + sides[(2*i+2) % 8].toString() + "\n";
            output += "        vertex " + sides[(2*i + 1) % 8].toString() + "\n";
            output += "        vertex " + sides[(2*i + 3) % 8].toString() + "\n";
            output += "    endloop\nendfacet\n";
        }

        output += "facet normal 0 0 -1\n";
        output += "    outer loop\n";
        output += "        vertex " + sides[0].toString() + "\n";
        output += "        vertex " + sides[4].toString() + "\n";
        output += "        vertex " + sides[6].toString() + "\n";
        output += "    endloop\nendfacet\n";

        output += "facet normal 0 0 -1\n";
        output += "    outer loop\n";
        output += "        vertex " + sides[4].toString() + "\n";
        output += "        vertex " + sides[0].toString() + "\n";
        output += "        vertex " + sides[2].toString() + "\n";
        output += "    endloop\nendfacet\n";

        output += "facet normal 0 0 1\n";
        output += "    outer loop\n";
        output += "        vertex " + sides[3].toString() + "\n";
        output += "        vertex " + sides[7].toString() + "\n";
        output += "        vertex " + sides[5].toString() + "\n";
        output += "    endloop\nendfacet\n";

        output += "facet normal 0 0 1\n";
        output += "    outer loop\n";
        output += "        vertex " + sides[7].toString() + "\n";
        output += "        vertex " + sides[3].toString() + "\n";
        output += "        vertex " + sides[1].toString() + "\n";
        output += "    endloop\nendfacet\n";

        return output;
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