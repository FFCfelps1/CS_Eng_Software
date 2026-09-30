#pragma once

#include "forme.hpp"

class Cercle : public Forme {
private:
    double rayon_;

public:
    Cercle(double r) : rayon_(r){
    }
    void afficher() {
        std::cout << "Rectangle " << "(" << rayon_ << ")";
    };

    double aire (double r) {
        return r**2 * 3.14;

    };
};
