
#ifndef CPP_ODWRTNOSC_HPP
#define CPP_ODWRTNOSC_HPP

#include "operator1arg.hpp"
class odwrotnosc : public operator1arg{
public:
    double oblicz() override ;
    odwrotnosc(Wyrazenie* fstArg);
    std::string opis() override ;
};
#endif //CPP_ODWRTNOSC_HPP
