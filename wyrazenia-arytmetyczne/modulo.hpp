#ifndef CPP_MODULO_HPP
#define CPP_MODULO_HPP
#include "operator2arg.hpp"
class modulo: public operator2arg{
public:
    double oblicz() override ;
    modulo(Wyrazenie* fstArg, Wyrazenie* sndArg);
};
#endif //CPP_MODULO_HPP
