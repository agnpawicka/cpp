
#include "liczba.hpp"

double liczba::oblicz() {
    return wartosc;
}

std::string liczba::opis() {
    return  std::to_string(wartosc);
}

liczba::liczba(double wartosc) : wartosc(wartosc){
    Nazwa="liczba";
    priorytet=7;
}
