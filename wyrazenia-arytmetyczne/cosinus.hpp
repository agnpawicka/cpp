
#ifndef CPP_COSINUS_HPP
#define CPP_COSINUS_HPP

#include "operator1arg.hpp"
class Cos : public operator1arg{
public:
    double oblicz() override ;
    Cos(Wyrazenie* fstArg);
    std::string opis() override ;
};

#endif //CPP_COSINUS_HPP
