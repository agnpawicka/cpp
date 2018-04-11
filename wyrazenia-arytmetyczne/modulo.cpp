#include "modulo.hpp"
double modulo::oblicz() {
    if((long long)sndArg->oblicz()==0) throw std::invalid_argument("modulo 0 \n");
    return (double )((long long)fstArg->oblicz()%(long long )sndArg->oblicz());
}

modulo::modulo(Wyrazenie *fstArg, Wyrazenie *sndArg) {
    this->fstArg=(fstArg);
    this->sndArg=(sndArg);
    Nazwa="mod";
    if(fstArg== nullptr or sndArg== nullptr)
        throw std::invalid_argument("nie podano wszystkich argumentów reszty z dzielenia\n");
    priorytet=1;
}
