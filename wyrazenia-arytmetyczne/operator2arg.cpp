#include "operator2arg.hpp"

std::string operator2arg::opis() {
    std::string Opis="";
    if(fstArg->getPriorytet()<priorytet or (fstArg->getPriorytet()==priorytet and priorytet==2)){//lewy znawiasowac
        Opis+='('+fstArg->opis()+')'+nazwa();
    } else Opis+=fstArg->opis()+nazwa();

    if(sndArg->getPriorytet()<priorytet){
        return Opis+'('+sndArg->opis()+')';
    }
    if(sndArg->getPriorytet()>priorytet){
        return Opis+sndArg->opis();
    }
    if(Nazwa=="-"  or Nazwa=="mod" or Nazwa=="/" or Nazwa=="*"){
        return Opis+'('+sndArg->opis()+')';
    }
    return Opis+sndArg->opis();
}
