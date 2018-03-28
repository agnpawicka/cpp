#ifndef CPP_WYDARZENIE_HPP
#define CPP_WYDARZENIE_HPP

#include "dataGodz.hpp"

class Wydarzenie {
public:
    DataGodz termin;
    std::string zdarzenie;
public:
    Wydarzenie(const DataGodz &dg, const std::string &zdarzenie);
    Wydarzenie(int rok, int miesiac, int dzien, int godzina, int minuty, int sekundy, std::string *zdarzenie);
    bool operator<(const Wydarzenie &wyd);
};


#endif //CPP_WYDARZENIE_HPP
