#ifndef CPP_POMNOZ_HPP
#define CPP_POMNOZ_HPP



#include "operator2arg.hpp"
class pomnoz : public operator2arg{
public:
    double oblicz() override ;
    pomnoz(Wyrazenie* fstArg, Wyrazenie* sndArg);
};

#endif //CPP_POMNOZ_HPP
