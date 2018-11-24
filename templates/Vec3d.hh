#pragma once

#include <iostream>
#include <cmath>
using namespace std;

template <class Vec>

class Vec3d{
private:
  Vec x = 0, y = 0, z = 0;

public:
    Vec3d(Vec xInput, Vec yInput, Vec zInput) : x(xInput), y(yInput), z(zInput) {}

    Vec3d operator +(Vec3d right) const{
        return Vec3d(right.x + x, right.y + y, right.z + z);
    }

  
    friend ostream& operator <<(ostream& s, Vec3d xyz ) {
        s << xyz.x << ", " << xyz.y << ", " << xyz.z << '\n';
    return s;
    }
};
