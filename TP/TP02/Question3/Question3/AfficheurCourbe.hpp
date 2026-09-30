#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class AfficheurCourbe {
private:

    // Informations du graphique
    std::string titre;
    std::string titreAxeX;
    std::string titreAxeY;
    std::string nomSerie;

    // Données
    std::vector<sf::Vector2f> donnees;

    // Fenêtre et police
    sf::RenderWindow window;
    sf::Font font;

    // Dimensions du graphique
    const float origineX = 80.f;
    const float origineY = 500.f;

    const float largeur = 650.f;
    const float hauteur = 400.f;

    // Fonctions privées
    void dessinerTexte(
        const std::string& texte,
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

public:

    AfficheurCourbe(
        const std::string& titre,
        const std::string& titreAxeX,
        const std::string& titreAxeY,
        const std::string& nomSerie
    );

    void ajouterPoint(int x, int y);

    void afficher();
};

