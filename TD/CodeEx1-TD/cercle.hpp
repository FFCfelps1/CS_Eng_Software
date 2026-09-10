#pragma once

#include "forme.hpp"

class Cercle : public Forme {
private:
    double x_;
    double y_;
    double rayon_;

public:
    Cercle(double x, double y, double r) : x_(x), y_(y), rayon_(r){
    }
    void dessiner(MoteurRendu& moteur) override {
        moteur.dessinerCercle(x_, y_, rayon_);
    }
};
