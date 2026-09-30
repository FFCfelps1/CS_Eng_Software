#pragma once

class Compte {

protected:
    int numero;
    double solde;

public:

    Compte(int unNumero, double soldeInit) : numero(unNumero), solde(soldeInit) {};
    virtual ~Compte() {};
    virtual bool debiterCompte(double montant) {
   	    solde = solde - montant;
        return true;
    };
    double donneSolde() const { return solde; };
    int donneNumero() const { return numero; };
};
