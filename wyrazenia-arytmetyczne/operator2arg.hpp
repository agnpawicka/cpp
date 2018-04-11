
#ifndef CPP_OPERATOR2ARG_HPP
#define CPP_OPERATOR2ARG_HPP

#include "operator1arg.hpp"
class operator2arg : public operator1arg{
protected:
    Wyrazenie * sndArg;
public:
    std::string opis() override ;
    ~operator2arg() override ;
};
#endif //CPP_OPERATOR2ARG_HPP
