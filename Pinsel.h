#ifndef PINSEL_H
#define PINSEL_H

#include "Position.hpp"
#include "CSimpleCanvas.h"

// Die abstrakte Basisklasse Pinsel
class Pinsel {
public:
    // Kopierkonstruktor (nicht implementiert, um die Verwendung zu verhindern)
    Pinsel(const Pinsel&) {}

    // Löschen des Zuweisungsoperators (um die Verwendung zu verhindern)
    Pinsel& operator=(const Pinsel&) = delete;

    // Reine virtuelle Methode zum Malen auf der Canvas an einer bestimmten Position
    virtual void male(CSimpleCanvas& canvas, const Position& pos) const = 0;

    // Virtueller Destruktor
    virtual ~Pinsel() {}

    // Reine virtuelle Methode zum Klonen des Pinsels
    virtual Pinsel* clone() const = 0;
};
// Die konkrete Klasse PinselFarbe, die von Pinsel erbt
class PinselFarbe : public Pinsel {
protected:
    unsigned char r, g, b;  // Farbwerte (Rot, Grün, Blau)

public:
    // Konstruktor mit Farbwerten als Parameter
    PinselFarbe(unsigned char r, unsigned char g, unsigned char b)
            : Pinsel(*this), r(r), g(g), b(b) {}

    // Virtueller Destruktor
    ~PinselFarbe() override = default;

    // Implementierung der male-Methode
    void male(CSimpleCanvas& canvas, const Position& pos) const override;

    // Implementierung der clone-Methode
    PinselFarbe* clone() const override { return new PinselFarbe(*this); }
};

// Die konkrete Klasse PinselFarbeAddierer, die von PinselFarbe erbt
class PinselAddierer : public PinselFarbe {
public:
    // Konstruktor mit Farbwerten als Parameter
    PinselAddierer(unsigned char r, unsigned char g, unsigned char b) : PinselFarbe(r, g, b) {}
    // Implementierung der male-Methode
    virtual void male(CSimpleCanvas& canvas, const Position& pos) const override;
    // Implementierung der clone-Methode
    PinselAddierer* clone() const override{ return new PinselAddierer(*this); }

    // Virtueller Destruktor
    ~PinselAddierer() override {}
};


// Die konkrete Klasse PinselFarbeTransparent, die von PinselFarbe erbt
class PinselFarbeTransparent : public PinselFarbe {
private:
    double t;  // Transparenzwert

public:
    // Konstruktor mit Farbwerten und Transparenzwert als Parameter
    PinselFarbeTransparent(unsigned char r, unsigned char g, unsigned char b, double t)
            : PinselFarbe(r, g, b), t(t) {}

    // Implementierung der male-Methode
    void male(CSimpleCanvas& canvas, const Position& pos) const override;

    // Implementierung der clone-Methode
    PinselFarbeTransparent* clone() const override { return new PinselFarbeTransparent(*this); }

    // Virtueller Destruktor
    ~PinselFarbeTransparent() override = default;
};


// Die konkrete Klasse PinselInverter, die von Pinsel erbt
class PinselInverter : public Pinsel {
public:
    // Standardkonstruktor
    PinselInverter() : Pinsel(*this) {}

    // Implementierung der male-Methode
    void male(CSimpleCanvas& canvas, const Position& pos) const override;

    // Implementierung der clone-Methode
    PinselInverter* clone() const override { return new PinselInverter(*this); }

    // Virtueller Destruktor
    ~PinselInverter() override = default;
};

#endif // PINSEL_H
