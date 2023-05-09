#include "GeoObjektGFX.h"
#include <cmath>

//Vorgegeben
void GeoObjektGFX::zeichne(CSimpleCanvas& canvas) {
    for(int x = 0; x < getBreite(); ++x) {
        for(int y = 0; y < getHoehe(); ++y) {
            if(istPositionInnerhalb(Position(x, y))) {
                this->pinsel->male(canvas, Position(x + pos.x, y + pos.y));
            }
        }
    }
}