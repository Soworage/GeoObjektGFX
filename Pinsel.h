#ifndef PINSEL_H
#define PINSEL_H

#include "Position.hpp"
#include "CSimpleCanvas.h"

class Pinsel {
public:
    Pinsel(const Pinsel&){}
    // Verhindern Sie die Nutzung des Zuweisungsoperators
    Pinsel& operator=(const Pinsel&) = delete;
    virtual void male(CSimpleCanvas& canvas, const Position& pos) const = 0;
    virtual ~Pinsel(){

    }

    virtual Pinsel* clone() const = 0;
};

class PinselFarbe : public Pinsel {
protected:
    unsigned char r, g, b;
public:
    PinselFarbe(unsigned char r, unsigned char g, unsigned char b) : Pinsel(*this),r(r), g(g), b(b) {
    }

    virtual ~PinselFarbe(){

    }

    virtual void male(CSimpleCanvas& canvas, const Position& pos) const override;
    PinselFarbe* clone() const override { return new PinselFarbe(*this); }
};

class PinselFarbeAddierer : public PinselFarbe {
public:
    PinselFarbeAddierer(unsigned char r, unsigned char g, unsigned char b) : PinselFarbe(r, g, b) {}
    virtual void male(CSimpleCanvas& canvas, const Position& pos) const override;
    PinselFarbeAddierer* clone() const override{ return new PinselFarbeAddierer(*this); }
    virtual ~PinselFarbeAddierer(){

    }
};

class PinselFarbeTransparent : public PinselFarbe {
private:
    double t;
public:
    PinselFarbeTransparent(unsigned char r, unsigned char g, unsigned char b, double t) : PinselFarbe(r, g, b), t(t) {}
    virtual void male(CSimpleCanvas& canvas, const Position& pos) const override;
    PinselFarbeTransparent* clone() const override { return new PinselFarbeTransparent(*this); }
    virtual ~PinselFarbeTransparent(){

    }
};

class PinselInverter : public Pinsel {
public:
    PinselInverter(): Pinsel(*this) {}
    virtual void male(CSimpleCanvas& canvas, const Position& pos) const override;
    PinselInverter* clone() const override { return new PinselInverter(*this); }
    virtual ~PinselInverter(){

    }
};

#endif // PINSEL_H
