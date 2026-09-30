#include "groupe.hpp"
#include "rectangle.hpp"
#include "cercle.hpp"

#include <iostream>
#include <memory>

int main()
{
    // Construction de l'arborescence de formes géométriques
    // dessin représente la racine de l'arborescence
    auto dessin = std::make_shared<Groupe>();
       
    // Construction d'un groupe de forme géométriques
    auto groupe1 = std::make_shared<Groupe>();
    // Construction d'un cercle de rayon 10 et ajout du cercle au groupe1
    groupe1->ajouter(std::make_shared<Cercle>(10));
    // Construction d'un cercle de rayon 15 et ajout du cercle au groupe1
    groupe1->ajouter(std::make_shared<Cercle>(15));
    // Ajout du groupe1 au dessin
    dessin->ajouter(groupe1);
    // Construction d'un rectangle de longueur 80 et de largeur 20 et ajout du rectangle au dessin
    dessin->ajouter(std::make_shared<Rectangle>(40,20));
    
    // Affichage des formes géométriques
    dessin->Afficher();
    
    // Calcul et affichage de l'aire totale des formes géomètriques
    std::cout << "Aire totale = "
        << dessin->aire()
        << std::endl;

    return 0;
}
