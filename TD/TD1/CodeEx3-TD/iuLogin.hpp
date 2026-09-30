/**
 * @file iuLogin.hpp
 * @author Michel Ianotto
 * 
 * @brief Déclaration de la classe IULogin
*/
#pragma once

#include <string>
#include <memory>

class GestionnairePersonne;

class IULogin {
private:
    std::shared_ptr<GestionnairePersonne> gestionnaire;
    std::string nom;
    std::string motDePasse;

public:
    IULogin();
    void setGestionnaire(
        std::shared_ptr<GestionnairePersonne>);
    void demanderNom();
    void demanderMotDePasse();
    void autoriserConnexion();
    void interdireConnexion();
    void identification();
};
