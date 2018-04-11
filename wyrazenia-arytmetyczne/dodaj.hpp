
#ifndef CPP_DODAJ_HPP
#define CPP_DODAJ_HPP

#include "operator2arg.hpp"
class dodaj : public operator2arg{
public:
    double oblicz() override ;
    dodaj(Wyrazenie* fstArg, Wyrazenie* sndArg);
};
#endif //CPP_DODAJ_HPP
