#include "AfficheurPrevisions.hpp"

#include <iostream>

void AfficheurPrevisions::mettreAJour(
    int temperature,
    int humidite,
    int pression
)
{
    std::cout << "Temperature: " << temperature << " C | "
              << "Humidite: " << humidite << " % | "
              << "Pression: " << pression << " hPa | Prevision: ";

    if (temperature <= 1 && humidite >= 70 && pression >= 1020)
    {
        std::cout << "neige";
    }
    else if (temperature > 1 && humidite >= 70 && pression >= 1020)
    {
        std::cout << "averses";
    }
    else if (temperature >= 40 && humidite <= 70 && pression <= 1000)
    {
        std::cout << "canicule";
    }
    else
    {
        std::cout << "beau temps";
    }

    std::cout << std::endl;
}
