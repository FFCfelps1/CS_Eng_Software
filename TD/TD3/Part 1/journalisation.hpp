#pragma once

#include <string>

class Journalisation {
private:
    Journalisation() = default;

public:
    static Journalisation& getInstance();

    void afficherLog(const std::string& log);
};
