
#ifndef CPP_PODZIEL_HPP
#define CPP_PODZIEL_HPP



#include "operator2arg.hpp"
class podziel : public operator2arg{
public:
    double oblicz() override ;
    podziel(Wyrazenie* fstArg, Wyrazenie* sndArg);
};


#endif //CPP_PODZIEL_HPP
