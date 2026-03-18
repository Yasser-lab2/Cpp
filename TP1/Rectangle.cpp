#include "Rectangle.h"

#include <algorithm>
#include <cmath>
#include <iostream>

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
    : x1_(x1), y1_(y1), x2_(x2), y2_(y2) {
    ordonner();
}

Rectangle::Rectangle(const Point& p1, const Point& p2)
    : x1_(p1.abscisse()), y1_(p1.ordonnee()), x2_(p2.abscisse()), y2_(p2.ordonnee()) {
    ordonner();
}

void Rectangle::ordonner() {
    if (x1_ > x2_) {
        std::swap(x1_, x2_);
    }
    if (y1_ > y2_) {
        std::swap(y1_, y2_);
    }
}

void Rectangle::afficher(std::ostream& os) const {
    os << "Rectangle[(" << x1_ << ", " << y1_ << "), (" << x2_ << ", " << y2_ << ")]";
}

void Rectangle::saisir(std::istream& is) {
    is >> x1_ >> y1_ >> x2_ >> y2_;
    ordonner();
}

bool Rectangle::carre() const {
    return (x2_ - x1_) == (y2_ - y1_);
}

int Rectangle::surface() const {
    return (x2_ - x1_ + 1) * (y2_ - y1_ + 1);
}

void Rectangle::rotation90() {
    const double centreX = (x1_ + x2_) / 2.0;
    const double centreY = (y1_ + y2_) / 2.0;
    const int largeurPixels = x2_ - x1_ + 1;
    const int hauteurPixels = y2_ - y1_ + 1;

    const double demiLargeur = (hauteurPixels - 1) / 2.0;
    const double demiHauteur = (largeurPixels - 1) / 2.0;

    x1_ = static_cast<int>(std::lround(centreX - demiLargeur));
    x2_ = static_cast<int>(std::lround(centreX + demiLargeur));
    y1_ = static_cast<int>(std::lround(centreY - demiHauteur));
    y2_ = static_cast<int>(std::lround(centreY + demiHauteur));
    ordonner();
}

int Rectangle::position(const Point& p) const {
    const int x = p.abscisse();
    const int y = p.ordonnee();

    if (x < x1_ || x > x2_ || y < y1_ || y > y2_) {
        return -1;
    }

    if (x == x1_ || x == x2_ || y == y1_ || y == y2_) {
        return 0;
    }

    return 1;
}

void Rectangle::translation(const Point& p) {
    x1_ += p.abscisse();
    x2_ += p.abscisse();
    y1_ += p.ordonnee();
    y2_ += p.ordonnee();
}

int Rectangle::comparer(const Rectangle& r) const {
    if (surface() < r.surface()) {
        return -1;
    }
    if (surface() > r.surface()) {
        return 1;
    }
    return 0;
}

bool Rectangle::contientStrictement(const Rectangle& r) const {
    return x1_ < r.x1_ && y1_ < r.y1_ && x2_ > r.x2_ && y2_ > r.y2_;
}

int Rectangle::position(const Rectangle& r) const {
    Rectangle inter;
    const bool aIntersection = intersection(r, inter);

    if (!aIntersection) {
        return -1;
    }

    if (contientStrictement(r)) {
        return 1;
    }

    if (r.contientStrictement(*this)) {
        return 2;
    }

    return 0;
}

Rectangle Rectangle::reunion(const Rectangle& r) const {
    return Rectangle(
        std::min(x1_, r.x1_),
        std::min(y1_, r.y1_),
        std::max(x2_, r.x2_),
        std::max(y2_, r.y2_));
}

Rectangle Rectangle::intersection(const Rectangle& r) const {
    Rectangle resultat;
    if (!intersection(r, resultat)) {
        return Rectangle(0, 0, 0, 0);
    }
    return resultat;
}

bool Rectangle::intersection(const Rectangle& r, Rectangle& resultat) const {
    const int ix1 = std::max(x1_, r.x1_);
    const int iy1 = std::max(y1_, r.y1_);
    const int ix2 = std::min(x2_, r.x2_);
    const int iy2 = std::min(y2_, r.y2_);

    if (ix1 > ix2 || iy1 > iy2) {
        return false;
    }

    resultat = Rectangle(ix1, iy1, ix2, iy2);
    return true;
}
