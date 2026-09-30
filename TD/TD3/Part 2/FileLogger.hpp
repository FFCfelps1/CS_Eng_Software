#pragma once

#include <iostream>
#include <fstream>

#include "Logger.hpp"

class FileLogger : public Logger {
private:
    std::string nomFichier_;

public:
    FileLogger(const std::string nomFichier) : nomFichier_(nomFichier) {
    }

    void log(const std::string& msg) override {
        std::ofstream fichier(nomFichier_, std::ios::app);

        if (fichier.is_open()) {
            fichier << msg << std::endl;
            fichier.close();
        }
        else {
            std::cerr << "Erreur : impossible d'ouvrir le fichier "
                    << "FichierLog.txt" << std::endl;
        }
    }
};

