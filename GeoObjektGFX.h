#ifndef GEOOBJEKTGFX_H
#define GEOOBJEKTGFX_H

#include "Position.hpp"
#include "Pinsel.h"
#include "CSimpleCanvas.h"


class GeoObjektGFX {
private:
    Pinsel* pinsel;
    Position pos;
public:
    GeoObjektGFX(const Position& pos) : pinsel(nullptr), pos(pos) {}
    virtual ~GeoObjektGFX() { delete pinsel;}
    GeoObjektGFX(const GeoObjektGFX& other);


    virtual GeoObjektGFX& operator=(const GeoObjektGFX& other) {
        if (this == &other) {
            return *this;
        }
        if(typeid(*this) != typeid(other)){
            throw OperandenPassenNicht();
        }
        pos = other.pos;
        delete pinsel;
        pinsel = other.pinsel ? other.pinsel->clone() : nullptr;
        return *this;
    }


    virtual GeoObjektGFX* clone() const = 0;

    void setPinsel(Pinsel* pin);
    const Pinsel* getPinsel() const;

    virtual unsigned int getBreite() const = 0;
    virtual unsigned int getHoehe() const = 0;
    virtual bool istPositionInnerhalb(const Position& pos) const = 0;

    void zeichne(CSimpleCanvas& canvas) const;

    void setPos(const Position& position){
        this->pos = position;
    }
    const Position getPos() const{
        return pos;
    }
};

class Rechteck : public GeoObjektGFX {
private:
    int breite;
    int hoehe;

public:
    Rechteck(const Position& pos, int breite, int hoehe, Pinsel* pinsel) :
            GeoObjektGFX(pos), breite(breite), hoehe(hoehe) {
        GeoObjektGFX::setPinsel(pinsel);
    }

    Rechteck(const Rechteck& other) : GeoObjektGFX(other.getPos()),
                                      breite(other.breite),
                                      hoehe(other.hoehe) {
        if(other.getPinsel()){
            this->setPinsel(other.getPinsel()->clone());
        }else{
            this->setPinsel(nullptr);
        }
    }

    Rechteck& operator=(const Rechteck& other) {
        if (this == &other) {
            return *this;
        }
        GeoObjektGFX::operator=(other);
        breite = other.breite;
        hoehe = other.hoehe;
        return *this;
    }

    Rechteck* clone() const override;
    bool istPositionInnerhalb(const Position& pos) const override;

    unsigned int getBreite() const override;
    unsigned int getHoehe() const override;
};

class Kreis : public GeoObjektGFX {
private:
    int radius;

public:
    Kreis(const Position& pos, int radius, Pinsel* pinsel) : GeoObjektGFX(pos), radius(radius) {
        GeoObjektGFX::setPinsel(pinsel);
    }

    Kreis* clone() const override;
    bool istPositionInnerhalb(const Position& pos) const override;

    unsigned int getBreite() const override;
    unsigned int getHoehe() const override;
};

#endif // GEOOBJEKTGFX_H
