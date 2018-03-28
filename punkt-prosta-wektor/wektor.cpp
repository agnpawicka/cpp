//
// Created by aga on 04.03.18.
//

#include "wektor.h"


Wektor::Wektor() = default;

Wektor::Wektor(const double  & dx, const double &dy) : dx(dx) , dy(dy){
}

Wektor::Wektor(const Wektor & wektor) : Wektor(wektor.dx, wektor.dy){
}


Wektor Wektor::ZlozWektor(const Wektor & wektor1,const Wektor & wektor2){
    return Wektor(wektor1.dx+wektor2.dx, wektor1.dy+wektor2.dy);
}

Wektor::~Wektor()=default;