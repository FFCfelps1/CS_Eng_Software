#include <iostream>
#include <algorithm>

#include "banque.hpp"

int Banque::numCompte = 0;

Banque::Banque() {
    
}

void Banque::retraitImpossible(int numeroCompte, double montant) {
    std::cout << "Solde insuffisant pour le retrait de "
              << montant
              << "€ sur le compte n° "
              << numeroCompte
              << std::endl;
}

std::shared_ptr<Compte> Banque::rechercherCompte(int numero) {
       for (const auto& compte : lesComptes) {
       if (compte->donneNumero() == numero) {
          return compte;
       }
   }
   return nullptr;
}

void Banque::debiter(int numeroCompte, double montant) {
    std::shared_ptr<Compte> compteClient;
    double solde;

    compteClient = rechercherCompte(numeroCompte);
    if (!compteClient) {
        std::cout << "Compte n°" << numeroCompte << " introuvable" << std::endl;
        return;
    }
    solde = compteClient->donneSolde();

    if (solde > montant) {
        compteClient->debiterCompte(montant);
        std::cout << "Retrait de " 
                   <<  montant 
                   << "€ effectué sur le compte n°" 
                   << numeroCompte
                   << std::endl;
    }
    else
        retraitImpossible(numeroCompte, montant);
}

int Banque::creerCompte(double soldeInit) {
    lesComptes.push_back(
            std::make_shared<Compte>(
                    numCompte,
                    soldeInit));

    return numCompte++;
}

int Banque::creerCompteEpargne(double soldeInit) {
    lesComptes.push_back(
            std::make_shared<CompteEpargne>(
                    numCompte,
                    soldeInit));

    return numCompte++;
}

int Banque::creerCompteCourant(double soldeInit, double plafond) {
    lesComptes.push_back(
            std::make_shared<CompteCourant>(
                    numCompte,
                    soldeInit,
                    plafond));

    return numCompte++;
}