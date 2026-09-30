/**
 * @file main1.cpp
 * @author Michel Ianotto
 *
 * @brief Programme principal
 *
 *
 *   g++ -std=c++20 -I. -o main1 main1.cpp
*/
#include <iostream>

#include "moteurRenduPDF.hpp"
#include "moteurRenduPNG.hpp"
#include "moteurRenduSVG.hpp"
#include "cercle.hpp"
#include "rectangle.hpp"
#include "ligne.hpp"

int main()
{
    Cercle c(100,100,50);
    Rectangle r(20,30,200,100);
    Ligne l(10, 10, 20, 20);

    MoteurRenduPNG moteurPNG;
    MoteurRenduPDF moteurPDF;
    MoteurRenduSVG moteurSVG;

    std::cout << "\n===== PDF =====\n";

    c.dessiner(moteurPDF);
    r.dessiner(moteurPDF);
    l.dessiner(moteurPDF);
    
    std::cout << "\n===== PNG =====\n";

    c.dessiner(moteurPNG);
    r.dessiner(moteurPNG);
    l.dessiner(moteurPNG);

    std::cout << "\n===== SVG =====\n";

    c.dessiner(moteurSVG);
    r.dessiner(moteurSVG);
    l.dessiner(moteurSVG);

}