
#include <cmath>
#include "ln.hpp"

double Ln::oblicz() {
    if(fstArg->oblicz()<=0.0) throw std::invalid_argument("liczba logarytmowana niedodatnia\n");
    return std::log(fstArg->oblicz());
}

Ln::Ln(Wyrazenie *fstArg) {
    this->fstArg=fstArg;
    Nazwa="ln";
    if(fstArg== nullptr)
        throw std::invalid_argument("nie podano argumentu logarytmu naturalnego\n");
    priorytet=5;
}
