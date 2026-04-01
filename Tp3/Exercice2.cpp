#include <iostream>
#include <cstring>
using namespace std;

class Instrument {
    char* nom;
    double prix;

public:

    // Constructeur
    Instrument(const char* n, double p) {
        nom = new char[strlen(n) + 1];
        strcpy(nom, n);
        prix = p;
    }

    // Constructeur de copie
    Instrument(const Instrument& other) {
        nom = new char[strlen(other.nom) + 1];
        strcpy(nom, other.nom);
        prix = other.prix;
    }

    // Destructeur
    ~Instrument() {
        delete[] nom;
    }

    // Affiche
    void affiche() const {
        cout << "Instrument : " << nom << ", Prix : " << prix << endl;
    }

    // memePrix
    bool memePrix(const Instrument& other) const {
        return prix == other.prix;
    }
};


int main() {
    Instrument A("Saxophone", 750.80);
    Instrument B=A;
    B.affiche();

    Instrument C("Guitare", 380.95);
    if (C.memePrix(B)) {
        cout << "la guitare/le saxophone, meme prix!" << endl;
    } else {
        cout << "la guitare/le saxophone, prix different!" << endl;
    }

    return 0;
}