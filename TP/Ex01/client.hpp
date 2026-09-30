#pragma once

#include "banque.hpp"

class Client {

private:
    std::string nom;
    int monNumero;
    std::shared_ptr<Banque> maBanque;

public:

    Client(const std::string & unNom);
    void retrait(double montant);
    //void ouvrirCompte(std::shared_ptr<Banque>, double);
    void ouvrirCompteEpargne(std::shared_ptr<Banque>, double);
    void ouvrirCompteCourant(std::shared_ptr<Banque>, double, double = 0);

};