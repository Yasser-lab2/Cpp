#include <iostream>
using namespace std;

class Polynome {
    int  degre;
    int* contenu;   // contenu[i] = coefficient de x^i

public:

    // Constructeur (degre par defaut = 1, coefficients mis a 1)
    Polynome(int d = 1) {
        if (d < 0) {
            cout << "Degre invalide, valeur par defaut (1) utilisee." << endl;
            d = 1;
        }
        degre   = d;
        contenu = new int[degre + 1];
        for (int i = 0; i <= degre; i++)
            contenu[i] = 1;
    }

    // Constructeur de recopie
    Polynome(const Polynome& other) {
        degre   = other.degre;
        contenu = new int[degre + 1];
        for (int i = 0; i <= degre; i++)
            contenu[i] = other.contenu[i];
    }

    // Destructeur
    ~Polynome() {
        delete[] contenu;
    }

    // affiche  — ex: [1, 0, -1, 2] → 1-x^2+2x^3
    void affiche() const {
        bool premier = true;
        for (int i = 0; i <= degre; i++) {
            int c = contenu[i];
            if (c == 0) continue;

            // signe
            if (!premier && c > 0) cout << "+";
            if (c == -1 && i > 0)  cout << "-";
            else if (c != 1 || i == 0) cout << c;

            // partie x^i
            if (i == 1) cout << "x";
            else if (i > 1) cout << "x^" << i;

            premier = false;
        }
        if (premier) cout << "0";
        cout << endl;
    }

    // operator<<
    friend ostream& operator<<(ostream& os, const Polynome& p) {
        os << "[";
        for (int i = 0; i <= p.degre; i++) {
            os << p.contenu[i];
            if (i < p.degre) os << ", ";
        }
        os << "]";
        return os;
    }

    // operator>>
    friend istream& operator>>(istream& is, Polynome& p) {
        cout << "Entrez " << p.degre + 1 << " coefficients (du degre 0 au degre " << p.degre << ") : ";
        for (int i = 0; i <= p.degre; i++)
            is >> p.contenu[i];
        return is;
    }

    // operator==
    bool operator==(const Polynome& other) const {
        if (degre != other.degre) return false;
        for (int i = 0; i <= degre; i++)
            if (contenu[i] != other.contenu[i]) return false;
        return true;
    }

    // operator*  (P * k)
    Polynome operator*(int k) const {
        Polynome result(*this);
        for (int i = 0; i <= result.degre; i++)
            result.contenu[i] *= k;
        return result;
    }

    // operator*  (k * P)  — fonction amie pour permettre k*P
    friend Polynome operator*(int k, const Polynome& p) {
        return p * k;
    }
};


int main() {
    // Test constructeur
    Polynome P(4);
    // Simuler contenu [3,0,5,0,9] manuellement via >>
    // Pour la demo on utilise directement les valeurs
    cin >> P;   // saisir : 3 0 5 0 9
    cout << "P (forme liste)   : " << P  << endl;
    cout << "P (forme polynome): "; P.affiche();

    // Test constructeur de recopie
    Polynome Q(P);
    cout << "Q == P ? " << (Q == P ? "oui" : "non") << endl;

    // Test P * k
    Polynome R = P * 2;
    cout << "P * 2 : " << R << endl;

    // Test k * P
    Polynome S = 3 * P;
    cout << "3 * P : " << S << endl;

    // Test degre invalide
    Polynome X(-5);

    return 0;
}