#ifndef POSITION_H
#define POSITION_H

#include <typeinfo>

// Eine benutzerdefinierte Ausnahme-Klasse für den Fall, dass Operanden nicht zusammenpassen
class OperandenPassenNicht {};

// Die Position-Klasse, die eine x- und y-Koordinate speichert
class Position {
public:
    int x;
    int y;

    // Konstruktor mit x- und y-Koordinaten als Parameter
    Position(int x, int y) : x(x), y(y) {}

    // Kopierkonstruktor
    Position(const Position& other) : x(other.x), y(other.y) {}

    // Zuweisungsoperator
    Position& operator=(const Position& other) {
        // Überprüfen, ob es sich um dieselbe Instanz handelt
        if (&other == this) {
            return *this;
        }

        // Überprüfen, ob die Operanden denselben Typ haben
        if (typeid(*this) != typeid(other)) {
            throw OperandenPassenNicht();
        }

        // Zuweisung der x- und y-Koordinaten
        this->x = other.x;
        this->y = other.y;
        return *this;
    }
};

#endif // POSITION_H
