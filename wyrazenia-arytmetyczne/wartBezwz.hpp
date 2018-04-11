
#ifndef CPP_WARTBEZWZ_HPP
#define CPP_WARTBEZWZ_HPP



#include "operator1arg.hpp"
class bezwzgledna : public operator1arg{
public:
    double oblicz() override ;
    bezwzgledna(Wyrazenie* fstArg);
    std::string opis() override ;
};

#endif //CPP_WARTBEZWZ_HPP
