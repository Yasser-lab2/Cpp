#ifndef TP1_RECTANGLE_POINTS_H
#define TP1_RECTANGLE_POINTS_H

#include <iosfwd>
#include "Point.h"

class RectanglePoints {
public:
    RectanglePoints(const Point& hautGauche = Point(), const Point& basDroite = Point());

    void afficher(std::ostream& os) const;
    int surface() const;
    bool carre() const;
    int position(const Point& p) const;
    RectanglePoints reunion(const RectanglePoints& r) const;
    bool intersection(const RectanglePoints& r, RectanglePoints& resultat) const;

private:
    void ordonner();

    Point hautGauche_;
    Point basDroite_;
};

#endif
