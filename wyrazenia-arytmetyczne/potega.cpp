#include "potega.hpp"
#include <cmath>
double potega::oblicz() {
    return std::pow(fstArg->oblicz(), sndArg->oblicz());
}

potega::potega(Wyrazenie *fstArg, Wyrazenie *sndArg) {
    this->fstArg=(fstArg);
    this->sndArg=(sndArg);
    Nazwa="^";
    if(fstArg== nullptr or sndArg== nullptr)
        throw std::invalid_argument("nie podano wszystkich argumentów potęgi\n");
    priorytet=6;
}
