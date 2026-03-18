#ifndef TP2_CERCLE_H
#define TP2_CERCLE_H

#include "Forme.h"

class Cercle : public Forme {
public:
    Cercle();
    Cercle(const Point& centre, double rayon);

    double Aire() const override;
    double Perimetre() const override;
    void SetRayon(double rayon);
    double GetRayon() const;
    void Afficher(std::ostream& os) const override;

private:
    double rayon_;
};

#endif
