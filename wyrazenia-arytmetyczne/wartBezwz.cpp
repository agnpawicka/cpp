
#include "wartBezwz.hpp"
#include "operator1arg.hpp"
#include <cmath>
double bezwzgledna::oblicz() {
    if(fstArg->oblicz()>0) return  fstArg->oblicz();
    else return -fstArg->oblicz();
}
bezwzgledna::bezwzgledna(Wyrazenie *fstArg)  {
    this->fstArg=fstArg;
    Nazwa="bezwzgledna";
    if(fstArg== nullptr)
        throw std::invalid_argument("nie podano argumentu dla wartości bezwzględnej\n");
    priorytet=10;
}

std::string bezwzgledna::opis() {
    return '|'+fstArg->opis()+'|';
}
