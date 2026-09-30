#include <gtest/gtest.h>
#include <iostream>

#include "CapteurMeteo.hpp"


// Test de la mesure de la température
TEST(CapteurMeteoTest, MesurerTemperature) {
    int temperatureAncienne;
    int temperatureNouvelle;
    // Création d'un capteur météorologique.
    CapteurMeteo c;

    // Au départ, la température doit être égale à la valeur initiale.
    temperatureAncienne = c.getTemperature();
    std::cout << temperatureAncienne << " ";
    // Vérifie que la température initiale est correcte.
    EXPECT_EQ(CapteurMeteo::TEMPERATURE_INITIALE, temperatureAncienne);
    // On effectue plusieurs mesures afin de vérifier le comportement
    // du capteur au cours du temps.
    for (int i = 0; i < 10; i++) {
        // Effectue une nouvelle mesure.
        c.mesurer();
        // Récupère la nouvelle température.
        temperatureNouvelle = c.getTemperature();
        std::cout << temperatureNouvelle << " ";
        // Vérifie que la température reste comprise entre
        // les valeurs minimale et maximale autorisées.
        EXPECT_GE(temperatureNouvelle, CapteurMeteo::TEMPERATURE_MIN);
        EXPECT_LE(temperatureNouvelle, CapteurMeteo::TEMPERATURE_MAX);
        // Vérifie que la température n'a pas diminué de plus
        // que la variation maximale autorisée.
        EXPECT_GE(temperatureNouvelle, temperatureAncienne - CapteurMeteo::VARIATION_TEMPERATURE);
        // Vérifie que la température n'a pas augmenté de plus
        // que la variation maximale autorisée.
        EXPECT_LE(temperatureNouvelle, temperatureAncienne + CapteurMeteo::VARIATION_TEMPERATURE);

        // La nouvelle température devient l'ancienne température
        // pour la prochaine itération.
        temperatureAncienne = temperatureNouvelle;
    }
    std::cout << std::endl;
}


// Test de la mesure de l'humidité
TEST(CapteurMeteoTest, MesurerHumidite) {
    int humiditeAncienne;
    int humiditeNouvelle;
    // Création d'un capteur météorologique.
    CapteurMeteo c;

    // Récupération de l'humidité initiale.
    humiditeAncienne = c.getHumidite();
    std::cout << humiditeAncienne << " ";
    // Vérifie que l'humidité initiale est correcte.
    EXPECT_EQ(CapteurMeteo::HUMIDITE_INITIALE, humiditeAncienne);
    // Effectue plusieurs mesures successives.
    for (int i = 0; i < 10; i++) {
        // Effectue une nouvelle mesure.
        c.mesurer();
        // Récupère la nouvelle valeur d'humidité.
        humiditeNouvelle = c.getHumidite();
        std::cout << humiditeNouvelle << " ";
        // Vérifie que l'humidité reste dans les limites autorisées.
        EXPECT_GE(humiditeNouvelle, CapteurMeteo::HUMIDITE_MIN);
        EXPECT_LE(humiditeNouvelle, CapteurMeteo::HUMIDITE_MAX);
        // Vérifie que l'humidité ne diminue pas de plus
        // que la variation maximale autorisée.
        EXPECT_GE(humiditeNouvelle, humiditeAncienne - CapteurMeteo::VARIATION_HUMIDITE);
         // Vérifie que l'humidité n'augmente pas de plus
        // que la variation maximale autorisée.
        EXPECT_LE(humiditeNouvelle, humiditeAncienne + CapteurMeteo::VARIATION_HUMIDITE);

        // Mémorise la nouvelle valeur pour la prochaine mesure.
        humiditeAncienne = humiditeNouvelle;
    }
    std::cout << std::endl;
}


// Test de la mesure de la pression
TEST(CapteurMeteoTest, MesurerPression) {
    int pressionAncienne;
    int pressionNouvelle;
    // Création d'un capteur météorologique.
    CapteurMeteo c;

    // Récupération de la pression initiale.
    pressionAncienne = c.getPression();
    std::cout << pressionAncienne << " ";
    // Vérifie que la pression initiale est correcte.
    EXPECT_EQ(CapteurMeteo::PRESSION_INITIALE, pressionAncienne);
    // Effectue plusieurs mesures successives.
    for (int i = 0; i < 10; i++) {
        // Effectue une nouvelle mesure.
        c.mesurer();
        // Récupère la nouvelle valeur de pression.
        pressionNouvelle = c.getPression();
        std::cout << pressionNouvelle << " ";
        // Vérifie que la pression reste dans les limites autorisées.
        EXPECT_GE(pressionNouvelle, CapteurMeteo::PRESSION_MIN);
        EXPECT_LE(pressionNouvelle, CapteurMeteo::PRESSION_MAX);
        // Vérifie que la pression ne diminue pas de plus
        // que la variation maximale autorisée.
        EXPECT_GE(pressionNouvelle, pressionAncienne - CapteurMeteo::VARIATION_PRESSION);
        // Vérifie que la pression n'augmente pas de plus
        // que la variation maximale autorisée.
        EXPECT_LE(pressionNouvelle, pressionAncienne + CapteurMeteo::VARIATION_PRESSION);

        // Mémorise la nouvelle valeur pour la prochaine mesure.
        pressionAncienne = pressionNouvelle;
    }
    std::cout << std::endl;
}

