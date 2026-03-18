#include "RectanglePoints.h"

#include <algorithm>
#include <ostream>

RectanglePoints::RectanglePoints(const Point& hautGauche, const Point& basDroite)
    : hautGauche_(hautGauche), basDroite_(basDroite) {
    ordonner();
}

void RectanglePoints::ordonner() {
    const int xMin = std::min(hautGauche_.abscisse(), basDroite_.abscisse());
    const int yMin = std::min(hautGauche_.ordonnee(), basDroite_.ordonnee());
    const int xMax = std::max(hautGauche_.abscisse(), basDroite_.abscisse());
    const int yMax = std::max(hautGauche_.ordonnee(), basDroite_.ordonnee());

    hautGauche_.setAbscisse(xMin);
    hautGauche_.setOrdonnee(yMin);
    basDroite_.setAbscisse(xMax);
    basDroite_.setOrdonnee(yMax);
}

void RectanglePoints::afficher(std::ostream& os) const {
    os << "RectanglePoints[(" << hautGauche_.abscisse() << ", " << hautGauche_.ordonnee()
       << "), (" << basDroite_.abscisse() << ", " << basDroite_.ordonnee() << ")]";
}

int RectanglePoints::surface() const {
    return (basDroite_.abscisse() - hautGauche_.abscisse() + 1) *
           (basDroite_.ordonnee() - hautGauche_.ordonnee() + 1);
}

bool RectanglePoints::carre() const {
    return (basDroite_.abscisse() - hautGauche_.abscisse()) ==
           (basDroite_.ordonnee() - hautGauche_.ordonnee());
}

int RectanglePoints::position(const Point& p) const {
    if (p.abscisse() < hautGauche_.abscisse() || p.abscisse() > basDroite_.abscisse() ||
        p.ordonnee() < hautGauche_.ordonnee() || p.ordonnee() > basDroite_.ordonnee()) {
        return -1;
    }

    if (p.abscisse() == hautGauche_.abscisse() || p.abscisse() == basDroite_.abscisse() ||
        p.ordonnee() == hautGauche_.ordonnee() || p.ordonnee() == basDroite_.ordonnee()) {
        return 0;
    }

    return 1;
}

RectanglePoints RectanglePoints::reunion(const RectanglePoints& r) const {
    return RectanglePoints(
        Point(std::min(hautGauche_.abscisse(), r.hautGauche_.abscisse()),
              std::min(hautGauche_.ordonnee(), r.hautGauche_.ordonnee())),
        Point(std::max(basDroite_.abscisse(), r.basDroite_.abscisse()),
              std::max(basDroite_.ordonnee(), r.basDroite_.ordonnee())));
}

bool RectanglePoints::intersection(const RectanglePoints& r, RectanglePoints& resultat) const {
    const int ix1 = std::max(hautGauche_.abscisse(), r.hautGauche_.abscisse());
    const int iy1 = std::max(hautGauche_.ordonnee(), r.hautGauche_.ordonnee());
    const int ix2 = std::min(basDroite_.abscisse(), r.basDroite_.abscisse());
    const int iy2 = std::min(basDroite_.ordonnee(), r.basDroite_.ordonnee());

    if (ix1 > ix2 || iy1 > iy2) {
        return false;
    }

    resultat = RectanglePoints(Point(ix1, iy1), Point(ix2, iy2));
    return true;
}
