#pragma once

class CapteurMeteo {
public:
    int temperature;  // en degrés Celsius
    int temperature_inside;
    int humidite;     // en %
    int pression;     // en hPa

    static constexpr int TEMPERATURE_MIN = -40;
    static constexpr int TEMPERATURE_MAX = 50;
    static constexpr int HUMIDITE_MIN = 0;
    static constexpr int HUMIDITE_MAX = 100;
    static constexpr int PRESSION_MIN = 900;
    static constexpr int PRESSION_MAX = 1080;

    static constexpr int VARIATION_TEMPERATURE = 5;
    static constexpr int VARIATION_HUMIDITE = 10;
    static constexpr int VARIATION_PRESSION = 5;

    static constexpr int TEMPERATURE_INITIALE = 10;
    static constexpr int HUMIDITE_INITIALE = 50;
    static constexpr int PRESSION_INITIALE = 1013;

    static constexpr int VARIATION_TEMPERATURE_IN_OUT = 3;

public:
    CapteurMeteo();

    int getTemperature() const;
    int getHumidite() const;
    int getPression() const;
    void mesurer();
    int mesurerInside() const;

};

