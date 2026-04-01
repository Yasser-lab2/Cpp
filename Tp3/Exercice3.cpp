#include <iostream>
#include <cstring>
using namespace std;

class Obj_class{
private:
    char *nom;
public:
    Obj_class(const char* n){
        nom = new char[strlen(n) + 1];
        strcpy(nom, n);
    }
    Obj_class(const Obj_class& other){
        nom = new char[strlen(other.nom) + 1];
        strcpy(nom, other.nom);
    }
    ~Obj_class(){
        delete[] nom;
    }
}