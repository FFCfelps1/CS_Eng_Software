/**
 * @file iuLogin.cpp
 * @author Michel Ianotto
 * 
 * @brief Implémentation des méthodes de la classe IULogin
*/
#include <IULogin.hpp>
#include <GestionnairePersonne.hpp>

#include <iostream>

IULogin::IULogin() {
}

void IULogin::setGestionnaire(
        std::shared_ptr<GestionnairePersonne> g) {
    gestionnaire = g;
}

void IULogin::demanderNom(){
    std::cout << "Entrer le nom : ";
    std::cin >> nom;
}

void IULogin::demanderMotDePasse()
{
    std::cout << "Entrer le mot de passe : ";
      std::cin >> motDePasse;
}

void IULogin::autoriserConnexion()
{
    std::cout << "Connexion autorisée\n";
}

void IULogin::interdireConnexion()
{
    std::cout << "Connexion interdite\n";
}

void IULogin::identification()
{
   
   
}
