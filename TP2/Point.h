#ifndef TP2_POINT_H
#define TP2_POINT_H

#include <iosfwd>

class Point {
public:
    Point(double x = 0.0, double y = 0.0);

    Point Add(const Point& pt) const;
    void Affiche(std::ostream& os) const;
    void GetXY(double& x, double& y) const;
    void SetXY(double x, double y);
    double Distance(const Point& pt) const;
    static double Vectoriel(const Point& pt1, const Point& pt2);

private:
    double x_;
    double y_;
};

#endif
