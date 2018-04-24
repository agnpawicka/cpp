
#ifndef CPP_WYMIERNA_HPP
#define CPP_WYMIERNA_HPP


namespace obliczenia{
#include "wyjatek_wymierny.hpp"
    class Wymierna{
    private:
        int licznik=0;
        int mianownik=1;
    public:
        Wymierna(int licznik, int mianownik=1)throw(dzielenie_przez_0);
        int getLicznik() const;
        int getMianownik() const;

        friend Wymierna operator+(Wymierna &x, Wymierna &y)throw(wyjscie_poza_zakres);
        friend Wymierna operator-(Wymierna &x, Wymierna &y)throw(wyjscie_poza_zakres);
        friend Wymierna operator*(Wymierna &x, Wymierna &y)throw(wyjscie_poza_zakres);
        friend Wymierna operator/(Wymierna &x, Wymierna &y)throw(wyjscie_poza_zakres, dzielenie_przez_0);

        Wymierna &operator-();
        Wymierna &operator!()throw(dzielenie_przez_0);

        friend std::ostream& operator<< (std::ostream &wyj, Wymierna &w);

        operator double();
        explicit operator int();

    public:
        Wymierna &operator+=(Wymierna &y) throw(wyjscie_poza_zakres);
        Wymierna &operator-=(Wymierna &y) throw(wyjscie_poza_zakres);
        Wymierna &operator*=(Wymierna &y) throw(wyjscie_poza_zakres);
        Wymierna &operator/=(Wymierna &y) throw(wyjscie_poza_zakres, dzielenie_przez_0);

    };
}

#endif //CPP_WYMIERNA_HPP

