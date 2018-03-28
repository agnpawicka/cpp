#ifndef CPP_DATA_HPP
#define CPP_DATA_HPP


#include <stdexcept>
#include <ctime>
#include <iostream>


class Data{
protected:
    int dzien=0;
    int miesiac=1;
    int rok=0;
    static bool rokPrzestepny(int rok);

    static constexpr int dniwMiesiacach[2][13] = {
            {0,31,28,31,30,31,30,31,31,30,31,30,31}, // lata zwykłe
            {0,31,29,31,30,31,30,31,31,30,31,30,31} // lata przestępne
    };
    static constexpr int dniodpoczroku[2][13] = {
            {0,31,59,90,120,151,181,212,243,273,304,334,365}, // lata zwykłe
            {0,31,60,91,121,152,182,213,244,274,305,335,366} // lata przestępne
    };
    void dodajDni(int dni);
    void odejmijDni(int dni);
private:
    bool poprawnaData(int dzien, int miesiac, int rok);
    int ileDniOdUstalonejDaty(Data data);

public:
    int getDzien() const;
    int getMiesiac() const;
    int getRok() const;
    Data(int dzien, int miesiac, int rok);
    Data();
    Data(const Data &data)= default;
    Data &operator=(const Data &data)= default;

    virtual int operator-(const Data &data);

    Data &operator--();
    Data &operator++();

    Data &operator+=(int dni);

    Data &operator-=(int dni);
};

#endif //CPP_DATA_HPP

