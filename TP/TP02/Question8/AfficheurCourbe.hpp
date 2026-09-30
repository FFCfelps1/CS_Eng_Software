#pragma once

#include "Observateur.hpp"
#include "Sujet.hpp"

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class AfficheurCourbe : public Observateur
{
private:
    //std::string titre;
    sf::String titre_;
    sf::String titreAxeX_;
    sf::String titreAxeY_;
    sf::String nomSerie_;

    std::vector<sf::Vector2f> donnees;

    sf::RenderWindow window;
    sf::Font font;

    const float origineX = 80.f;
    const float origineY = 500.f;

    const float largeur = 650.f;
    const float hauteur = 400.f;

    void dessinerTexte(
        const sf::String& texte,
        float x,
        float y,
        unsigned int taille = 16
    );

    void dessinerAxes();

    void dessinerGraduations(
        float maxX,
        float maxY
    );

    void dessinerCourbe(
        float maxX,
        float maxY
    );

    void dessinerLegende();

    sf::String convertirUTF8(const std::string& texte);

public:

    AfficheurCourbe(
        const std::string& titre,
        const std::string& titreAxeX,
        const std::string& titreAxeY,
        const std::string& nomSerie
    );

    void ajouterPoint(int x, int y);

    // Redessine la fenêtre une fois
    void actualiser(Sujet *s);

    // Boucle d'affichage permanente
    void afficher();

    // Permet de savoir si la fenêtre est encore ouverte
    bool estOuverte() const;
};

