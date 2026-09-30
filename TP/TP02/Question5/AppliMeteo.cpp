#include "AfficheurPrevisions.hpp"
#include "../Question1/Question1/CapteurMeteo.hpp"

#include <chrono>
#include <thread>

int main()
{
    CapteurMeteo capteur;
    AfficheurPrevisions afficheur;

    while (true)
    {
        capteur.mesurer();

        afficheur.mettreAJour(
            capteur.getTemperature(),
            capteur.getHumidite(),
            capteur.getPression()
        );

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
