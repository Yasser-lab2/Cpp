#include "Quadri.h"

#include <cmath>
#include <ostream>

namespace {
double airePolygone(const Forme& forme) {
    double somme = 0.0;
    for (int i = 0; i < forme.GetNbSommets(); ++i) {
        double xi;
        double yi;
        double xj;
        double yj;
        forme.GetPoint(i).GetXY(xi, yi);
        forme.GetPoint((i + 1) % forme.GetNbSommets()).GetXY(xj, yj);
        somme += xi * yj - yi * xj;
    }
    return std::abs(somme) / 2.0;
}
}

Quadri::Quadri() : Forme(4) {}

Quadri::Quadri(const Point& p1, const Point& p2, const Point& p3, const Point& p4) : Forme(4) {
    SetPoint(0, p1);
    SetPoint(1, p2);
    SetPoint(2, p3);
    SetPoint(3, p4);
}

double Quadri::Aire() const {
    return airePolygone(*this);
}

void Quadri::Afficher(std::ostream& os) const {
    os << "Quadrilatere : ";
    Forme::Afficher(os);
}
