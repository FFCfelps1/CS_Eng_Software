/**
 * @file moteurRendu.hpp
 * @author Michel Ianotto
 *
 * @brief Interface pour les différents formats d'exportation.
 *
 */
#pragma once

#include <iostream>

class MoteurRendu {
public:

    virtual void dessinerCercle(double x, double y, double rayon) = 0;

    virtual void dessinerRectangle(double x, double y, double longueur, double largeur) = 0;

    virtual void dessinerLigne(double x1, double y1, double x2, double y2) = 0;

    virtual ~MoteurRendu() = default;
};


