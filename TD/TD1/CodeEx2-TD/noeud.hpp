/**
 * @file noeud.hpp
 * @author Michel Ianotto
 *
 * @brief Classe permettant de représenter un noeud
 *
*/
#include <iostream>
#include <vector>
#include <memory>


class Noeud : public Element {
private:
    std::vector<std::shared_ptr<Element>> lesElements;

public:
    // Constructeur 
    Noeud() : lesElements() {};

    // Ajoute les éléments e1 et e2 au vecteur d'éléments
    void setElement(std::shared_ptr<Element> e1,
                    std::shared_ptr<Element> e2) {
        lesElements.push_back(e1);
        lesElements.push_back(e2);
    }

    // Méthode permettant d'afficher les éléments d'un noeud
    void afficheElement() override {
        for(auto e : lesElements) {
            e->afficheElement();
        };
    }
};
