
#ifndef CPP_LOGARYTM_HPP
#define CPP_LOGARYTM_HPP

#include "operator2arg.hpp"
class logarytm : public operator2arg{
public:
    std::string opis() override ;
    double oblicz() override ;
    logarytm(Wyrazenie* fstArg, Wyrazenie* sndArg);
};
#endif //CPP_LOGARYTM_HPP
