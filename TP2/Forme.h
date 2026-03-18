#ifndef TP2_FORME_H
#define TP2_FORME_H

#include <iosfwd>
#include <vector>

#include "Point.h"

class Forme {
public:
    explicit Forme(int nbSommets = 3);
    virtual ~Forme() = default;

    void SetPoint(int i, const Point& p);
    Point GetPoint(int i) const;
    virtual void Afficher(std::ostream& os) const;
    virtual double Perimetre() const;
    virtual double Aire() const = 0;
    int GetNbSommets() const;
    virtual void Translation(const Point& pt);

protected:
    std::vector<Point> sommets_;
    int nbSommets_;
};

#endif
