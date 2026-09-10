#pragma once

#include "moteurRendu.hpp"

class Forme {
public:

    virtual void dessiner(MoteurRendu& moteur) = 0;

    virtual ~Forme()=default;
};
