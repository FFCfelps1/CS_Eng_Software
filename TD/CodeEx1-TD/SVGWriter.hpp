
#pragma once

#include <iostream>
#include <string>


class SVGWriter {
public:

    void addCercle(double cx, double cy, double r)  {
        std::cout 
          << "<circle cx=\"" 
          << cx
          << "\" cy=\""
          << cy
          << "\" r=\""
          << r
          << "\"/>"
          << std::endl;
    }

    void addRectangle(double x, double y, double longueur, double largeur) {
        std::cout 
          << "<rect x=\""
          << x
          << "\" y=\""
          << y
          << "\" width=\""
          << longueur
          << "\" height=\""
          << largeur
          << "\"/>"
          << std::endl;
    }

    void addLigne(double x1, double y1, double x2, double y2) {
        std::cout 
          << "<line x1=\""
          << x1
          << "\" y1=\""
          << y1
          << "\" x2=\""
          << x2
          << "\" y2=\""
          << y2
          << "\" stroke=\"black\""
          << "stroke-width=\"2\""
          << "/>"
          << std::endl;
    }
};


