#pragma once

#include <fstream>

class Cercle;
class Rectangle;
class Groupe;

class ExportSVGVisitor {
private:
    std::ofstream fichier;

public:
    ExportSVGVisitor(const std::string& nom);
    ~ExportSVGVisitor();
    void exporter(Cercle&);
    void exporter(Rectangle&);
    void exporter(Groupe&);
};

