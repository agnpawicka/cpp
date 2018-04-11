#include "operator1arg.hpp"

std::string operator1arg::opis() {
     if(fstArg->getPriorytet()<priorytet)
        return nazwa()+" ("+fstArg->opis()+')';
    else  return nazwa()+" "+fstArg->opis();
}

operator1arg::~operator1arg() {
    delete fstArg;
}
