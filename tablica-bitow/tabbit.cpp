#include "tabbit.hpp"
///Operatory strumieniowe (zaprzyjaźnione)
std::ostream &operator<<(std::ostream &wy, const tab_bit &tb){
    for(int i=0; i<tb.dl; i++){
        wy<<tb.czytaj(i)<<" ";
    }
    return wy;
}

std::basic_istream <char> &operator>>(std::istream &we, tab_bit &tb){
    std::string wek;
    we >> wek;
    if(wek.size()>64* tb.rozmiar()) throw std::range_error("Przekroczono pojemność tablicy\n");
    for(int i=0; i<wek.size(); i++){
        if(wek[i]=='0') tb.pisz(i, false);
        else  tb.pisz(i, true);
    }
    return we;
}


///Konstruktory/destruktor
tab_bit::tab_bit(int rozm) : dl(rozm){
    tab= new slowo[rozmiar()];
    for(int i=0; i<rozmiar(); i++) tab[i]=0;

}

 tab_bit::tab_bit(slowo tb) {
     tab= new slowo[1];
    dl=rozmiarSlowa;
    tab[0]=tb;
}

tab_bit::tab_bit(std::initializer_list<bool> lista) {
    dl=(int)lista.size();
    tab= new slowo[rozmiar()];
    int nrSlowa=0;
    int shift=0;
    for (auto it : lista){
        if(shift==rozmiarSlowa) {
            shift=0;
            nrSlowa++;
        }
        tab[nrSlowa]=tab[nrSlowa]|(((bool)(it))<<shift);
        shift++;
    }
}

tab_bit::tab_bit(const tab_bit &tb){
    dl=tb.dl;
    tab= new slowo[rozmiar()];
    *tab=*tb.tab;
}

tab_bit::tab_bit(tab_bit &&tb)noexcept {
    tab=tb.tab;
    dl=tb.dl;
    tb.tab= nullptr;
}


tab_bit::~tab_bit(){
    delete [] tab;
}
/// operatory = kopiujący/przenoszący
tab_bit &tab_bit::operator=(const tab_bit &tb){
    if(this==&tb) return *this;
    delete[] this->tab;
    dl=tb.dl;
    tab= new slowo[rozmiar()];
    for(int i=0; i<(rozmiar()); i++){
        tab[i]=tb.tab[i];
    }
    return *this;
}
tab_bit &tab_bit::operator=(tab_bit &&tb) noexcept {
    delete[] this->tab;
    tab=tb.tab;
    dl=tb.dl;
    tb.tab= nullptr;
    return *this;
}

///prywatne czytaj i pisz
bool tab_bit::czytaj(int i) const{
    int nrSlowa=i/rozmiarSlowa;
    int shift=i%rozmiarSlowa;
    return (bool)((tab[nrSlowa]>>shift)&1);
}

bool tab_bit::pisz(int i, bool b){
    int nrSlowa=i/rozmiarSlowa;
    int shift=i%rozmiarSlowa;
    auto bb=(slowo )b;
    tab[nrSlowa]=(bb<<shift)| (tab[nrSlowa]& (~ (1<<shift)));
    return true;
}
///rozmiar
int tab_bit::rozmiar() const {
    return (dl+63)/64;
}

///operatory operacji bitowych:
tab_bit operator|(const tab_bit &tb1, const tab_bit &tb2) {
    tab_bit nowe(tb2);
    nowe|=tb1;
    return  nowe;
}
tab_bit &tab_bit::operator|=(const tab_bit &tb){
    int dokad=std::min(dl, tb.dl);
    dokad+=63;
    dokad/=64;
    for(int i=0; i<dokad; i++){
        tab[i]=tab[i]|tb.tab[i];
    }
    return *this;
}
tab_bit operator&(const tab_bit &tb1, const tab_bit &tb2) {
    tab_bit nowe(tb2);
    nowe&=tb1;
    return  nowe;
}
tab_bit &tab_bit::operator&=(const tab_bit &tb){
    int dokad=std::min(dl, tb.dl);
    dokad+=63;
    dokad/=64;
    for(int i=0; i<dokad; i++){
        tab[i]=tab[i]&tb.tab[i];
    }
    return *this;
}
tab_bit operator^(const tab_bit &tb1, const tab_bit &tb2) {
    tab_bit nowe(tb2);
    nowe^=tb1;
    return  nowe;
}

tab_bit &tab_bit::operator^=(const tab_bit &tb){
    int dokad=std::min(dl, tb.dl);
    dokad+=63;
    dokad/=64;
    for(int i=0; i<dokad; i++){
        tab[i]=tab[i]^tb.tab[i];
    }
    return *this;
}

tab_bit operator~(const tab_bit &tb){
    tab_bit nowe(tb);
    for(int i=0; i<(nowe.rozmiar()); i++) nowe.tab[i]=~tb.tab[i];
    return nowe;
}


///operatory []:
bool tab_bit::operator[](int i) const{
    if(i>dl) throw std::invalid_argument("próba stworzenia referencji spoza tablicy\n");
    return czytaj(i);
}
tab_bit::ref tab_bit::operator[](int i) {
    if(i>dl) throw std::invalid_argument("próba stworzenia referencji spoza tablicy\n");
    return ref(i, this);
}

/// operatory klasy ref:

tab_bit::ref& tab_bit::ref::operator=(bool b) {
    MTB->pisz(nr, b);
    return *this;
}

tab_bit::ref& tab_bit::ref::operator=(ref referencja) {
    MTB->pisz(nr, referencja.MTB->czytaj(referencja.nr));
    return *this;
}

tab_bit::ref ::operator bool() const {
     MTB->czytaj(nr);
}