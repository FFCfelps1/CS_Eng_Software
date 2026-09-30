#include "AfficheurCourbe.hpp"

#include <algorithm>
#include <iostream>
#include <cmath>
#include <optional>


// ------------------------------------------------------------
// Constructeur
// ------------------------------------------------------------
AfficheurCourbe::AfficheurCourbe(
    const std::string& titre,
    const std::string& titreAxeX,
    const std::string& titreAxeY,
    const std::string& nomSerie
)
    : titre_(convertirUTF8(titre)),
      titreAxeX_(convertirUTF8(titreAxeX)),
      titreAxeY_(convertirUTF8(titreAxeY)),
      nomSerie_(convertirUTF8(nomSerie)),
      window(
          sf::VideoMode({800, 600}),
          convertirUTF8(titre)
      )
{
    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf") &&
        !font.openFromFile(
            "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"))
    {
        std::cerr
            << "Erreur : impossible de charger la police."
            << std::endl;
    }
}


// ------------------------------------------------------------
// Ajouter un point
// ------------------------------------------------------------
void AfficheurCourbe::ajouterPoint(int x, int y)
{
    donnees.emplace_back(
        static_cast<float>(x),
        static_cast<float>(y)
    );
}


// ------------------------------------------------------------
// Dessiner du texte
// ------------------------------------------------------------
void AfficheurCourbe::dessinerTexte(
    const sf::String& texte,
    float x,
    float y,
    unsigned int taille
)
{
    sf::Text text(font, texte, taille);
    text.setFillColor(sf::Color::Black);
    text.setPosition({x, y});

    window.draw(text);
}


// ------------------------------------------------------------
// Dessiner les axes
// ------------------------------------------------------------
void AfficheurCourbe::dessinerAxes()
{
    // Axe X
    sf::VertexArray axeX(sf::PrimitiveType::Lines, 2);

    axeX[0].position =
        sf::Vector2f(origineX, origineY);

    axeX[1].position =
        sf::Vector2f(
            origineX + largeur,
            origineY
        );

    axeX[0].color = sf::Color::Black;
    axeX[1].color = sf::Color::Black;

    window.draw(axeX);


    // Axe Y
    sf::VertexArray axeY(sf::PrimitiveType::Lines, 2);

    axeY[0].position =
        sf::Vector2f(origineX, origineY);

    axeY[1].position =
        sf::Vector2f(
            origineX,
            origineY - hauteur
        );

    axeY[0].color = sf::Color::Black;
    axeY[1].color = sf::Color::Black;

    window.draw(axeY);


    // Nom de l'axe X
    dessinerTexte(
        titreAxeX_,
        origineX + largeur - 30.f,
        origineY + 25.f,
        16
    );


    // Nom de l'axe Y
    dessinerTexte(
        titreAxeY_,
        20.f,
        origineY - hauteur - 30.f,
        16
    );
}


// ------------------------------------------------------------
// Dessiner les graduations
// ------------------------------------------------------------
void AfficheurCourbe::dessinerGraduations(
    float maxX,
    float maxY
)
{
    int graduationMaxX =
        static_cast<int>(std::ceil(maxX));

    if (graduationMaxX < 1)
        graduationMaxX = 1;


    // Axe X
    for (int i = 0;
         i <= graduationMaxX;
         ++i)
    {
        float valeur =
            static_cast<float>(i);

        float x =
            origineX
            + (valeur / graduationMaxX)
              * largeur;


        sf::VertexArray graduation(
            sf::PrimitiveType::Lines,
            2
        );

        graduation[0].position =
            sf::Vector2f(x, origineY);

        graduation[1].position =
            sf::Vector2f(x, origineY + 5.f);

        graduation[0].color =
            sf::Color::Black;

        graduation[1].color =
            sf::Color::Black;

        window.draw(graduation);


        dessinerTexte(
            std::to_string(i),
            x - 5.f,
            origineY + 8.f,
            14
        );
    }


    int graduationMaxY =
        static_cast<int>(std::ceil(maxY));

    if (graduationMaxY < 1)
        graduationMaxY = 1;


    // Axe Y
    for (int i = 0;
         i <= graduationMaxY;
         ++i)
    {
        float valeur =
            static_cast<float>(i);

        float y =
            origineY
            - (valeur / graduationMaxY)
              * hauteur;


        sf::VertexArray graduation(
            sf::PrimitiveType::Lines,
            2
        );

        graduation[0].position =
            sf::Vector2f(
                origineX - 5.f,
                y
            );

        graduation[1].position =
            sf::Vector2f(
                origineX,
                y
            );

        graduation[0].color =
            sf::Color::Black;

        graduation[1].color =
            sf::Color::Black;

        window.draw(graduation);


        dessinerTexte(
            std::to_string(i),
            origineX - 30.f,
            y - 8.f,
            14
        );
    }
}


