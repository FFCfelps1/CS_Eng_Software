/**
 * @file element.hpp
 * @author Michel Ianotto
 *
 * @brief Classe de base abstraite
 *
*/
class Element {
public:
    virtual void afficheElement() = 0;
    virtual ~Element() = default;
};