/*
*  g++  -g -std=c++20 -I. -o main2 main2.cpp cercle.cpp groupe.cpp rectangle.cpp 
*/

#include <groupe.hpp>
#include <rectangle.hpp>
#include <cercle.hpp>

#include <iostream>
#include <memory>

int main()
{
    // Construction de l'arborescence de formes géométriques
    // dessin représente la racine de l'arborescence
    auto dessin = std::make_shared<Groupe>(10, 10, 0);
    // Construction d'un groupe de forme géométriques
    auto groupe1 = std::make_shared<Groupe>(100, 50, 0);
    // Construction d'un cercle de rayon 10 et de centre -20, 0 et ajout du cercle au groupe1
    groupe1->ajouter(std::make_shared<Cercle>(10, -20, 0));
    // Construction d'un cercle de rayon 15 et de centre 20, 0 et ajout du cercle au groupe1   
    groupe1->ajouter(std::make_shared<Cercle>(15, 20, 0));
    // Ajout du groupe1 au dessin
    dessin->ajouter(groupe1);
    // Construction d'un rectangle de largeur 80 et de hauteur 20 avec un coin 
    // supérieur gauche de coordonnées (0,0) et ajout du rectangle au dessin
    dessin->ajouter(std::make_shared<Rectangle>(80, 20, 0, 0));
    // Affichage des formes géométriques
    dessin->afficher();

    std::cout
        << std::endl;

    // Calcul et affichage de l'aire totale des formes géomètriques
    std::cout
        << "Aire totale = "
        << dessin->aire()
        << std::endl;
 
    // Export du dessin dans un fichier svg
    std::ofstream fichier;
    fichier.open("dessin.svg");

    fichier
        << "<svg xmlns=\"http://www.w3.org/2000/svg\">"
        << std::endl;
    dessin->exportSVG(fichier);
    fichier << "</svg>";
    fichier.close();
}
