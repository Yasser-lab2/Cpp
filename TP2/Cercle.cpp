#include "Cercle.h"

#include <cmath>
#include <ostream>
#include <stdexcept>

namespace {
constexpr double kPi = 3.14159265358979323846;
}

Cercle::Cercle() : Forme(1), rayon_(1.0) {}

Cercle::Cercle(const Point& centre, double rayon) : Forme(1), rayon_(rayon) {
    if (rayon < 0.0) {
        throw std::invalid_argument("Le rayon doit etre positif.");
    }
    SetPoint(0, centre);
}

double Cercle::Aire() const {
    return kPi * rayon_ * rayon_;
}

double Cercle::Perimetre() const {
    return 2.0 * kPi * rayon_;
}

void Cercle::SetRayon(double rayon) {
    if (rayon < 0.0) {
        throw std::invalid_argument("Le rayon doit etre positif.");
    }
    rayon_ = rayon;
}

double Cercle::GetRayon() const {
    return rayon_;
}

void Cercle::Afficher(std::ostream& os) const {
    os << "Cercle centre ";
    GetPoint(0).Affiche(os);
    os << " rayon = " << rayon_;
}
