#ifndef CPP_STALA_HPP
#define CPP_STALA_HPP

#include "wyrazenie.hpp"
class stala : public Wyrazenie{
protected:
     double wartosc;
public:
    std::string opis() override ;
    double oblicz() override;
};
#endif //CPP_STALA_HPP
