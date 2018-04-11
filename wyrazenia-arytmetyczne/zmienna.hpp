
#ifndef CPP_ZMIENNA_HPP
#define CPP_ZMIENNA_HPP

#include <map>
#include <vector>
#include "wyrazenie.hpp"
class zmienna : public Wyrazenie{
private:
    static  std::vector<std::pair<std::string, double >> zmienne;
public:
    static double znajdzZmienna(std::string Nazwa);
    static void dodajZmienna(std::string klucz, double wartosc);
    static void zmienZmienna(std::string klucz, double wartosc);
    zmienna(std::string nazwa);
    std::string getNazwa();
    std::string opis() override ;
    double oblicz() override;
};
#endif //CPP_ZMIENNA_HPP
