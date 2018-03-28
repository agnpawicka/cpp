#ifndef CPP_DATAGODZ_HPP
#define CPP_DATAGODZ_HPP


#include "Data.hpp"

class DataGodz final : public Data{
private:
    int godzina;
    int minuty;
    int sekundy;
    bool poprawnaDG(int dzien, int miesiac, int rok, int godzina, int minuty, int sekundy);
    long long roznicaWdniach(const DataGodz &dg);
    long long roznicaCzasu(const DataGodz &dg);
public:
    DataGodz(int rok, int miesiac=10, int dzien=1, int godzina=11, int minuty=0, int sekundy=0);
    DataGodz();
    int getGodzina() const;
    int getMinuty() const;
    int getSekundy() const;
    DataGodz(const DataGodz &datagodz)= default;
    DataGodz &operator=(const DataGodz &datagodz)= default;
    long long operator-(const DataGodz &dg);
    DataGodz &operator--();
    DataGodz &operator++();
    DataGodz &operator-=(int sec);
    DataGodz &operator+=(int sec);
    bool operator<(const DataGodz &dg) ;
    bool operator==(const DataGodz &dg);


};



#endif //CPP_DATAGODZ_HPP