// ------------------------------------------------------------
// Dessiner la courbe
// ------------------------------------------------------------
void AfficheurCourbe::dessinerCourbe(
    float maxX,
    float maxY
)
{
    if (donnees.empty())
        return;


    // Courbe
    if (donnees.size() >= 2)
    {
        sf::VertexArray courbe(
            sf::PrimitiveType::LineStrip,
            donnees.size()
        );


        for (std::size_t i = 0;
             i < donnees.size();
             ++i)
        {
            float x =
                origineX
                + (donnees[i].x / maxX)
                  * largeur;

            float y =
                origineY
                - (donnees[i].y / maxY)
                  * hauteur;


            courbe[i].position =
                sf::Vector2f(x, y);

            courbe[i].color =
                sf::Color::Blue;
        }


        window.draw(courbe);
    }


    // Points
    for (const auto& point : donnees)
    {
        float x =
            origineX
            + (point.x / maxX)
              * largeur;

        float y =
            origineY
            - (point.y / maxY)
              * hauteur;


        sf::CircleShape cercle(5.f);

        cercle.setFillColor(
            sf::Color::Red
        );

        cercle.setPosition({x - 5.f, y - 5.f});

        window.draw(cercle);
    }
}


// ------------------------------------------------------------
// Dessiner la légende
// ------------------------------------------------------------

void AfficheurCourbe::dessinerLegende()
{
    const float x = 600.f;
    const float y = 80.f;


    sf::VertexArray ligne(
        sf::PrimitiveType::Lines,
        2
    );

    ligne[0].position =
        sf::Vector2f(x, y + 8.f);

    ligne[1].position =
        sf::Vector2f(x + 30.f, y + 8.f);

    ligne[0].color =
        sf::Color::Blue;

    ligne[1].color =
        sf::Color::Blue;

    window.draw(ligne);


    dessinerTexte(
        nomSerie_,
        x + 40.f,
        y,
        14
    );
}


// ------------------------------------------------------------
// Actualiser
// ------------------------------------------------------------

void AfficheurCourbe::actualiser()
{
    if (!window.isOpen())
        return;


    // --------------------------------------------------------
    // Gestion des événements
    // --------------------------------------------------------

    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
    }


    // --------------------------------------------------------
    // Fond
    // --------------------------------------------------------

    window.clear(sf::Color::White);


    // --------------------------------------------------------
    // Calcul des valeurs maximales
    // --------------------------------------------------------

    float maxX = 1.f;
    float maxY = 1.f;

    for (const auto& point : donnees)
    {
        maxX =
            std::max(maxX, point.x);

        maxY =
            std::max(maxY, point.y);
    }


    // --------------------------------------------------------
    // Titre
    // --------------------------------------------------------

    dessinerTexte(
        titre_,
        300.f,
        20.f,
        22
    );


    // --------------------------------------------------------
    // Axes
    // --------------------------------------------------------
    dessinerAxes();


    // --------------------------------------------------------
    // Graduations
    // --------------------------------------------------------
    dessinerGraduations(
        maxX,
        maxY
    );


    // --------------------------------------------------------
    // Courbe
    // --------------------------------------------------------

    dessinerCourbe(
        maxX,
        maxY
    );


    // --------------------------------------------------------
    // Légende
    // --------------------------------------------------------

    dessinerLegende();


    // --------------------------------------------------------
    // Affichage
    // --------------------------------------------------------

    window.display();
}


// ------------------------------------------------------------
// Affichage permanent
// ------------------------------------------------------------

void AfficheurCourbe::afficher()
{
    while (window.isOpen())
    {
        actualiser();
    }
}


// ------------------------------------------------------------
// État de la fenêtre
// ------------------------------------------------------------
bool AfficheurCourbe::estOuverte() const
{
    return window.isOpen();
}

sf::String AfficheurCourbe::convertirUTF8(const std::string& texte)
{
    return sf::String::fromUtf8(
        texte.begin(),
        texte.end()
    );
}