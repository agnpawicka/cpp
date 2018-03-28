#ifndef CPP_TABBIT_HPP
#define CPP_TABBIT_HPP


#include <iostream>


class tab_bit {
    typedef unsigned long long slowo; // komorka w tablicy
    static const int rozmiarSlowa=64; // rozmiar slowa w bitach
public:
    friend std::istream &operator>>(std::istream &we, tab_bit &tzb);
    friend std::ostream &operator<<(std::ostream &wy, const tab_bit &tb);

private:
    class ref{// klasa pomocnicza do adresowania bitów
        tab_bit* MTB;
        int nr;
    public:
        ref(int nr, tab_bit* tb): nr(nr),  MTB(tb){}
        ref &operator=(bool b);
        ref &operator=(ref referencja);
        operator bool() const;
    };
protected:
    int dl; // liczba bitów
    slowo *tab; // tablica bitów

public:
    explicit tab_bit(int rozm); // wyzerowana tablica bitow [0...rozm]
    explicit tab_bit(slowo tb); // tablica bitów [0...rozmiarSlowa]
    // zainicjalizowana wzorcem

    tab_bit(std::initializer_list<bool> lista);

    tab_bit(const tab_bit &tb); // konstruktor kopiujący
    tab_bit(tab_bit &&tb) noexcept ; // konstruktor przenoszący

    tab_bit &operator=(const tab_bit &tb); // przypisanie kopiujące
    tab_bit &operator=(tab_bit &&tb) noexcept ; // przypisanie przenoszące

    ~tab_bit(); // destruktor

private:
    bool czytaj(int i) const; // metoda pomocnicza do odczytu bitu
    bool pisz(int i, bool b); // metoda pomocnicza do zapisu bitu

public:
    bool operator[](int i) const; // indeksowanie dla stałych tablic bitowych
    ref operator[](int i); // indeksowanie dla zwykłych tablic bitowych
    inline int rozmiar() const; // rozmiar tablicy w bitach

public:
    friend tab_bit operator|(const tab_bit &tb1, const tab_bit &tb2);
    tab_bit &operator|=(const tab_bit &tb);
    friend tab_bit operator&(const tab_bit &tb1, const tab_bit &tb2);
    tab_bit &operator&=(const tab_bit &tb);
    friend tab_bit operator^(const tab_bit &tb1, const tab_bit &tb2);
    tab_bit &operator^=(const tab_bit &tb);
    friend tab_bit operator~(const tab_bit & tb);
};

#endif //CPP_TABBIT_HPP
