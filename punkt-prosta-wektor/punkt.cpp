//
// Created by aga on 04.03.18.
//

#include "punkt.h"


Punkt::Punkt()=default;


Punkt::Punkt(const double  &x, const double &y) : x(x), y(y){
}

Punkt::Punkt(const Punkt & punkt, const Wektor & wektor) : Punkt(punkt.x+wektor.dx, punkt.y+wektor.dy) {
}

Punkt::Punkt(const Punkt &  punkt ): Punkt(punkt.x, punkt.y){
}

Punkt::~Punkt()=default;