
#include "podziel.hpp"

double podziel::oblicz() {
    if(sndArg->oblicz()==0.0) throw std::invalid_argument("dzielenie przez 0\n");
    return fstArg->oblicz()/sndArg->oblicz();
}

podziel::podziel(Wyrazenie *fstArg, Wyrazenie *sndArg)  {
    this->fstArg=(fstArg);
    this->sndArg=(sndArg);
    Nazwa="/";
    if(fstArg== nullptr or sndArg== nullptr)
        throw std::invalid_argument("nie podano wszystkich argumentów dzielenia\n");
    priorytet=2;

}


