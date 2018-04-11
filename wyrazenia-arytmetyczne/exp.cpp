#include "exp.hpp"
#include <cmath>

double Exp::oblicz() {
    return std::exp(fstArg->oblicz());
}

Exp::Exp(Wyrazenie *fstArg) {
    this->fstArg=fstArg;
    Nazwa="e ^";
    if(fstArg== nullptr)
        throw std::invalid_argument("nie podano argumentu e^x\n");
    priorytet=6;

}

