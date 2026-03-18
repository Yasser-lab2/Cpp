#ifndef TP2_TRIANGLE_H
#define TP2_TRIANGLE_H

#include "Forme.h"

class Triangle : public Forme {
public:
    Triangle();
    Triangle(const Point& pt1, const Point& pt2, const Point& pt3);

    double Aire() const override;
    void Afficher(std::ostream& os) const override;
};

#endif
