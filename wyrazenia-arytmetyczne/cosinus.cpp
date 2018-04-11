
#include "cosinus.hpp"
#include <cmath>

double Cos::oblicz() {
    return std::cos (fstArg->oblicz());
}
Cos::Cos(Wyrazenie* fstArg) {
    this->fstArg=fstArg;
    Nazwa="cos";
    if(fstArg== nullptr)
        throw std::invalid_argument("nie podano argumentu cosinusa\n");
    priorytet=4;
}
