#ifndef SUJET_HPP
#define SUJET_HPP

#include <vector>
#include <algorithm>
#include "Observateur.hpp"

class Sujet {
protected:
    // Lista de observadores inscritos
    std::vector<Observateur*> lesObservateurs;

public:
    Sujet() = default;
    virtual ~Sujet() = default;

    /**
     * Inscreve um observador.
     */
    void attacher(Observateur* o) {
        if (o != nullptr) {
            lesObservateurs.push_back(o);
        }
    }

    /**
     * Remove a inscrição de um observador.
     */
    void detacher(Observateur* o) {
        lesObservateurs.erase(
            std::remove(lesObservateurs.begin(), lesObservateurs.end(), o),
            lesObservateurs.end()
        );
    }

    /**
     * Notifica todos os observadores inscritos invocando o método actualiser.
     */
    void prevenir() {
        for (Observateur* o : lesObservateurs) {
            if (o != nullptr) {
                o->actualiser(this);
            }
        }
    }
};

#endif // SUJET_HPP