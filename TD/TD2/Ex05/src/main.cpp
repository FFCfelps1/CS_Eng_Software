#include <iostream>
#include "liste.hpp"

int main() {
    Liste liste;

    // Insertion de plusieurs éléments
    liste.inserer(5);
    liste.inserer(2);
    liste.inserer(8);
    liste.inserer(1);
    liste.inserer(6);

    // Parcours de la liste
    Element* courant = liste.getDebut();

    while (courant != nullptr) {
        std::cout << courant->getInfo() << " -> ";
        courant = courant->getSuivant();
    }

    std::cout << "nullptr" << std::endl;

    return 0;
}

