#include "GeoObjektGFX.h"

GeoObjektGFX::GeoObjektGFX(const GeoObjektGFX& other) :
        pinsel(other.pinsel ? other.pinsel->clone() : nullptr),
        pos(other.pos) {}

//GeoObjektGFX& GeoObjektGFX::operator=(const GeoObjektGFX& other)


void GeoObjektGFX::setPinsel(Pinsel* pin) {
    this->pinsel = pin;
}

const Pinsel* GeoObjektGFX::getPinsel() const {
    return pinsel;
}

void GeoObjektGFX::zeichne(CSimpleCanvas& canvas) const {
    for (unsigned int y = 0; y < canvas.getHeight(); y++) {
        for (unsigned int x = 0; x < canvas.getWidth(); x++) {
            Position poss(x, y);
            if (istPositionInnerhalb(poss)) {
                pinsel->male(canvas, pos);
            }
        }
    }
}

Rechteck* Rechteck::clone() const {
    return new Rechteck(*this);
}

unsigned int Rechteck::getBreite() const {return breite;}
unsigned int Rechteck::getHoehe() const {return hoehe;}

bool Rechteck::istPositionInnerhalb(const Position& pos) const {
    return pos.x >= this->getPos().x
           && pos.x < this->getPos().x + this->breite
           && pos.y >= this->getPos().y
           && pos.y < this->getPos().y + this->hoehe;
}

Kreis* Kreis::clone() const {
    return new Kreis(*this);
}
unsigned int Kreis::getBreite() const {return radius*2;}
unsigned int Kreis::getHoehe() const {return radius*2;}

bool Kreis::istPositionInnerhalb(const Position& pos) const {
    int dx = pos.x - this->getPos().x;
    int dy = pos.y - this->getPos().y;
    return dx * dx + dy * dy <= this->radius * this->radius;


}
