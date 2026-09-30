#pragma once

#include "forme.hpp"

class Rectangle : public Forme {
private:
    double largeur_;
    double hauteur_;

public:
    Rectangle(double l, double h)
        : largeur_(l), hauteur_(h) {
    }
    void Afficher() {
        std::cout << "Rectangle " << "(" << largeur_ << "," << hauteur_ << ")";
    }

    double aire (double l, double h) {
        return l * h;

    };
};
