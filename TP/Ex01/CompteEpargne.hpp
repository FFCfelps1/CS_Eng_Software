#pragma once

#include "compte.hpp"

class CompteEpargne : public Compte {

    public:

        CompteEpargne(int unNumero, double soldeInit) : Compte(unNumero, soldeInit) {};
        virtual ~CompteEpargne() {};
        virtual bool debiterCompte(double montant) {
            if (0 < solde - montant){
                solde = solde - montant; 
                return true;
            };
            return false;
        };
        // double donneSolde() const { return solde; };
        // int donneNumero() const { return numero; };
};
