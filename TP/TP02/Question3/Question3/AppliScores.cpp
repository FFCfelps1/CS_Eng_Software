#include "AfficheurCourbe.hpp"

int main()
{
    AfficheurCourbe ac(
        "Evolution des scores",
        "date",
        "score",
        "scores"
    );

    ac.ajouterPoint(1, 2);
    ac.ajouterPoint(2, 2);
    ac.ajouterPoint(3, 4);
    ac.ajouterPoint(5, 5);
    ac.ajouterPoint(8, 6);

    ac.afficher();

    return 0;
}