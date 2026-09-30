#include "liste.hpp"

Liste::Liste()
    : debut(nullptr) {
}

std::shared_ptr<Element> Liste::getDebut() const {
    return debut;
}

void Liste::setDebut(std::shared_ptr<Element> debut) {
    this->debut = debut;
}

void Liste::inserer(int x) {
    // Variables
    std::shared_ptr<Element> courant;
    std::shared_ptr<Element> precedent;
    std::shared_ptr<Element> nouveau;
    bool trouve;

    // Initialisation des variables
    courant = debut;
    precedent = nullptr;
    trouve = false;

    // Recherche de la position de l'élément à insérer
    while (courant != nullptr && trouve == false) {
        if (courant->getInfo() >= x) {
            trouve = true;
        }
        else {
            precedent = courant;
            courant = courant->getSuivant();
        }
    }

    // Création du nouvel élément
    nouveau = std::make_shared<Element>(x);

    nouveau->setInfo(x);
    nouveau->setSuivant(courant);

    // Insertion du nouvel élément
    if (precedent == nullptr) {
        debut = nouveau;
    }
    else {
        precedent->setSuivant(nouveau);
    }
}