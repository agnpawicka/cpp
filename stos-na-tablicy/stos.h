#ifndef CPP_STOS_H
#define CPP_STOS_H

#include <iostream>


class stos{
private:
    int pojemnosc;
    int ile;
    std::string* tablica;
public:
    stos&operator=(const stos &stos1);
    stos&operator=(stos &&stos1) noexcept ;
    stos(const int & pojemnosc);
    stos();
    stos(std::initializer_list<std::string> slowa);
    stos(const stos &stos1);
    stos(stos &&stos1)  noexcept;
    ~stos();
    void wloz(const std::string  & slowo);
    std::string sciagnij();
    std::string sprawdz();
    int rozmiar();
};

#endif //CPP_STOS_H
