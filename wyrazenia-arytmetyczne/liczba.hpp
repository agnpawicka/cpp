#ifndef CPP_LICZBA_HPP
#define CPP_LICZBA_HPP

#include "wyrazenie.hpp"
class liczba : public Wyrazenie{
private:
    double wartosc;
public:
    liczba(double wartosc);
    std::string opis() override ;
    double oblicz() override;

};
#endif //CPP_LICZBA_HPP
