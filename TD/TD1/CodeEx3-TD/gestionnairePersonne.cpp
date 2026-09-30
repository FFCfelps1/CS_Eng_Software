/**
 * @file gestionnairePersonne.cpp
 * @author Michel Ianotto
 * 
 * @brief Implémentation des méthodes de la classe GestionnairePersonne
*/
#include <GestionnairePersonne.hpp>

void GestionnairePersonne::ajoute(
        std::shared_ptr<Personne> p) {
    lesPersonnes.push_back(p);
}

bool GestionnairePersonne::verifierMotDePasse(
        const std::string& nom,
        const std::string& motDePasse) const {

    return false;
}
