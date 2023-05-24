#ifndef POSITION_H
#define POSITION_H

#include <typeinfo>

class OperandenPassenNicht {};

class Position {
public:
    int x;
    int y;

    Position(int x, int y) : x(x), y(y) {}

    Position(const Position& other):x(other.x), y(other.y){}

    Position& operator= (const Position& other){
        if (&other == this){
            return *this;
        }

        if (typeid(*this) != typeid(other)){
            throw OperandenPassenNicht();
        }
        this->x = other.x;
        this->y = other.y;
        return *this;
    }
};

#endif // POSITION_H
