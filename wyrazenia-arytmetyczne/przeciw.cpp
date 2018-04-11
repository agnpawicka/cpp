

#include "przeciw.hpp"

przeciw::przeciw(Wyrazenie *fstArg) {
    this->fstArg=fstArg;
    Nazwa="przeciw";
    if(fstArg== nullptr)
        throw std::invalid_argument("nie podano argumentu operatora\n");
    priorytet=1;

}

double przeciw::oblicz() {
    return -fstArg->oblicz();
}

std::string przeciw::opis() {
    if(fstArg->getPriorytet()<priorytet)
        return "-"+'('+fstArg->opis()+')';
    else  return "-"+fstArg->opis();
}
