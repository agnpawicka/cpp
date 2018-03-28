
#include "Data.hpp"
constexpr int Data::dniwMiesiacach[2][13];
constexpr int Data::dniodpoczroku[2][13];
Data::Data(int dzien, int miesiac, int rok) {
    if(!poprawnaData(dzien, miesiac, rok)) throw std::invalid_argument("podano niepoprawną datę");
    this->dzien=dzien;
    this->miesiac=miesiac;
    this->rok=rok;
}

bool Data::poprawnaData(int dzien, int miesiac, int rok) {
    if(rok<1582 or (rok==1582 and (miesiac<10 or (miesiac==10 and dzien<15)))) return false;
    return miesiac > 0 and miesiac <= 12 and dzien <= dniwMiesiacach[(int)rokPrzestepny(rok)][miesiac] and dzien > 0;
}

bool Data::rokPrzestepny(int rok) {
    return (rok % 4 == 0 and rok % 100 != 0) or rok%400==0;
}

int Data::getDzien() const {
    return dzien;
}

int Data::getMiesiac() const {
    return miesiac;
}

int Data::getRok() const {
    return rok;
}

Data::Data() {
    std::time_t result = std::time(nullptr);
    std::tm  *czas=std::localtime(&result);
    dzien=czas->tm_mday;
    miesiac=czas->tm_mon+1;
    rok=czas->tm_year+1900;
}

int Data::ileDniOdUstalonejDaty(Data data) {
    int dni=(data.rok - rok) *365;
    dni+=(data.rok/4 -rok/4);
    dni+=(rok/100 - data.rok/100);
    dni+=(data.rok/400 - rok/400);
    if(rokPrzestepny(data.rok)) dni--;
    if(rokPrzestepny(rok)) dni++;
    dni+=dniodpoczroku[rokPrzestepny(data.rok)][data.miesiac-1]+data.dzien;
    dni-=dniodpoczroku[rokPrzestepny(rok)][miesiac-1]+dzien;
    return dni;
}

int Data::operator-(const Data &data) {
    return ileDniOdUstalonejDaty(data);
}

Data &Data::operator--(){
    if(dzien==15 and miesiac==10 and rok==1582) throw std::logic_error("W obecnej reprezentacji nie ma wcześniejszej daty");
    if(dzien>1) {
        dzien--;
        return *this;
    }
    if(miesiac>1){
        dzien=dniwMiesiacach[rokPrzestepny(rok)][miesiac-1];
        miesiac--;
        return *this;
    }
    dzien=31;
    miesiac=12;
    rok--;
    return  *this;
}

Data &Data::operator++() {
    if(dzien<dniwMiesiacach[rokPrzestepny(rok)][miesiac]){
        dzien++;
        return *this;
    }
    if(miesiac<12){
        dzien=1;
        miesiac++;
        return *this;
    }
    dzien=1;
    miesiac=1;
    rok++;
    return *this;
}

Data &Data::operator+=(int dni) {
    dodajDni(dni);
    return  *this;
}

Data &Data::operator-=(int dni) {
    odejmijDni(dni);
    return  *this;
}

void Data::dodajDni(int dni) {
    if(dni > 4*365+1){
        int latabezsetnych=4*(dni/(3*365+366));
        rok+=latabezsetnych;
        dni%=(3*365+366);
        latabezsetnych+=rok;
        latabezsetnych/=100;
        while(latabezsetnych>rok/100){
            if(latabezsetnych%4!=0) dni++;
        }
    }
    bool przest=rokPrzestepny(rok);
    while(dni>=365){
        rok++;
        if((przest and miesiac<=2 )or (rokPrzestepny(rok) and miesiac>2)) dni-=366;
        else dni-=365;
        przest=rokPrzestepny(rok);
    }
    if(dni==-1){
        operator--();
        return;
    }

    if(dni>=365+przest-dniodpoczroku[przest][miesiac]-dzien){
        dni-=365+przest-dniodpoczroku[przest][miesiac]-dzien;
        rok++;
        przest=rokPrzestepny(rok);
        dzien=1;
        miesiac=1;
    }
    while(dni>dniwMiesiacach[przest][miesiac]){
        dni-=dniwMiesiacach[przest][miesiac];
        miesiac++;
    }
    if(dni+dzien>dniwMiesiacach[przest][miesiac]){
        dni-=dniwMiesiacach[przest][miesiac]-dzien+1;
        miesiac++;
        dzien=1;
    }
    dzien+=dni;
}

void Data::odejmijDni(int dni) {
    if(dni > 4*365+1){
        int latabezsetnych=4*(dni/(3*365+366));
        rok-=latabezsetnych;
        dni%=(3*365+366);
        latabezsetnych+=rok;
        latabezsetnych/=100;
        while(latabezsetnych>rok/100){
            if(latabezsetnych%4!=0) dni++;
        }
    }
    bool przest=rokPrzestepny(rok);
    while(dni>=365){
        rok--;
        if((przest and miesiac>2 )or (rokPrzestepny(rok) and miesiac<=2)) dni-=366;
        else dni-=365;
        przest=rokPrzestepny(rok);
    }
    if(dni==-1){
        operator++();
        return;
    }

    if(dni>=dniodpoczroku[przest][miesiac]){
        dni-=dniodpoczroku[przest][miesiac];
        rok--;
        przest=rokPrzestepny(rok);
        dzien=31;
        miesiac=12;
    }
    while(dni>dniwMiesiacach[przest][miesiac]){
        dni-=dniwMiesiacach[przest][miesiac];
        miesiac--;
    }
    if(dni>dzien){
        dni-=dzien;
        miesiac--;
        dzien=dniwMiesiacach[przest][miesiac];
    }
    dzien-=dni;
}
