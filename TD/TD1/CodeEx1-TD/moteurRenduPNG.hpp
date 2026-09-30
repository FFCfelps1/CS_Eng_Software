/**
 * @file moteurRenduPNG.hpp
 * @author Michel Ianotto
 *
 * @brief Moteur d'exportation vers le format PNG.
 *
 */
#pragma once

#include "moteurRendu.hpp"

class MoteurRenduPNG : public MoteurRendu {

public:
    void dessinerCercle(double x, double y, double rayon) override {
       std::cout << "PNG : cercle" << std::endl;
    }

    void dessinerRectangle(double x, double y, double longueur, double largeur) override {
         std::cout << "PNG : rectangle" << std::endl;
    }

    void dessinerLigne(double x1, double y1, double x2, double y2) override {
         std::cout << "PNG : ligne" << std::endl;
    }
};

