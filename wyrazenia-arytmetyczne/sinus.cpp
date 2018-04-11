#include <cmath>
#include "sinus.hpp"

double Sin::oblicz() {
    return std::sin (fstArg->oblicz());
}
Sin::Sin(Wyrazenie* fstArg)  {
    this->fstArg=fstArg;
    Nazwa="sin";
    if(fstArg== nullptr)
        throw std::invalid_argument("nie podano argumentu sinusa\n");
    priorytet=4;
}
