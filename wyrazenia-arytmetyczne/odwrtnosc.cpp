
#include "odwrtnosc.hpp"

double odwrotnosc::oblicz() {
    return 1/fstArg->oblicz();
}

odwrotnosc::odwrotnosc(Wyrazenie *fstArg) {
    this->fstArg=fstArg;
    Nazwa="odwrotnosc";
    if(fstArg== nullptr)
        throw std::invalid_argument("nie podano argumentu operatora\n");
    priorytet=3;

}

std::string odwrotnosc::opis() {
    if(fstArg->getPriorytet()<priorytet)
        return "1/"+'('+fstArg->opis()+')';
    else  return "1/"+fstArg->opis();
}
