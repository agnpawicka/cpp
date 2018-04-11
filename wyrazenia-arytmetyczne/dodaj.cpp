#include "dodaj.hpp"

double dodaj::oblicz() {
    return fstArg->oblicz()+sndArg->oblicz();
}

dodaj::dodaj(Wyrazenie *fstArg, Wyrazenie *sndArg){
    this->fstArg=(fstArg);
    this->sndArg=(sndArg);
    Nazwa="+";
    if(fstArg== nullptr or sndArg== nullptr)
        throw std::invalid_argument("nie podano wszystkich argumentów dodawania\n");
    priorytet=0;

}
