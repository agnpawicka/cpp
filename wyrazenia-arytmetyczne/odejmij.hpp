
#ifndef CPP_ODEJMIJ_HPP
#define CPP_ODEJMIJ_HPP
#include "operator2arg.hpp"
class odejmij : public operator2arg{
public:
    double oblicz() override ;
    odejmij(Wyrazenie* fstArg, Wyrazenie* sndArg);
};
#endif //CPP_ODEJMIJ_HPP
