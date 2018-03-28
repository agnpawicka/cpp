//
// Created by aga on 04.03.18.
//

#ifndef CPP_PROSTA_H
#define CPP_PROSTA_H

#include <iostream>
#include "punkt.h"

const double epsilon=0.000001;

class Prosta{
private:
    double a;
    double b;
    double c;
    inline  void  normalizacja();
public:
    double getA() const;
    double getB() const;
    double getC() const;


    Prosta();
    Prosta(const Punkt & X,const Punkt & Y);
    Prosta(const Wektor & wektor);
    Prosta(const double & A,const  double &B, const double & C);
    Prosta(const Prosta & prosta, const Wektor & wektor);

    ~Prosta();


    bool WektorProstodadlyDoProstej(const Wektor & wektor);
    bool WektorRownoleglDoProstej(const Wektor & wektor);
    double odlegloscPunktuOdProstej(const Punkt & punkt);
    bool punktNaProstej(const Punkt & punkt);
    static bool ProsteRownolegle(const Prosta & prosta1, const Prosta & prosta2);
    static bool ProsteProstopadle(const Prosta & prosta1,const Prosta & prosta2);
    static Punkt PunktPrzeciecia(const Prosta & prosta1,const Prosta & prosta2);


    Prosta(Prosta & prosta)= delete;
    Prosta &operator=(const Prosta &)= delete;

};

#endif //CPP_PROSTA_H
