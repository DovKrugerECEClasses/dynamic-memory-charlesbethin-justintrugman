#pragma once

#include "vector"
#include "iostream"
using namespace std;



class Design {
private:
    vector<shape*> exp;

public:
    void add(shape* s) {
        exp.push_back(s);
    }

    void write(string file) {
        ofstream f;

        f.open(file);
        f<<"solid "<<f<<'\n';
        for(int i=0;i<exp.size();i++){
            exp[i]->writeIn(file);
        }
        f<<"endsolid "<<file<<'\n';
        f.close();


    }

};