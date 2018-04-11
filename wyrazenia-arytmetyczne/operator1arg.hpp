
#ifndef CPP_OPERATOR1ARG_HPP
#define CPP_OPERATOR1ARG_HPP

#include "wyrazenie.hpp"

class operator1arg : public Wyrazenie{
protected:
    Wyrazenie* fstArg;
public:
    std::string opis() override ;
    ~operator1arg() override ;
};
#endif //CPP_OPERATOR1ARG_HPP
