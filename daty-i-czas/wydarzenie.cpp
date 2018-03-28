#include "wydarzenie.hpp"
Wydarzenie::Wydarzenie(const DataGodz &dg, const std::string &zdarzenie) :termin(dg), zdarzenie(zdarzenie){

}
Wydarzenie::Wydarzenie(int rok, int miesiac, int dzien, int godzina, int minuty, int sekundy, std::string *zdarzenie){
    DataGodz dg(rok, miesiac, dzien, godzina, minuty, sekundy);
    termin = dg;
    this->zdarzenie=*zdarzenie;
}

bool Wydarzenie::operator<(const Wydarzenie &wyd) {
    return this->termin<wyd.termin;
}
