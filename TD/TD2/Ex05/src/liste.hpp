#pragma once

#include <memory>
#include "element.hpp"

class Liste {
private:
    std::shared_ptr<Element> debut;

public:
    Liste();

    std::shared_ptr<Element> getDebut() const;
    void setDebut(std::shared_ptr<Element> debut);

    void inserer(int x);
};