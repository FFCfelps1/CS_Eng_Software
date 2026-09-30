/*
  fichier main.cpp
*/

#include <memory>

#include "client.hpp"
#include "banque.hpp"

// Programme principal
int main() {
    std::shared_ptr<Banque> banqueNationale = std::make_shared<Banque>();
    std::shared_ptr<Client> c1 = std::make_shared<Client>("C1");
    std::shared_ptr<Client> c2 = std::make_shared<Client>("C2");

    // Ouverture d'un compte épargne
    c1->ouvrirCompteEpargne(banqueNationale, 1000);
    // Retrait sur le compte Epargne
    c1->retrait(200);

    // Ouverture d'un compte courant
    c2->ouvrirCompteCourant(banqueNationale, 500);
    // Retrait sur le compte courant
    c2->retrait(700);

    return 0;
}