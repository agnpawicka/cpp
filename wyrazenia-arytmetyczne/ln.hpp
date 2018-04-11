
#ifndef CPP_LN_HPP
#define CPP_LN_HPP

#include "operator1arg.hpp"
class Ln: public operator1arg{
public:
    double oblicz() override ;
    Ln(Wyrazenie* fstArg);
};
#endif //CPP_LN_HPP
