#include <iostream>
#include <cmath>
using namespace std;

class Complexe {
    double re;
    double im;

public:

    // Constructeur
    Complexe(double r = 1, double i = 0) : re(r), im(i) {}

    // Setters
    void setRe(double r) { re = r; }
    void setIm(double i) { im = i; }

    // Getters
    double getRe() const { return re; }
    double getIm() const { return im; }

    // Module
    double module() const {
        return sqrt(re * re + im * im);
    }

    // Conjugue
    Complexe conjugue() const {
        return Complexe(re, -im);
    }

    // Inverse
    Complexe inverse() const {
        double norme2 = re * re + im * im;
        if (norme2 == 0) {
            cout << "Erreur : module nul" << endl;
            return Complexe(0, 0);
        }
        return Complexe(re / norme2, -im / norme2);
    }

    // Affiche
    void affiche() const {
        cout << re;
        if (im >= 0)
            cout << " + " << im << "i";
        else
            cout << " - " << -im << "i";
        cout << endl;
    }

    // Operateur *
    Complexe operator*(const Complexe& other) const {
        return Complexe(re * other.re - im * other.im,
                        re * other.im + im * other.re);
    }

    // Operateur /
    Complexe operator/(const Complexe& other) const {
        return (*this) * other.inverse();
    }
};


int main() {
    Complexe z1(3, 4);
    Complexe z2(1, 2);

    cout << "z1 = ";       z1.affiche();
    cout << "z2 = ";       z2.affiche();

    cout << "|z1| = "      << z1.module() << endl;

    cout << "Conjugue z1 = "; z1.conjugue().affiche();
    cout << "Inverse  z1 = "; z1.inverse().affiche();

    cout << "z1 * z2 = ";  (z1 * z2).affiche();
    cout << "z1 / z2 = ";  (z1 / z2).affiche();

    return 0;
}