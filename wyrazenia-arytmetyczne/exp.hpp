
#ifndef CPP_EXP_HPP
#define CPP_EXP_HPP


#include "operator1arg.hpp"
class Exp : public operator1arg{
public:
    double oblicz() override ;
    Exp(Wyrazenie* fstArg);
};

#endif //CPP_EXP_HPP
