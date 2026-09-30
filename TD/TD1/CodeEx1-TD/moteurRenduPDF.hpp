/**
 * @file moteurRenduPDF.hpp
 * @author Michel Ianotto
 *
 * @brief Moteur d'exportation vers le format PDF.
 *
 */
#pragma once

#include "moteurRendu.hpp"

class MoteurRenduPDF : public MoteurRendu {

public:
    void dessinerCercle(double x, double y, double rayon) override {
       std::cout << "PDF : cercle" << std::endl;
    }

    void dessinerRectangle(double x, double y, double longueur, double largeur) override {
         std::cout << "PDF : rectangle" << std::endl;
    }

    void dessinerLigne(double x1, double y1, double x2, double y2) override {
         std::cout << "PDF : ligne" << std::endl;
    }
};

