#pragma once

#include "forme.hpp"

class Rectangle : public Forme {
private:
    double x_;
    double y_;
    double largeur_;
    double hauteur_;

public:
    Rectangle(double x,double y, double l, double h)
        : x_(x), y_(y), largeur_(l), hauteur_(h) {
    }
    void dessiner(MoteurRendu& moteur) override {
        moteur.dessinerRectangle(x_, y_, largeur_, hauteur_);
    }
};
