#ifndef CPP_EXCEPT_HPP
#define CPP_EXCEPT_HPP

#include <iostream>

class Except : public std::exception{
public:
    virtual const char * what(){
        return "";
    }
};

class DiferentSize : public Except{
public:
    const char * what() override {
        return "Rozmiary nie pasują";
    }
};
class Skalar0 : public Except{
public:
    const char * what() override {
        return "Próba mnożenia przez zerowy skalar";
    }
};
class Undefined : public Except{
public:
    const  char * what() override {
        return "Działanie niezdefiniowane dla danego typu macierzy";
    }
};
#endif //CPP_EXCEPT_HPP
