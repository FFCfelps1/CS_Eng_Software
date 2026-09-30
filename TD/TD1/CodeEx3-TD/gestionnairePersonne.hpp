/**
 * @file gestionnairePersonne.hpp
 * @author Michel Ianotto
 * 
 * @brief Déclaration de la classe GestionnairePersonne
*/
#pragma once

#include <vector>
#include <memory>
#include <string>

#include "Personne.hpp"

class GestionnairePersonne {
private:
    std::vector<std::shared_ptr<Personne>> lesPersonnes;

public:
    GestionnairePersonne() = default;
    void ajoute(std::shared_ptr<Personne> p);
    bool verifierMotDePasse(
        const std::string& nom,
        const std::string& motDePasse) const;
};
