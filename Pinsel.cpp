#include "Pinsel.h"  // Einbinden der Pinsel-Kopfdatei

// Implementierung der PinselFarbe-Methode "male"
void PinselFarbe::male(CSimpleCanvas& canvas, const Position& pos) const {
    canvas(pos.x, pos.y).r = r;  // Setzen des Rotwerts der Pixelposition
    canvas(pos.x, pos.y).g = g;  // Setzen des Grünwerts der Pixelposition
    canvas(pos.x, pos.y).b = b;  // Setzen des Blauwerts der Pixelposition
}
// Implementierung der PinselFarbeAddierer-Methode "male"
void PinselAddierer::male(CSimpleCanvas& canvas, const Position& pos) const {

    // Hinzufügen der Farbwerte zu den vorhandenen Werten, wobei sie auf maximal 255 begrenzt werden
    canvas(pos.x, pos.y).r = std::min(255, canvas(pos.x, pos.y).r + r);
    canvas(pos.x, pos.y).g = std::min(255, canvas(pos.x, pos.y).g + g);
    canvas(pos.x, pos.y).b = std::min(255, canvas(pos.x, pos.y).b + b);
}

// Implementierung der PinselFarbeTransparent-Methode "male"
void PinselFarbeTransparent::male(CSimpleCanvas& canvas, const Position& pos) const {
    // Mischen der Farbwerte mit der Hintergrundfarbe basierend auf dem Transparenzwert
    canvas(pos.x, pos.y).r = t * r + (1 - t) * canvas(pos.x, pos.y).r;
    canvas(pos.x, pos.y).g = t * g + (1 - t) * canvas(pos.x, pos.y).g;
    canvas(pos.x, pos.y).b = t * b + (1 - t) * canvas(pos.x, pos.y).b;
}

// Implementierung der PinselInverter-Methode "male"
void PinselInverter::male(CSimpleCanvas& canvas, const Position& pos) const {
    // Invertieren der Farbwerte durch Subtraktion vom Maximalwert (255)
    canvas(pos.x, pos.y).r = 255 - canvas(pos.x, pos.y).r;
    canvas(pos.x, pos.y).g = 255 - canvas(pos.x, pos.y).g;
    canvas(pos.x, pos.y).b = 255 - canvas(pos.x, pos.y).b;
}


