#ifndef TP1_RECTANGLE_H
#define TP1_RECTANGLE_H

#include <iosfwd>
#include "Point.h"

class Rectangle {
public:
    Rectangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
    Rectangle(const Point& p1, const Point& p2);

    void afficher(std::ostream& os) const;
    void saisir(std::istream& is);

    bool carre() const;
    int surface() const;
    void rotation90();
    int position(const Point& p) const;
    void translation(const Point& p);
    int comparer(const Rectangle& r) const;
    int position(const Rectangle& r) const;
    Rectangle reunion(const Rectangle& r) const;
    Rectangle intersection(const Rectangle& r) const;
    bool intersection(const Rectangle& r, Rectangle& resultat) const;

    int x1() const { return x1_; }
    int y1() const { return y1_; }
    int x2() const { return x2_; }
    int y2() const { return y2_; }

private:
    void ordonner();
    bool contientStrictement(const Rectangle& r) const;

    int x1_;
    int y1_;
    int x2_;
    int y2_;
};

#endif
