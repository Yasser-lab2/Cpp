#ifndef TP1_POINT_H
#define TP1_POINT_H

class Point {
public:
    Point(int x = 0, int y = 0) : x_(x), y_(y) {}

    int abscisse() const { return x_; }
    int ordonnee() const { return y_; }

    void setAbscisse(int x) { x_ = x; }
    void setOrdonnee(int y) { y_ = y; }

private:
    int x_;
    int y_;
};

#endif
