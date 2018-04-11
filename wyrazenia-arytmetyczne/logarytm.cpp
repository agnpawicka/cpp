
#include "logarytm.hpp"
#include <cmath>

std::string logarytm::opis() {

    if(sndArg->getPriorytet()<priorytet){
        return "log("+fstArg->opis()+")"+'('+sndArg->opis()+')';
    }
    return "log("+fstArg->opis()+")"+sndArg->opis();
}

double logarytm::oblicz() {
    if(sndArg->oblicz()<=0.0) throw std::invalid_argument("liczba logarytmowana niedodatnia\n");
    if(fstArg->oblicz()<=0.0 || fstArg->oblicz()==1.0) throw std::invalid_argument("podstawa logarytmu niepoprawna\n");
    return std::log(sndArg->oblicz())/std::log(fstArg->oblicz());
}

logarytm::logarytm(Wyrazenie *fstArg, Wyrazenie *sndArg) {
    this->fstArg=(fstArg);
    this->sndArg=(sndArg);
    Nazwa="log";
    if(fstArg== nullptr or sndArg== nullptr)
        throw std::invalid_argument("nie podano wszystkich argumentów logarytmu\n");
    priorytet=5;

}
