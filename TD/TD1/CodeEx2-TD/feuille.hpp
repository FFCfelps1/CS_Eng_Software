/**
 * @file feuille.hpp
 * @author Michel Ianotto
 *
 * @brief Classe permettant de représenter une feuille
 *
*/
class Feuille : public Element {
private:
    int valeur;

public:
    // Constructeur
    Feuille(int uneValeur) : valeur(uneValeur) {}
    // Méthode permettant d'afficher l'élément d'une feuille
    void afficheElement() override {
        std::cout << valeur << " -> " << std::endl;
    }
};