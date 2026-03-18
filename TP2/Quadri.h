#ifndef TP2_QUADRI_H
#define TP2_QUADRI_H

#include "Forme.h"

class Quadri : public Forme {
public:
    Quadri();
    Quadri(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

    double Aire() const override;
    void Afficher(std::ostream& os) const override;
};

#endif
