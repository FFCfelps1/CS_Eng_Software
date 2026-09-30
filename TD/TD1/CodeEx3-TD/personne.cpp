/**
 * @file personne.cpp
 * @author Michel Ianotto
 * 
 * @brief Implémentation des méthodes de la classe Personne
*/
#include <Personne.hpp>

Personne::Personne(const std::string& nom,
                   const std::string& motDePasse)
    : nom(nom),
      motDePasse(motDePasse) {
}

const std::string& Personne::getNom() const {
    return nom;
}

const std::string& Personne::getMotDePasse() const {
    return motDePasse;
}

