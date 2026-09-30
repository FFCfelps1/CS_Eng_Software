#pragma once
#include "journalisation.hpp"

class CompteBancaire {
private:
    int numero;                    // Numéro du compte
    double solde;                  // Argent disponible sur le compte
    Journalisation& journalisation;

public:
    // Constructeur
    CompteBancaire(int numero);

    // Déposer de l'argent
    void deposerArgent(double depot);

    // Retirer de l'argent
    void retirerArgent(double retrait);
};
    
