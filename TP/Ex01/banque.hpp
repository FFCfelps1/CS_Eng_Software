#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <string>

#include "compte.hpp"
#include "compteCourant.hpp"
#include "compteEpargne.hpp"


class Banque {

private:
    std::vector<std::shared_ptr<Compte>> lesComptes;
    static int numCompte;

public:
    Banque();
    void retraitImpossible(int numeroCompte, double montant);
    void debiter(int numeroCompte, double montant);
    int creerCompte(double soldeInit);
    int creerCompteEpargne(double soldeInit);
    int creerCompteCourant(double soldeInit, double plafond);
    std::shared_ptr<Compte> rechercherCompte(int numero);
};
