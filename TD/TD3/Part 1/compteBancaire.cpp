#include <iostream>

#include "compteBancaire.hpp"

#include <string>

CompteBancaire::CompteBancaire(int numero)
    : numero(numero),
            solde(0.0),
            journalisation(Journalisation::getInstance()) {}

void CompteBancaire::deposerArgent(double depot) {
    if (depot > 0.0) {
        solde += depot;

        journalisation.afficherLog(
            "Dépôt de " + std::to_string(depot) +
            "€ sur le compte " + std::to_string(numero) + "."
        );
    }
}

void CompteBancaire::retirerArgent(double retrait) {
    if (retrait > 0.0) {
        if (solde >= retrait) {
            solde -= retrait;

            journalisation.afficherLog(
                "Retrait de " + std::to_string(retrait) +
                "€ sur le compte " + std::to_string(numero) + "."
            );
        }
        else {
            journalisation.afficherLog(
                "La banque n'autorise pas de découvert sur le compte " +
                std::to_string(numero) + "."
            );
        }
    }
}