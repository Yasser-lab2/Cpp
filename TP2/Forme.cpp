#include "Forme.h"

#include <iomanip>
#include <stdexcept>

Forme::Forme(int nbSommets) : nbSommets_(nbSommets) {
    if (nbSommets < 0) {
        throw std::invalid_argument("Le nombre de sommets doit etre positif.");
    }
    sommets_.resize(static_cast<std::size_t>(nbSommets_));
}

void Forme::SetPoint(int i, const Point& p) {
    if (i < 0 || i >= nbSommets_) {
        throw std::out_of_range("Indice de sommet invalide.");
    }
    sommets_[static_cast<std::size_t>(i)] = p;
}

Point Forme::GetPoint(int i) const {
    if (i < 0 || i >= nbSommets_) {
        throw std::out_of_range("Indice de sommet invalide.");
    }
    return sommets_[static_cast<std::size_t>(i)];
}

void Forme::Afficher(std::ostream& os) const {
    os << "Forme de " << nbSommets_ << " sommets : ";
    for (int i = 0; i < nbSommets_; ++i) {
        sommets_[static_cast<std::size_t>(i)].Affiche(os);
        if (i + 1 != nbSommets_) {
            os << " ";
        }
    }
}

double Forme::Perimetre() const {
    if (nbSommets_ < 2) {
        return 0.0;
    }

    double perimetre = 0.0;
    for (int i = 0; i < nbSommets_; ++i) {
        const Point& courant = sommets_[static_cast<std::size_t>(i)];
        const Point& suivant = sommets_[static_cast<std::size_t>((i + 1) % nbSommets_)];
        perimetre += courant.Distance(suivant);
    }
    return perimetre;
}

int Forme::GetNbSommets() const {
    return nbSommets_;
}

void Forme::Translation(const Point& pt) {
    for (Point& sommet : sommets_) {
        sommet = sommet.Add(pt);
    }
}
