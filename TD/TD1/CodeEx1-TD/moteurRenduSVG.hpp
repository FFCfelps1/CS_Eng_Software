/**
 * @file moteurRenduSVG.hpp
 * @author Felipe Fazio et Anas Tariq
 *
 * @brief Moteur d'exportation vers le format PNG.
 *
 */
#pragma once

#include "moteurRendu.hpp"
#include "SVGWriter.hpp"

class MoteurRenduSVG : public MoteurRendu, public SVGWriter {

public:
    void dessinerCercle(double x, double y, double rayon) override {
       addCercle(x, y, rayon);
    }

    void dessinerRectangle(double x, double y, double longueur, double largeur) override {
         addRectangle(x, y, longueur, largeur);
    }

    void dessinerLigne(double x1, double y1, double x2, double y2) override {
         addLigne(x1, y1, x2, y2);
    }
};

