#include "stos.h"


stos &stos::operator=(const stos &stos1){
    if(this==&stos1) return *this;
    delete[] this->tablica;
    tablica=new std::string[stos1.pojemnosc];
    ile=0;
    pojemnosc=stos1.pojemnosc;
    while(this->ile < stos1.ile){
        tablica[ile]=stos1.tablica[ile];
        ile++;
    }
    return *this;
}


stos &stos::operator=(stos &&stos1) noexcept {
    delete[] this->tablica;
    tablica=stos1.tablica;
    ile=stos1.ile;
    pojemnosc=stos1.pojemnosc;
    stos1.tablica= nullptr;
    return *this;
}


stos::stos(const int & pojemnosc) {
    tablica = new std::string[pojemnosc];
    this->pojemnosc=pojemnosc;
    ile=0;
}

stos::stos() : stos(1){
}

stos::stos(std::initializer_list<std::string> slowa) {
    tablica= new std::string[slowa.size()];
    for (auto it : slowa){
        tablica[ile]=(it);
        ile++;
    }
}
stos::stos(const stos & stos1) {
    tablica=new std::string[stos1.pojemnosc];
    pojemnosc=stos1.pojemnosc;
    ile=0;
    while (ile <stos1.ile){
        tablica[ile]=stos1.tablica[ile];
        ile++;
    }
}
stos::stos(stos &&stos1) noexcept {
    tablica=stos1.tablica;
    pojemnosc=stos1.pojemnosc;
    ile=stos1.ile;
    stos1.tablica= nullptr;
}
stos::~stos() {
    delete[] tablica;
}

void stos::wloz(const std::string & slowo){
    if(ile>=pojemnosc) throw std::range_error("przekroczono zdefiniowaną pojemność stosu");
    tablica[ile]=slowo;
    ile++;
}

std::string stos::sciagnij() {
    if(ile==0) throw std::logic_error("próba zdjęcia elementu z pustego stosu");
    ile--;
    return tablica[ile];
}

std::string stos::sprawdz(){
    if(ile==0) throw std::logic_error("próba odczytania elementu pustego stosu");
    return tablica[ile-1];
}

int stos::rozmiar(){
    return ile;
}