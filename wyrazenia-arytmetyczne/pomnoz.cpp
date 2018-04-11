#include "pomnoz.hpp"

double pomnoz::oblicz() {
    return fstArg->oblicz()*sndArg->oblicz();
}

pomnoz::pomnoz(Wyrazenie *fstArg, Wyrazenie *sndArg) {
    this->fstArg=(fstArg);
    this->sndArg=(sndArg);
    Nazwa="*";
    if(fstArg== nullptr or sndArg== nullptr)
        throw std::invalid_argument("nie podano wszystkich argumentów mnożenia\n");
    priorytet=2;

}
