//
// Created by aga on 04.03.18.
//

#ifndef CPP_PUNKT_H
#define CPP_PUNKT_H

#include "wektor.h"

class  Punkt{
public:
    const double x=0;
    const double y=0;
    Punkt();
    Punkt(const double &x,const double &y);
    Punkt(const Punkt & punkt,const Wektor & wektor);
    Punkt(const Punkt &  punkt);
    ~Punkt();
    Punkt &operator=(const Punkt &)= delete;

};
#endif //CPP_PUNKT_H
