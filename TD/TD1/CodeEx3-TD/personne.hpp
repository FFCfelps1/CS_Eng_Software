/**
 * @file personne.hpp
 * @author Michel Ianotto
 * 
 * @brief Déclaration de la classe Personne
*/
#pragma once

#include <string>

class Personne
{
private:
    std::string nom;
    std::string motDePasse;

public:
    Personne(const std::string& nom,
             const std::string& motDePasse);

    const std::string& getNom() const;
    const std::string& getMotDePasse() const;
};
