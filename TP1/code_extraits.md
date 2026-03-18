# TP1 – Extraits de code essentiels

## Exercice 16 – Intersection

### Intersection booléenne de deux rectangles
Cette fonction décide si deux rectangles se chevauchent et, le cas échéant, construit le rectangle résultant.

```cpp
bool Rectangle::intersection(const Rectangle& r, Rectangle& resultat) const {
    const int ix1 = std::max(x1_, r.x1_);
    const int iy1 = std::max(y1_, r.y1_);
    const int ix2 = std::min(x2_, r.x2_);
    const int iy2 = std::min(y2_, r.y2_);

    if (ix1 > ix2 || iy1 > iy2) {
        return false;
    }

    resultat = Rectangle(ix1, iy1, ix2, iy2);
    return true;
}
```

### Intersection de plusieurs rectangles
Cette fonction `main.cpp` illustre la réduction d'un tableau de rectangles par intersection successive. Elle correspond exactement au besoin décrit dans l’exercice 16.

```cpp
void afficherIntersectionsMultiples(const std::vector<Rectangle>& rectangles) {
    if (rectangles.empty()) {
        std::cout << "Aucun rectangle saisi.\n";
        return;
    }

    Rectangle courant = rectangles.front();
    for (size_t i = 1; i < rectangles.size(); ++i) {
        Rectangle resultat;
        if (!courant.intersection(rectangles[i], resultat)) {
            std::cout << "Intersection globale vide apres le rectangle " << i + 1 << ".\n";
            return;
        }
        courant = resultat;
    }

    std::cout << "Intersection globale: ";
    courant.afficher(std::cout);
    std::cout << '\n';
}
```

### Déclaration complète de `Rectangle`
Rappel structuré de toutes les fonctions déjà utilisées dans les premières parties du TP et nécessaires pour comprendre l’exercice 16.

```cpp
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

private:
    void ordonner();
    int x1_;
    int y1_;
    int x2_;
    int y2_;
};
```

## Exercice 17 – Rectangle composé de `Point`

### Déclaration de `RectanglePoints`
Version orientée objet du rectangle : deux `Point` servent de coins et la classe expose les mêmes opérations que l’ancienne version.

```cpp
class RectanglePoints {
public:
    RectanglePoints(const Point& hautGauche = Point(), const Point& basDroite = Point());

    void afficher(std::ostream& os) const;
    int surface() const;
    bool carre() const;
    int position(const Point& p) const;
    RectanglePoints reunion(const RectanglePoints& r) const;
    bool intersection(const RectanglePoints& r, RectanglePoints& resultat) const;

private:
    void ordonner();

    Point hautGauche_;
    Point basDroite_;
};
```

### Méthodes clés de `RectanglePoints`
Voici les implémentations principales qui manipulent les `Point` pour assurer le bon comportement des opérations géométriques.

```cpp
void RectanglePoints::ordonner() {
    const int xMin = std::min(hautGauche_.abscisse(), basDroite_.abscisse());
    const int yMin = std::min(hautGauche_.ordonnee(), basDroite_.ordonnee());
    const int xMax = std::max(hautGauche_.abscisse(), basDroite_.abscisse());
    const int yMax = std::max(hautGauche_.ordonnee(), basDroite_.ordonnee());

    hautGauche_.setAbscisse(xMin);
    hautGauche_.setOrdonnee(yMin);
    basDroite_.setAbscisse(xMax);
    basDroite_.setOrdonnee(yMax);
}

bool RectanglePoints::intersection(const RectanglePoints& r, RectanglePoints& resultat) const {
    const int ix1 = std::max(hautGauche_.abscisse(), r.hautGauche_.abscisse());
    const int iy1 = std::max(hautGauche_.ordonnee(), r.hautGauche_.ordonnee());
    const int ix2 = std::min(basDroite_.abscisse(), r.basDroite_.abscisse());
    const int iy2 = std::min(basDroite_.ordonnee(), r.basDroite_.ordonnee());

    if (ix1 > ix2 || iy1 > iy2) {
        return false;
    }

    resultat = RectanglePoints(Point(ix1, iy1), Point(ix2, iy2));
    return true;
}
```
