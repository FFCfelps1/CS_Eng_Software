#pragma once

#include "compte.hpp"

class CompteCourant : public Compte {
    protected:

    double plafond;


    public:

        CompteCourant(int unNumero, double soldeInit, double plafond) : Compte(unNumero, soldeInit) , plafond(plafond) {};
        virtual ~CompteCourant() {};
        virtual bool debiterCompte(double montant) {
            if (plafond < solde - montant){
                solde = solde - montant; 
                return true;
            };
            return false;
        };
        double donneSolde() const { return solde; };
        int donneNumero() const { return numero; };
};
