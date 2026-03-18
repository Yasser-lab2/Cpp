#include "Point.h"

#include <cmath>
#include <ostream>

Point::Point(double x, double y) : x_(x), y_(y) {}

Point Point::Add(const Point& pt) const {
    return Point(x_ + pt.x_, y_ + pt.y_);
}

void Point::Affiche(std::ostream& os) const {
    os << '(' << x_ << ", " << y_ << ')';
}

void Point::GetXY(double& x, double& y) const {
    x = x_;
    y = y_;
}

void Point::SetXY(double x, double y) {
    x_ = x;
    y_ = y;
}

double Point::Distance(const Point& pt) const {
    const double dx = x_ - pt.x_;
    const double dy = y_ - pt.y_;
    return std::sqrt(dx * dx + dy * dy);
}

double Point::Vectoriel(const Point& pt1, const Point& pt2) {
    return pt1.x_ * pt2.y_ - pt1.y_ * pt2.x_;
}
