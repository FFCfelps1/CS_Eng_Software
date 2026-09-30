/**
 * @file main.cpp
 * @author Michel Ianotto
 *
 * @brief Programme principal
 *
 *
 *   g++ -std=c++20 -I. -o main main.cpp
*/
#include <iostream>
#include <vector>
#include <memory>
#include "element.hpp"
#include "noeud.hpp"
#include "feuille.hpp"

int main()
{
    // Nodes and leaf creation object
    std::shared_ptr<Noeud> n1 = std::make_shared<Noeud>();
    std::shared_ptr<Noeud> n2 = std::make_shared<Noeud>();
    std::shared_ptr<Feuille> f1 = std::make_shared<Feuille>(1);
    std::shared_ptr<Feuille> f2 = std::make_shared<Feuille>(2);
    std::shared_ptr<Feuille> f3 = std::make_shared<Feuille>(3);

    // Pointers conection -> doing the tree
    n1->setElement(n2, f3);
    n2->setElement(f1, f2);

    // Print the leafs
    f1->afficheElement();
    f2->afficheElement();
    f3->afficheElement();
}