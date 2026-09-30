#include "AfficheurCourbe.hpp"
#include "../Question1/Question1/CapteurMeteo.hpp"

#include <chrono>
#include <thread>

int main()
{
    CapteurMeteo capteur;
    AfficheurCourbe afficheur(
        "Evolution des températures",
        "instant de mesure",
        "température",
        "températures"
    );

    for (int instant = 0; instant < 5 && afficheur.estOuverte(); ++instant)
    {
        capteur.mesurer();
        const int temperatureInterieure = capteur.mesurerInside();

        afficheur.ajouterPoint(instant, temperatureInterieure);
        afficheur.actualiser();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    afficheur.afficher();
    return 0;
}
