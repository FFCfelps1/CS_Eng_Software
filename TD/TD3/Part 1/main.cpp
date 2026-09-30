#include "compteBancaire.hpp"

#include <memory>

int main()
{
    // Création des CompteBancaires cb1, cb2, cb3.
    std::shared_ptr<CompteBancaire> cb1 = std::make_shared<CompteBancaire>(123456789);
    std::shared_ptr<CompteBancaire> cb2 = std::make_shared<CompteBancaire>(987654321);
    std::shared_ptr<CompteBancaire> cb3 = std::make_shared<CompteBancaire>(456789012);

    // Utilisation du CompteBancaire cb1.
    // A COMPLETER
    cb1->deposerArgent(100);
    cb1->retirerArgent(80);

    // Utilisation du CompteBancaire cb2.
    // A COMPLETER
    cb2->retirerArgent(80);

    // Utilisation du CompteBancaire cb3.
    // A COMPLETER
    cb3->deposerArgent(100);


    return 0;
}