/**
 * @file main.cpp
 * @author Michel Ianotto
 *
 * @brief Programme principal.
 *
 * Ce programme met en œuvre un exemple simple d'authentification.
 * Il crée les différents objets de l'application, établit les
 * associations entre eux, initialise une liste de personnes
 * autorisées puis lance la procédure d'identification.
 *
 *    g++ -std=c++20 -o main main.cpp iuLogin.cpp gestionPersonne.cpp Personne.cpp
*/

#include <IULogin.hpp>
#include <GestionnairePersonne.hpp>
#include <Personne.hpp>

int main()
{
    // Création de l'interface utilisateur chargée de dialoguer
    // avec l'utilisateur.
    std::shared_ptr<IULogin> unIULogin = std::make_shared<IULogin>();;

    // Création du gestionnaire qui mémorise les personnes
    // autorisées à se connecter.
    std::shared_ptr<GestionnairePersonne> unGestionnaire = std::make_shared<GestionnairePersonne>();

    // -----------------------------------------------------------------
    // Phase d'initialisation
    // -----------------------------------------------------------------

    // Création de quelques utilisateurs.
    // Dans une application réelle, ces informations proviendraient
    // d'une base de données ou d'un fichier.
    std::shared_ptr<Personne> p1 = std::make_shared<Personne>("nom1", "motdepasse1");
    std::shared_ptr<Personne> p2 = std::make_shared<Personne>("nom2", "motdepasse2");
    std::shared_ptr<Personne> p3 = std::make_shared<Personne>("nom3", "motdepasse3");

    // Établissement de l'association entre l'interface utilisateur
    // et le gestionnaire de personnes.
    unIULogin->setGestionnaire(unGestionnaire);

    // Ajout des personnes dans le gestionnaire.
    unGestionnaire->ajoute(p1);
    unGestionnaire->ajoute(p2);
    unGestionnaire->ajoute(p3);

    // -----------------------------------------------------------------
    // Exécution de l'application
    // -----------------------------------------------------------------

    // Lancement de la procédure d'identification.
    // L'utilisateur est invité à saisir son nom et son mot de passe.
    // Le gestionnaire vérifie ensuite si ces informations
    // correspondent à une personne enregistrée.
    unIULogin->identification();

    return 0;
}