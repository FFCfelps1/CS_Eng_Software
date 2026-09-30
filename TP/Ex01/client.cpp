#include <iostream>
#include <memory>
#include <string>

#include "client.hpp"
#include "banque.hpp"

Client::Client(const std::string& unNom) : nom(unNom), monNumero(0) {

}

void Client::retrait(double montant) {
    maBanque->debiter(monNumero, montant);
}

// void Client::ouvrirCompte(std::shared_ptr<Banque> uneBanque, double soldeInit) {
//     maBanque = uneBanque;
//     monNumero = maBanque->creerCompte(soldeInit);
//     std::cout << "Client "
//               << nom
//               << " a ouvert le compte n°"
//               << monNumero
//               << " avec un solde initial de "
//               << soldeInit << "€"
//               << std::endl;
// }

void Client::ouvrirCompteEpargne(std::shared_ptr<Banque> uneBanque, double soldeInit) {
    maBanque = uneBanque;
    monNumero = maBanque->creerCompteEpargne(soldeInit);
    std::cout << "Client "
              << nom
              << " a ouvert le compte le Epargne n°"
              << monNumero
              << " avec un solde initial de "
              << soldeInit << "€"
              << std::endl;
}

void Client::ouvrirCompteCourant(std::shared_ptr<Banque> uneBanque, double soldeInit, double plafond) {
    maBanque = uneBanque;
    monNumero = maBanque->creerCompteCourant(soldeInit , plafond);
    std::cout << "Client "
              << nom
              << " a ouvert le compte Courant n°"
              << monNumero
              << " avec un solde initial de "
              << soldeInit << "€"
              << std::endl;
}


