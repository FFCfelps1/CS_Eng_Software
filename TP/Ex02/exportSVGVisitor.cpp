#include <exportSVGVisitor.hpp>

#include <cercle.hpp>
#include <rectangle.hpp>
#include <groupe.hpp>

ExportSVGVisitor::ExportSVGVisitor(const std::string& nom) {
    fichier.open(nom);

    fichier
        << "<svg xmlns=\"http://www.w3.org/2000/svg\">"
        << std::endl;
}

ExportSVGVisitor::~ExportSVGVisitor() {
    fichier << "</svg>";
    fichier.close();
}

void ExportSVGVisitor::exporter(Cercle& c) {
    fichier
        << "<circle cx=\""
        << c.getCx()
        << "\" cy=\""
        << c.getCy()
        << "\" r=\""
        << c.getRayon()
        << "\" fill=\"red\" />"
        << std::endl;
}

void ExportSVGVisitor::exporter(Rectangle& r) {
    fichier
        << "<rect x=\""
        << r.getX()
        << "\" y=\""
        << r.getY()
        << "\" width=\""
        << r.getLongueur()
        << "\" height=\""
        << r.getLargeur()
        << "\" fill=\"blue\" />"
        << std::endl;
}

void ExportSVGVisitor::exporter(Groupe& g) {
    fichier << "<g transform=\"translate("
            << g.getTx() << "," << g.getTy() << ") rotate("
            << g.getAngle() << ")\">\n";

    for(auto const& f : g.getFormes()) {
        f->accepter(*this);
    }
    fichier << "</g>\n";
}
