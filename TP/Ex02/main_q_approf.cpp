/*
*  g++  -g -std=c++20 -I. -o main2 main2.cpp cercle.cpp groupe.cpp rectangle.cpp exportSVGVisitor.cpp
*/

#include <groupe.hpp>
#include <rectangle.hpp>
#include <cercle.hpp>
#include <exportSVGVisitor.hpp>

#include <iostream>
#include <memory>

int main()
{

    // Construction de l'arborescence de formes géométriques
    // dessin représente la racine de l'arborescence
    auto dessin = std::make_shared<Groupe>(10, 10, 20);
    
    // Construction d'un groupe de forme géométriques
    auto groupe2 = std::make_shared<Groupe>(100, 50, 0);
    groupe2->ajouter(std::make_shared<Cercle>(10, -20, 0));
    groupe2->ajouter(std::make_shared<Cercle>(15, 20, 0));
    dessin->ajouter(groupe2);
    dessin->ajouter(std::make_shared<Rectangle>(40, 20, 0, 0));
    dessin->afficher();

    std::cout
        << std::endl;

    std::cout
        << "Aire totale = "
        << dessin->aire()
        << std::endl;

    ExportSVGVisitor exportSVG("dessin.svg");

    dessin->accepter(exportSVG);
}
