#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Vec3d{
public:
  double x = 0, y = 0, z = 0;

public:
    Vec3d(double xInput=0.0, double yInput=0.0, double zInput=0.0) : x(xInput), y(yInput), z(zInput) {}

    double dot(const Vec3d& r) const {
        return (x * r.x )+ (y * r.y) + (z * r.z);
    }

    double magSquared() const {
        return x*x + y*y + z*z;
    }

    double mag() const {
        return sqrt(magSquared());
    }

    std::string toString() {
        std::stringstream stream;
        stream << x << std::setprecision(5) << " ";
        stream << y << std::setprecision(5) << " ";
        stream << z << std::setprecision(5);
        return stream.str();
    }

    Vec3d scaledBy(double n) const {
        return Vec3d(x * n, y * n, z * n);
    }

    Vec3d operator +(const Vec3d& right) const {
        return Vec3d(right.x + x, right.y + y, right.z + z);
    }

    Vec3d operator -(const Vec3d& r) const {
        return Vec3d(x - r.x, y - r.y, z - r.z);
    }

    friend ostream& operator <<(ostream& s, const Vec3d& xyz) {
        s << xyz.x << ", " << xyz.y << ", " << xyz.z;
        return s;
    }

    friend Vec3d findNormalVector(const Vec3d& u, const Vec3d& v) {
        Vec3d result = Vec3d(u.y*v.z - v.y*u.z, u.x*v.z - v.x*u.z, u.x*v.y - v.x*u.y);
        return result.scaledBy(1/result.mag());
    }
};


