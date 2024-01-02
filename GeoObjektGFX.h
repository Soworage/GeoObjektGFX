#ifndef GEOOBJEKTGFX_H
#define GEOOBJEKTGFX_H

#include "Position.hpp"  // Einbinden der Position-Klasse
#include "Pinsel.h"      // Einbinden der Pinsel-Klasse
#include "CSimpleCanvas.h"  // Einbinden der CSimpleCanvas-Klasse

//class OperandenPassenNicht{};

// Die Klasse GeoObjektGFX
class GeoObjektGFX {
private:
    Pinsel* pinsel;  // Zeiger auf ein Pinsel-Objekt
    Position pos;   // Position des Geoobjekts

public:
    // Konstruktor mit Position als Parameter
    explicit GeoObjektGFX(const Position& pos, Pinsel* p) : pinsel(p), pos(pos) {}

    // Destruktor
    virtual ~GeoObjektGFX() { delete pinsel; }

    // Kopierkonstruktor
    GeoObjektGFX(const GeoObjektGFX& other);




    GeoObjektGFX& operator=(const GeoObjektGFX& other);


    virtual GeoObjektGFX& assign(const GeoObjektGFX& other);



    // Virtuelle Methode zur Erstellung einer Kopie des GeoObjektGFX-Objekts
    virtual GeoObjektGFX* clone() const = 0;

    // Setter für den Pinsel
    void setPinsel(Pinsel* pin);

    // Getter für den Pinsel
    const Pinsel* getPinsel() const;

    // Virtuelle Methode zur Rückgabe der Breite des Geoobjekts
    virtual int getBreite() const = 0;

    // Virtuelle Methode zur Rückgabe der Höhe des Geoobjekts
    virtual int getHoehe() const = 0;

    // Virtuelle Methode zur Überprüfung, ob eine Position innerhalb des Geoobjekts liegt
    virtual bool istPositionInnerhalb(const Position& pos) const = 0;

    // Methode zum Zeichnen des Geoobjekts auf einer CSimpleCanvas
    void zeichne(CSimpleCanvas& canvas);
    // Setter für die Position
    void setPos(const Position& position){
        this->pos = position;
    }
    // Getter für die Position
    const Position& getPos() const{
        return pos;
    }
};

// Die Klasse Rechteck, die von GeoObjektGFX erbt
class Rechteck : public GeoObjektGFX {
private:
    int breite;  // Breite des Rechtecks
    int hoehe;   // Höhe des Rechtecks


public:
    // Konstruktor mit Position, Breite, Höhe und Pinsel als Parameter
    Rechteck(const Position& pos, int breite, int hoehe, Pinsel* pinsel) :
            GeoObjektGFX(pos, pinsel), breite(breite), hoehe(hoehe) {
    }
    // Kopierkonstruktor
    //Rechteck(const Rechteck& other) : GeoObjektGFX(other), breite(other.breite), hoehe(other.hoehe) {}
    Rechteck(const Rechteck& other) = default;

//    GeoObjektGFX(other.getPos()),
//    breite(other.breite),
//    hoehe(other.hoehe) {
//        if(other.getPinsel()){
//            this->setPinsel(other.getPinsel()->clone());
//        }else{
//            this->setPinsel(nullptr);
//        }
//    }
    // Überladung des Zuweisungsoperators
    Rechteck& operator=(const Rechteck& other);
    // Überschreiben der assign-Methode
    Rechteck& assign(const GeoObjektGFX& other) override;
    // Virtuelle Methode zur Erstellung einer Kopie des Rechteck-Objekts
    Rechteck* clone() const override;
    // Virtuelle Methode zur Überprüfung, ob eine Position innerhalb des Rechtecks liegt
    bool istPositionInnerhalb(const Position& pos) const override;
    // Implementierung der Methode getBreite
    int getBreite() const override;
    // Implementierung der Methode getHoehe
    int getHoehe() const override;
};

// Die Klasse Kreis, die von GeoObjektGFX erbt
class Kreis : public GeoObjektGFX {
private:
    int radius;  // Radius des Kreises

public:
    // Konstruktor mit Position, Radius und Pinsel als Parameter
    Kreis(const Position& pos, int radius, Pinsel* pinsel) :
            GeoObjektGFX(pos, pinsel), radius(radius) {
//        GeoObjektGFX::setPinsel(pinsel);
    }
    Kreis(const Kreis& other) = default;
    // Überschreiben der istPositionInnerhalb-Methode
    bool istPositionInnerhalb(const Position& pos) const override;

    // Implementierung der Methode getBreite
    int getBreite() const override;

    // Implementierung der Methode getHoehe
    int getHoehe() const override;

    Kreis &assign(const GeoObjektGFX &other);

    // Überschreiben der clone-Methode
    Kreis* clone() const override;

    Kreis& operator=(const Kreis &other);
};

#endif // GEOOBJEKTGFX_H
