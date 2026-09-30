#ifndef OBSERVATEUR_HPP
#define OBSERVATEUR_HPP

// Declaração antecipada (Forward declaration) para evitar inclusão circular
class Sujet;

class Observateur {
public:
    virtual ~Observateur() = default;

    /**
     * Chamado automaticamente quando um Sujet observado altera seu estado.
     * @param s Ponteiro para o Sujet que disparou a atualização.
     */
    virtual void actualiser(Sujet* s) = 0;
};

#endif // OBSERVATEUR_HPP