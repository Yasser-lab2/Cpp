#include <iostream>
using namespace std;

class Ensemble {
    int* tableau;
    int  taille;     // nombre d'elements actuellement dans l'ensemble
    int  capacite;   // taille maximale fixee par l'utilisateur

public:

    // Constructeur
    Ensemble(int capaciteMax) {
        capacite = capaciteMax;
        taille   = 0;
        tableau  = new int[capacite];
    }

    // Constructeur de recopie
    Ensemble(const Ensemble& other) {
        capacite = other.capacite;
        taille   = other.taille;
        tableau  = new int[capacite];
        for (int i = 0; i < taille; i++)
            tableau[i] = other.tableau[i];
    }

    // Destructeur
    ~Ensemble() {
        delete[] tableau;
    }

    // appartient
    bool appartient(int e) const {
        for (int i = 0; i < taille; i++)
            if (tableau[i] == e) return true;
        return false;
    }

    // getSize
    int getSize() const {
        return taille;
    }

    // ajouter
    void ajouter(int e) {
        if (appartient(e)) return;
        if (taille >= capacite) {
            cout << "Ensemble plein, impossible d'ajouter " << e << endl;
            return;
        }
        tableau[taille++] = e;
    }

    // union
    Ensemble union_ens(const Ensemble& other) const {
        Ensemble result(capacite + other.capacite);
        for (int i = 0; i < taille; i++)
            result.ajouter(tableau[i]);
        for (int i = 0; i < other.taille; i++)
            result.ajouter(other.tableau[i]);
        return result;
    }

    // affiche
    void affiche() const {
        cout << "{ ";
        for (int i = 0; i < taille; i++) {
            cout << tableau[i];
            if (i < taille - 1) cout << ", ";
        }
        cout << " }" << endl;
    }
};


int main() {
    Ensemble E1(5);
    E1.ajouter(10);
    E1.ajouter(20);
    E1.ajouter(30);
    E1.ajouter(20);   // doublon, ignore

    cout << "E1 = "; E1.affiche();
    cout << "Taille E1 = " << E1.getSize() << endl;
    cout << "30 appartient a E1 ? " << (E1.appartient(30) ? "oui" : "non") << endl;
    cout << "99 appartient a E1 ? " << (E1.appartient(99) ? "oui" : "non") << endl;

    Ensemble E2(5);
    E2.ajouter(20);
    E2.ajouter(40);
    E2.ajouter(50);

    cout << "E2 = "; E2.affiche();

    Ensemble E3 = E1.union_ens(E2);
    cout << "E1 U E2 = "; E3.affiche();

    return 0;
}