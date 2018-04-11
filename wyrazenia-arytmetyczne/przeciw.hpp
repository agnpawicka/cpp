
#ifndef CPP_PRZECIW_HPP
#define CPP_PRZECIW_HPP

#include "operator1arg.hpp"
class przeciw : public operator1arg{
public:
    double oblicz() override ;
    przeciw(Wyrazenie* fstArg);
    std::string opis() override ;
};
#endif //CPP_PRZECIW_HPP
