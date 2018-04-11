#include <iostream>
#include <map>

#ifndef CPP_WYRAZENIE_HPP
#define CPP_WYRAZENIE_HPP
class Wyrazenie{
protected:
    std::string Nazwa;
    int priorytet;
public:
    int getPriorytet() const {
        return priorytet;
    }

public:
    std::string nazwa(){
        return Nazwa;
    }
    virtual double oblicz()=0;
    virtual std::string opis()=0;
};

#endif //CPP_WYRAZENIE_HPP
