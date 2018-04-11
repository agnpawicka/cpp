
#ifndef CPP_POTEGA_HPP
#define CPP_POTEGA_HPP

#include "operator2arg.hpp"
class potega : public operator2arg{
public:
    double oblicz() override ;
    potega(Wyrazenie* fstArg, Wyrazenie* sndArg);
};
#endif //CPP_POTEGA_HPP
