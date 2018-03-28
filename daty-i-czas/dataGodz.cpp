
#include "dataGodz.hpp"

DataGodz::DataGodz(int rok, int miesiac, int dzien, int godzina, int minuty, int sekundy) {
    if(!poprawnaDG(dzien, miesiac, rok, godzina, minuty, sekundy)) throw std::invalid_argument("podano niepoprawną datę");
    this->godzina=godzina;
    this->miesiac=miesiac;
    this->sekundy=sekundy;
    this->dzien=dzien;
    this->miesiac=miesiac;
    this->rok=rok;
}

bool DataGodz::poprawnaDG(int dzien, int miesiac, int rok, int godzina, int minuty, int sekundy) {
    if(godzina<0 or godzina>23 or minuty<0 or minuty>59 or sekundy<0 or sekundy>59) return false;
    if(rok<1582 or (rok==1582 and (miesiac<10 or (miesiac==10 and dzien<15)))) return false;
    return miesiac > 0 and miesiac <= 12 and dzien <= dniwMiesiacach[(int)rokPrzestepny(rok)][miesiac] and dzien > 0;

}

DataGodz::DataGodz() {
    std::time_t result = std::time(nullptr);
    std::tm  *czas=std::localtime(&result);
    dzien=czas->tm_mday;
    miesiac=czas->tm_mon+1;
    rok=czas->tm_year+1900;
    godzina=czas->tm_hour;
    minuty=czas->tm_min;
    sekundy=czas->tm_sec;
}

int DataGodz::getGodzina() const {
    return godzina;
}

int DataGodz::getMinuty() const {
    return minuty;
}

int DataGodz::getSekundy() const {
    return sekundy;
}

long long DataGodz::operator-(const DataGodz &dg) {
    return roznicaWdniach(dg)*(24*60*60)+roznicaCzasu(dg);
}

long long DataGodz::roznicaWdniach(const DataGodz &dg) {
    int dni=(dg.rok - rok) *365;
    dni+=(dg.rok/4 -rok/4);
    dni+=(rok/100 - dg.rok/100);
    dni+=(dg.rok/400 - rok/400);
    if(rokPrzestepny(dg.rok)) dni--;
    if(rokPrzestepny(rok)) dni++;
    dni+=dniodpoczroku[rokPrzestepny(dg.rok)][dg.miesiac-1]+dg.dzien;
    dni-=dniodpoczroku[rokPrzestepny(rok)][miesiac-1]+dzien;
    return  -dni;
}

long long DataGodz::roznicaCzasu(const DataGodz &dg) {
    long long sek=(dg.godzina-godzina)*3600;
    sek+=(dg.minuty-minuty)*60;
    sek+=(dg.sekundy-sekundy);
    return -sek;

}

DataGodz &DataGodz::operator--() {
    if(sekundy>0) sekundy--;
    else{
        sekundy=59;
        if(minuty>0)  minuty--;
        else{
            minuty=59;
            if(godzina>0) godzina--;
            else{
                godzina=23;
                if(dzien>1) dzien--;
                else{
                   if(miesiac>1){
                       miesiac--;
                       dzien=dniwMiesiacach[rokPrzestepny(rok)][miesiac];
                   } else{
                       dzien=31;
                       miesiac=12;
                       rok--;
                   }

                }

            }

        }

    }
    return  *this;
}

DataGodz &DataGodz::operator++() {
    if(sekundy<59) sekundy++;
    else{
        sekundy=0;
        if(minuty<59)  minuty++;
        else{
            minuty=0;
            if(godzina<23) godzina++;
            else{
                godzina=0;
                if(dzien<dniwMiesiacach[rokPrzestepny(rok)][miesiac]) dzien++;
                else{
                    dzien=1;
                    if(miesiac<12)      miesiac++;
                    else rok++;

                }

            }

        }

    }
    return  *this;
}

DataGodz &DataGodz::operator-=(int sec) {
    int dni=sec/(24*3600);
    odejmijDni(dni);
    sec%=(24*3600);
    godzina-=sec/3600;
    sec%=3600;
    minuty-=sec/60;
    sec%=60;
    sekundy-=sec;
    if(sekundy<0) {
        sekundy+=60;
        minuty--;
    }
    if(minuty<0){
        minuty+=60;
        godzina--;
    }
    if(godzina<0){
        godzina=+24;
        odejmijDni(1);
    }
    return *this;
}

DataGodz &DataGodz::operator+=(int sec) {
    int dni=sec/(24*3600);
    dodajDni(dni);
    sec/=(24*3600);
    godzina+=sec/3600;
    sec%=3600;
    minuty+=sec/60;
    sec%=60;
    sekundy+=sec;
    if(sekundy>59) {
        sekundy-=60;
        minuty++;
    }
    if(minuty>59){
        minuty-=60;
        godzina++;
    }
    if(godzina>23){
        godzina-=24;
        dodajDni(1);
    }
    return *this;
}

bool DataGodz::operator==(const DataGodz &dg)  {
    return rok==dg.rok and miesiac==dg.miesiac and dzien==dg.dzien and godzina==dg.godzina and minuty==dg.miesiac and sekundy==dg.sekundy;
}


bool DataGodz::operator<(const DataGodz &dg) {
    return (*this-dg)<0;
}




