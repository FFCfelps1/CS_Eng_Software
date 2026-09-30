#pragma once

#include "forme.hpp"

class Ligne : public Forme {
private:
    double x1_;
    double y1_;
    double x2_;
    double y2_;

public:
    Ligne(double x1, double y1, double x2, double y2) : 
        x1_(x1), y1_(y1), x2_(x2), y2_(y2) {
    }
    void dessiner(MoteurRendu& moteur) override {
        moteur.dessinerLigne(x1_, y1_, x2_, y2_);
    }
};
