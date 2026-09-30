#include "journalisation.hpp"

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

Journalisation& Journalisation::getInstance() {
    static Journalisation instance;
    return instance;
}

void Journalisation::afficherLog(const std::string& log){
    // Récupération de la date et de l'heure actuelles
    auto maintenant = std::chrono::system_clock::now();
    std::time_t temps = std::chrono::system_clock::to_time_t(maintenant);

    std::tm* date = std::localtime(&temps);

    std::cout << "["
              << date->tm_mday << "/"
              << date->tm_mon + 1 << "/"
              << date->tm_year + 1900
              << " à "
              << date->tm_hour << "h"
              << date->tm_min
              << "] "
              << log
              << std::endl;
}