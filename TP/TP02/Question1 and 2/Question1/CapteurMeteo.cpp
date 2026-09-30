#include "CapteurMeteo.hpp"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <thread>

CapteurMeteo::CapteurMeteo()
    : temperature(TEMPERATURE_INITIALE),
      humidite(HUMIDITE_INITIALE),
      pression(PRESSION_INITIALE) {}

int CapteurMeteo::getTemperature() const {
    return temperature;
}

int CapteurMeteo::getHumidite() const {
    return humidite;
}

int CapteurMeteo::getPression() const {
    return pression;
}

void CapteurMeteo::mesurer() {
    static std::random_device source;
    static std::mt19937 generateur(source());

    std::uniform_int_distribution<int> variationTemperature(
        -VARIATION_TEMPERATURE, VARIATION_TEMPERATURE);
    std::uniform_int_distribution<int> variationHumidite(
        -VARIATION_HUMIDITE, VARIATION_HUMIDITE);
    std::uniform_int_distribution<int> variationPression(
        -VARIATION_PRESSION, VARIATION_PRESSION);

    temperature = std::clamp(temperature + variationTemperature(generateur),
                             TEMPERATURE_MIN, TEMPERATURE_MAX);
    humidite = std::clamp(humidite + variationHumidite(generateur),
                          HUMIDITE_MIN, HUMIDITE_MAX);
    pression = std::clamp(pression + variationPression(generateur),
                          PRESSION_MIN, PRESSION_MAX);
}

int CapteurMeteo::mesurerInside() const {
    static std::random_device source;
    static std::mt19937 generateur(source());


    std::uniform_int_distribution<int> variationTemperatureInside(
        -VARIATION_TEMPERATURE_IN_OUT, VARIATION_TEMPERATURE_IN_OUT);

    int temperatureInside = std::clamp(temperature + variationTemperatureInside(generateur), TEMPERATURE_MIN, TEMPERATURE_MAX);

    return temperatureInside;
}

 #ifndef CAPTEUR_METEO_TEST
int main() {
    CapteurMeteo capteur;

    while (true) {
        capteur.mesurer();
        std::cout << "temperatures:\t| indoor: " << capteur.getTemperature()
                  << " C\t| outdoor: " << capteur.mesurerInside() << " C"
                  << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
#endif