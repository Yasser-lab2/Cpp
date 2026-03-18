#include <iostream>
#include <vector>

#include "Point.h"
#include "Rectangle.h"
#include "RectanglePoints.h"

namespace {
void afficherIntersectionsMultiples(const std::vector<Rectangle>& rectangles) {
    if (rectangles.empty()) {
        std::cout << "Aucun rectangle saisi.\n";
        return;
    }

    Rectangle courant = rectangles.front();
    for (std::size_t i = 1; i < rectangles.size(); ++i) {
        Rectangle resultat;
        if (!courant.intersection(rectangles[i], resultat)) {
            std::cout << "Intersection globale vide apres le rectangle " << i + 1 << ".\n";
            return;
        }
        courant = resultat;
    }

    std::cout << "Intersection globale: ";
    courant.afficher(std::cout);
    std::cout << '\n';
}
}

int main() {
    std::cout << "===== TP1 - Classe Rectangle =====\n";

    Rectangle r1(8, 6, 2, 1);
    std::cout << "Rectangle ordonne a la construction: ";
    r1.afficher(std::cout);
    std::cout << "\nSurface = " << r1.surface() << "\n";
    std::cout << "Est-ce un carre ? " << (r1.carre() ? "Oui" : "Non") << "\n\n";

    r1.rotation90();
    std::cout << "Apres rotation 90 degres: ";
    r1.afficher(std::cout);
    std::cout << "\n\n";

    Point p(4, 4);
    std::cout << "Position du point (4,4) par rapport a r1 = " << r1.position(p) << "\n";

    Rectangle r2(Point(3, 2), Point(10, 7));
    std::cout << "Rectangle construit avec 2 points: ";
    r2.afficher(std::cout);
    std::cout << "\nComparaison de surface r1/r2 = " << r1.comparer(r2) << "\n";
    std::cout << "Position de r1 par rapport a r2 = " << r1.position(r2) << "\n";

    Rectangle uni = r1.reunion(r2);
    Rectangle inter = r1.intersection(r2);
    std::cout << "Union: ";
    uni.afficher(std::cout);
    std::cout << "\nIntersection (version 1): ";
    inter.afficher(std::cout);
    std::cout << "\n";

    Rectangle inter2;
    if (r1.intersection(r2, inter2)) {
        std::cout << "Intersection (version 2): ";
        inter2.afficher(std::cout);
        std::cout << "\n";
    } else {
        std::cout << "Intersection (version 2): vide\n";
    }

    r1.translation(Point(2, 3));
    std::cout << "Apres translation de vecteur OP avec P(2,3): ";
    r1.afficher(std::cout);
    std::cout << "\n\n";

    std::vector<Rectangle> tableau;
    tableau.push_back(Rectangle(0, 0, 10, 10));
    tableau.push_back(Rectangle(2, 1, 7, 9));
    tableau.push_back(Rectangle(3, 3, 8, 8));
    afficherIntersectionsMultiples(tableau);

    RectanglePoints rp1(Point(1, 1), Point(5, 4));
    RectanglePoints rp2(Point(3, 0), Point(6, 3));
    RectanglePoints rpInter;
    std::cout << "\n===== Exercice 17 - Version avec 2 objets Point =====\n";
    std::cout << "rp1: ";
    rp1.afficher(std::cout);
    std::cout << "\nrp2: ";
    rp2.afficher(std::cout);
    std::cout << "\nSurface rp1 = " << rp1.surface() << "\n";
    std::cout << "Position du point (3,2) dans rp1 = " << rp1.position(Point(3, 2)) << "\n";
    if (rp1.intersection(rp2, rpInter)) {
        std::cout << "Intersection rp1/rp2: ";
        rpInter.afficher(std::cout);
        std::cout << "\n";
    } else {
        std::cout << "Intersection rp1/rp2: vide\n";
    }

    return 0;
}
