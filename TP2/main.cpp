#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

#include "Cercle.h"
#include "Quadri.h"
#include "Triangle.h"

int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "===== TP2 - Diagramme de classes =====\n";

    Triangle triangle(Point(0.0, 0.0), Point(4.0, 0.0), Point(0.0, 3.0));
    Quadri quadrilatere(Point(0.0, 0.0), Point(5.0, 0.0), Point(5.0, 2.0), Point(0.0, 2.0));
    Cercle cercle(Point(1.0, 1.0), 3.0);

    std::vector<std::unique_ptr<Forme>> formes;
    formes.push_back(std::make_unique<Triangle>(triangle));
    formes.push_back(std::make_unique<Quadri>(quadrilatere));
    formes.push_back(std::make_unique<Cercle>(cercle));

    for (const std::unique_ptr<Forme>& forme : formes) {
        forme->Afficher(std::cout);
        std::cout << "\nPerimetre = " << forme->Perimetre();
        std::cout << "\nAire = " << forme->Aire() << "\n\n";
    }

    Point vecteur(2.0, -1.0);
    triangle.Translation(vecteur);
    std::cout << "Triangle apres translation de (2,-1): ";
    triangle.Afficher(std::cout);
    std::cout << "\n";

    return 0;
}
