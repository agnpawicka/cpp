#include <iostream>
#include <vector>
#include "wymierna.hpp"

namespace obliczenia {

    int gdb(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        else return gdb(std::max(a, b) % std::min(a, b), std::min(a, b));
    }

    bool pozaZakresem(long long x) {
        return (x > (long long) INT32_MAX or x < (long long) INT32_MIN);
    }

    Wymierna::Wymierna(int licznik, int mianownik) throw(dzielenie_przez_0) {
        if (mianownik == 0) throw dzielenie_przez_0();
        if (mianownik < 0) {
            mianownik = -mianownik;
            licznik = -licznik;
        }
        int GDB = gdb(std::abs(licznik), mianownik);
        this->licznik = licznik / GDB;
        this->mianownik = mianownik / GDB;
    }

    int Wymierna::getLicznik() const {
        return licznik;
    }


    int Wymierna::getMianownik() const {
        return mianownik;
    }


    Wymierna operator+(Wymierna &x, Wymierna &y) throw(wyjscie_poza_zakres){
        return *(new Wymierna(x)) += y;
    }

    Wymierna operator-(Wymierna &x, Wymierna &y) throw(wyjscie_poza_zakres){
        return *(new Wymierna(x)) -= y;
    }

    Wymierna operator*(Wymierna &x, Wymierna &y) throw(wyjscie_poza_zakres){
        return *(new Wymierna(x)) *= y;
    }

    Wymierna operator/(Wymierna &x, Wymierna &y) throw(wyjscie_poza_zakres, dzielenie_przez_0){
        return *(new Wymierna(x)) /= y;
    }

    Wymierna &Wymierna::operator+=(Wymierna &y)throw(wyjscie_poza_zakres) {
        long long GDB = (gdb(mianownik, y.mianownik));//mianowniki są dodatnie
        long long licz = (long long) licznik * ((long long) y.mianownik / GDB);
        //jeśli licznik pierwszego wyszedł poza zakres oraz oba mają ten sam znak
        if (pozaZakresem(licz) and (((unsigned) y.licznik) >> 31) * (((unsigned) licznik) >> 31) > 0)
            throw wyjscie_poza_zakres();
        else {
            licz += ((long long) y.licznik * ((long long) mianownik / GDB));
            if (pozaZakresem(licz))throw wyjscie_poza_zakres();
            else licznik = (int) licz;
        }

        licz = (long long) mianownik * ((long long) y.mianownik / GDB);
        if (pozaZakresem(licz)) throw wyjscie_poza_zakres();
        mianownik = (int) licz;
        GDB = gdb(std::abs(licznik), mianownik);
        licznik /= (int) GDB;
        mianownik /= (int) GDB;
        //std::cout<<"Sprawdzenie jak wygląda drugi argument  po dodawaniu "<<y<<"\n";
        return *this;
    }

    Wymierna &Wymierna::operator-=(Wymierna &y)throw(wyjscie_poza_zakres) {
        return *(new Wymierna(-y)) += *this;
    }

    Wymierna &Wymierna::operator*=(Wymierna &y) throw(wyjscie_poza_zakres){
        long long GDB1 = gdb(std::abs(licznik), y.mianownik);
        licznik /= GDB1;
        long long GDB2 = gdb(std::abs(y.licznik), mianownik);
        mianownik /= GDB2;
        long long licz = (long long) licznik * ((long long) y.licznik / GDB2);
        if (pozaZakresem(licz))throw wyjscie_poza_zakres();
        licznik = (int) licz;

        licz = (long long) mianownik * ( (long long) y.mianownik / GDB1);
        if (pozaZakresem(licz)) throw wyjscie_poza_zakres();
        mianownik = (int) licz;
        return *this;
    }

    Wymierna &Wymierna::operator/=(Wymierna &y) throw(wyjscie_poza_zakres, dzielenie_przez_0) {
        if (y.licznik == 0) throw dzielenie_przez_0();
        return *this *= *(new Wymierna((!y)));
    }

    Wymierna &Wymierna::operator-() {
        auto nowe=new Wymierna(*this);
        nowe->licznik = -nowe->licznik;
        return *nowe;
    }

    Wymierna &Wymierna::operator!() throw(dzielenie_przez_0) {
        if (licznik == 0) throw dzielenie_przez_0();
        auto nowe=new Wymierna(*this);
       std::swap(nowe->licznik, nowe->mianownik);
        if (nowe->mianownik < 0) {
            nowe->mianownik = -nowe->mianownik;
            nowe->licznik = -nowe->licznik;
        }
        return *nowe;
    }

    std::ostream &operator<<(std::ostream &wyj, Wymierna &w) {
        int l=w.licznik;
        int m=w.mianownik;
        if(l<0) {
            wyj<<"-";
            l=-l;
        }
        int cal=l/m;
        wyj<<cal<<",";
        l=l%m;
        if(l==0){
            wyj<<"0";
            return wyj;
        }
        std::vector<int> liczba;
        auto resz=new int[m];
        int nawias=-1;
        for(int i=0; i<m; i++) resz[i]=-1;
        while(l!=0){
            if(resz[l]==-1){
                resz[l]=(int)liczba.size();
                l*=10;
                liczba.push_back(l/m);
                l=l%m;
            } else{
                nawias=(int)liczba.size();
                break;
            }
        }
        if(nawias<1){
            for(int i=0; i<liczba.size(); i++)wyj<<liczba[i];
        }
        else{
            for(int i=0; i<nawias-1; i++) wyj<<liczba[i];
            wyj<<"(";
            for(int i=nawias-1; i<liczba.size(); i++) wyj<<liczba[i];
            wyj<<")";
        }

        delete[] resz;
        liczba.clear();
         return wyj;
    }

    Wymierna::operator double() {
        return (double)licznik/(double)mianownik;
    }

    Wymierna::operator int() {
        return licznik/mianownik;
    }


}