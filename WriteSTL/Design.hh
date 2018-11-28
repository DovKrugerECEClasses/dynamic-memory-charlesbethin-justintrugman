#pragma once

#include "vector"
#include "iostream"
#include <fstream>
using namespace std;



class Design {
private:
    vector<const Shape*> shapes;

public:
    void add(const Shape& s) {
        shapes.push_back(&s);
    }

    void write(string file) const {
        ofstream f;

        f.open(file);
        for(int i=0;i<shapes.size();i++){
            f << "solid Shape" << std::to_string(i) << '\n';
            f << shapes[i]->stl() << '\n';
            f<<"endsolid Shape" << std::to_string(i) <<'\n';
        }
        f.close();
    }

};