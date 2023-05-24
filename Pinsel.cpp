#include "Pinsel.h"
// pinselfarbe wird erstellt
void PinselFarbe::male(CSimpleCanvas& canvas, const Position& pos) const {
    canvas(pos.x, pos.y).r = r;
    canvas(pos.x, pos.y).g = g;
    canvas(pos.x, pos.y).b = b;
}

void PinselFarbeAddierer::male(CSimpleCanvas& canvas, const Position& pos) const { // pinselfarbe wird addiert
    canvas(pos.x, pos.y).r = std::min(255, canvas(pos.x, pos.y).r + r);
    canvas(pos.x, pos.y).g = std::min(255, canvas(pos.x, pos.y).g + g);
    canvas(pos.x, pos.y).b = std::min(255, canvas(pos.x, pos.y).b + b);
}
// Farbe wird transparent gemacht mit t * r
void PinselFarbeTransparent::male(CSimpleCanvas& canvas, const Position& pos) const {
    canvas(pos.x, pos.y).r = t * r + (1 - t) * canvas(pos.x, pos.y).r;
    canvas(pos.x, pos.y).g = t * g + (1 - t) * canvas(pos.x, pos.y).g;
    canvas(pos.x, pos.y).b = t * b + (1 - t) * canvas(pos.x, pos.y).b;
}
// Farbe wird invertiert indem die Farben minus der max Zahl sind
void PinselInverter::male(CSimpleCanvas& canvas, const Position& pos) const {
    canvas(pos.x, pos.y).r = 255 - canvas(pos.x, pos.y).r;
    canvas(pos.x, pos.y).g = 255 - canvas(pos.x, pos.y).g;
    canvas(pos.x, pos.y).b = 255 - canvas(pos.x, pos.y).b;
}
