

#ifndef CPP_SINUS_HPP
#define CPP_SINUS_HPP

#include "operator1arg.hpp"
class Sin : public operator1arg{
public:
    double oblicz() override ;
    Sin(Wyrazenie* fstArg);
};
#endif //CPP_SINUS_HPP
