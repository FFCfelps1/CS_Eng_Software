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


class Groupe : public Forme {
private:
    std::vector<std::shared_ptr<Forme>> lesFormes;

public:
    // Constructeur 
    Groupe() : lesFormes() {};

    void ajouter(std::shared_ptr<Forme> f1) {
        lesFormes.push_back(f1);
    }

    // Méthode permettant d'afficher les éléments d'un noeud
    void Afficher() override {
        for(auto f : lesFormes) {
            f->Afficher();
        };
    }

    double aire() override {
        double sum = 0;
        for (auto count : lesFormes){
            sum += lesFormes->aire();
        }

        return sum;
    }
};
