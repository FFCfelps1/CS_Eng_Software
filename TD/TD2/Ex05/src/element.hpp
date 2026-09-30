#pragma once

#include <memory>

class Element {
private:
    int info;
    std::shared_ptr<Element> suivant;

public:
   
    Element(int info)
        : info(info), suivant(nullptr) {
    }

    int getInfo() const {
        return info;
    }

    void setInfo(int info) {
        this->info = info;
    }

    std::shared_ptr<Element> getSuivant() const {
        return suivant;
    }

    void setSuivant(std::shared_ptr<Element> suivant) {
        this->suivant = suivant;
    }
};