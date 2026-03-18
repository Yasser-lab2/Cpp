#include "Triangle.h"

#include <cmath>
#include <ostream>

Triangle::Triangle() : Forme(3) {}

Triangle::Triangle(const Point& pt1, const Point& pt2, const Point& pt3) : Forme(3) {
    SetPoint(0, pt1);
    SetPoint(1, pt2);
    SetPoint(2, pt3);
}

double Triangle::Aire() const {
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    GetPoint(0).GetXY(x1, y1);
    GetPoint(1).GetXY(x2, y2);
    GetPoint(2).GetXY(x3, y3);

    return std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

void Triangle::Afficher(std::ostream& os) const {
    os << "Triangle : ";
    Forme::Afficher(os);
}
