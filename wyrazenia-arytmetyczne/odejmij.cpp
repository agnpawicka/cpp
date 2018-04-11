
#include "odejmij.hpp"

odejmij::odejmij(Wyrazenie *fstArg, Wyrazenie *sndArg) {
    this->fstArg=(fstArg);
    this->sndArg=(sndArg);
    Nazwa="-";
    if(fstArg== nullptr or sndArg== nullptr)
        throw std::invalid_argument("nie podano wszystkich argumentów odejmowania\n");
    priorytet=0;
}

double odejmij::oblicz() {
    return fstArg->oblicz()-sndArg->oblicz();
}
