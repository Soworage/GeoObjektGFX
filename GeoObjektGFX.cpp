#include "GeoObjektGFX.h"
#include "math.h"

// Konstruktor der GeoObjektGFX-Klasse, kopiert die Werte von other und klonen den Pinsel
GeoObjektGFX::GeoObjektGFX(const GeoObjektGFX& other) :
        pinsel(other.pinsel ? other.pinsel->clone() : nullptr),
        pos(other.pos) {}

// Setzt den Pinsel für das GeoObjektGFX-Objekt
void GeoObjektGFX::setPinsel(Pinsel* pin) {
    delete pinsel;
    this->pinsel = pin;
}

// Gibt den Pinsel des GeoObjektGFX-Objekts zurück
const Pinsel* GeoObjektGFX::getPinsel() const {
    return pinsel;
}

// Zeichnet das GeoObjekt auf der gegebenen Canvas
void GeoObjektGFX::zeichne(CSimpleCanvas& canvas) {
    for(int x = 0; x < getBreite(); ++x) {
        for(int y = 0; y < getHoehe(); ++y) {
            if(istPositionInnerhalb(Position(x, y))) {
                this->pinsel->male(canvas, Position(x + pos.x, y + pos.y));
            }
        }
    }
}


GeoObjektGFX &GeoObjektGFX::operator=(const GeoObjektGFX &other) {
//    if (this == &other) {
//        return *this;
//    }
//    if (typeid(*this) != typeid(other)){
//        throw OperandenPassenNicht();
//    }
    assign(other);
    return *this;
}

GeoObjektGFX &GeoObjektGFX::assign(const GeoObjektGFX &other) {
    delete pinsel;
    pinsel = other.pinsel ? other.pinsel->clone() : nullptr;
    pos = other.pos;
    return *this;
}

// Erstellt eine tiefe Kopie des Rechteck-Objekts
Rechteck* Rechteck::clone() const {
    return new Rechteck(*this);
}

// Gibt die Breite des Rechtecks zurück
int Rechteck::getBreite() const {
    return breite;
}

// Gibt die Höhe des Rechtecks zurück
int Rechteck::getHoehe() const {
    return hoehe;
}

// Überprüft, ob die gegebene Position innerhalb des Rechtecks liegt
bool Rechteck::istPositionInnerhalb(const Position& pos) const {
    return pos.x >= 0 && pos.x <= breite && pos.y >= 0 && pos.y <= hoehe;
}

Rechteck &Rechteck::assign(const GeoObjektGFX &other) {
    if (this == &other) return *this;

    const Rechteck*
            otherRechteck = dynamic_cast<const Rechteck*>(&other);
    if(!otherRechteck){
        throw OperandenPassenNicht{};
    }
    GeoObjektGFX::assign(other);
    breite = otherRechteck->breite;
    hoehe = otherRechteck->hoehe;
    return *this;
}

Rechteck &Rechteck::operator=(const Rechteck &other) {
    assign(other);
//        GeoObjektGFX::operator=(other);
//        breite = other.breite;
//        hoehe = other.hoehe;
    return *this;
}



// Gibt die Breite des Kreises zurück (doppelter Radius)
int Kreis::getBreite() const {
    return radius * 2;
}

// Gibt die Höhe des Kreises zurück (doppelter Radius)
int Kreis::getHoehe() const {
    return radius * 2;
}

Kreis &Kreis::assign(const GeoObjektGFX &other) {
    if (this == &other) return *this;

    const Kreis*
            otherKreis = dynamic_cast<const Kreis*>(&other);
    if(!otherKreis){
        throw OperandenPassenNicht{};
    }
    GeoObjektGFX::assign(other);
    radius = otherKreis->radius;
    return *this;
}

Kreis &Kreis::operator=(const Kreis &other) {
    assign(other);
//        GeoObjektGFX::operator=(other);
//        breite = other.breite;
//        hoehe = other.hoehe;
    return *this;
}
// Überprüft, ob die gegebene Position innerhalb des Kreises liegt
bool Kreis::istPositionInnerhalb(const Position& pos) const {
    int a = getBreite() / 2 - pos.x;
    int b = getHoehe() / 2 - pos.y;
    int c = sqrt(a * a + b * b);
    return c <= radius;
}

Kreis* Kreis::clone() const {
    return new Kreis(*this);
}

