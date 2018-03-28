//
// Created by aga on 04.03.18.
//

#include <cmath>
#include "prosta.h"

double Prosta::getA() const {
    return a;
}


double Prosta::getB() const {
    return b;
}


double Prosta::getC() const {
    return c;
}

inline void Prosta::normalizacja(){
    double skalar=std::sqrt(a*a + b*b);
    a/=skalar;
    b/=skalar;
    c/=skalar;
}

Prosta::Prosta(){
    this->a=1;
    this->b=1;
    this->c=0;
}

Prosta::Prosta(const Punkt & X, const Punkt & Y){
    if(X.x==Y.x and X.y==Y.y) throw std::invalid_argument("Nie można jednoznacznie wyznaczyć prostej");
    this->a=X.x*(Y.y-X.y);
    this->b=X.y*(X.x-Y.x);
    this->c=(Y.x*X.y)-(Y.y*X.x);
    normalizacja();
}

Prosta::Prosta(const Wektor & wektor){
    if(wektor.dx==wektor.dy and wektor.dy==0) throw  std::invalid_argument("Nie można jednoznacznie wznaczyć prostej");
    this->a=wektor.dx;
    this->b=wektor.dy;
    this->c=-(wektor.dx*wektor.dx+wektor.dy*wektor.dy);
    normalizacja();
}

Prosta::Prosta(const double &A, const double &B,const double &C){
    if(A==B and B==0) throw std::invalid_argument("Współczynniki A i B równania prostej nie mogą być jednocześnie zerami");
    this->a=A;
    this->b=B;
    this->c=C;
    normalizacja();

}
Prosta::Prosta(const Prosta & prosta, const Wektor & wektor){
    this->a=prosta.a;
    this->b=prosta.b;
    this->c=prosta.c-(wektor.dx*prosta.a+ wektor.dy*prosta.b);
    normalizacja();
}


Prosta::~Prosta()=default;

bool Prosta::WektorProstodadlyDoProstej(const Wektor &wektor) {
    return (std::abs(this->a*wektor.dx-this->b*wektor.dy)<epsilon);
}

bool Prosta::WektorRownoleglDoProstej(const Wektor &wektor) {
    return (std::abs(this->a*wektor.dy-this->b*wektor.dx)<epsilon);

}

double Prosta::odlegloscPunktuOdProstej(const Punkt &punkt) {
    double odleglosc=std::abs((this->a*punkt.x+this->b*punkt.y+this->c)/(std::sqrt(this->a*this->a +this->b*this->b)));
    return odleglosc;
}

bool Prosta::punktNaProstej(const Punkt &punkt) {
    if(odlegloscPunktuOdProstej(punkt)<epsilon) return true;
    return false;
}

bool Prosta::ProsteRownolegle(const Prosta & prosta1, const Prosta & prosta2){
    return (std::abs(prosta1.a-prosta2.a)<epsilon and std::abs( prosta1.b-prosta2.b)<epsilon);
}

bool Prosta::ProsteProstopadle(const Prosta & prosta1, const Prosta & prosta2){
    return (std::abs(prosta1.getA()-prosta2.getB())<epsilon and std::abs(prosta1.getB()+prosta2.getA())<epsilon )
           or (std::abs(prosta1.getA()+prosta2.getB())<epsilon and std::abs(prosta1.getB()-prosta2.getA())<epsilon);
}

Punkt Prosta::PunktPrzeciecia(const Prosta & prosta1, const Prosta & prosta2){
    if(ProsteRownolegle(prosta1, prosta2)) throw std::invalid_argument("Proste równoległe się nie przecinają");
    if(prosta1.getB()==0){
        return Punkt(-prosta1.getC()/prosta1.getA(), -(prosta2.getA()+prosta2.getC())/prosta2.getB());
    }
    if(prosta2.getB()==0){
        return Punkt(-prosta2.getC()/prosta2.getA(), -(prosta1.getA()+prosta1.getC())/prosta1.getB());
    }
    double xPrzeciecia=((prosta1.getC()/prosta1.getB())-(prosta2.getC()/prosta2.getB()))/((prosta2.getA()/prosta2.getB())-(prosta1.getA()/prosta1.getB()));
    return Punkt(xPrzeciecia, -(prosta1.getC()+(prosta1.getA()*xPrzeciecia))/prosta1.getB());
}


