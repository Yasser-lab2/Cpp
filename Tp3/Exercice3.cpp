#include <iostream>
#include <cstring>
using namespace std;

class Obj_Class {
    char* nom;

public:

    // Constructeur par defaut
    Obj_Class() {
        nom = new char[1];
        nom[0] = '\0';
    }

    // Constructeur avec parametre
    Obj_Class(const char* n) {
        nom = new char[strlen(n) + 1];
        strcpy(nom, n);
    }

    // Constructeur de recopie
    Obj_Class(const Obj_Class& other) {
        nom = new char[strlen(other.nom) + 1];
        strcpy(nom, other.nom);
    }

    // Destructeur
    ~Obj_Class() {
        delete[] nom;
    }

    // affiche
    void affiche() const {
        cout << nom << endl;
    }

    // affichageRenverse
    void affichageRenverse() const {
        int len = strlen(nom);
        for (int i = len - 1; i >= 0; i--)
            cout << nom[i];
        cout << endl;
    }

    // compare
    bool compare(const char* chaine) const {
        return strcmp(nom, chaine) == 0;
    }
};


int main() {
    Obj_Class x;
    x.affiche();
    x.affichageRenverse();

    Obj_Class y("bateau");
    y.affiche();
    y.affichageRenverse();

    Obj_Class z = y;
    z.affiche();
    z.affichageRenverse();

    if (z.compare("bateau"))
        cout << "identique" << endl;
    else
        cout << "different" << endl;

    return 0;
}