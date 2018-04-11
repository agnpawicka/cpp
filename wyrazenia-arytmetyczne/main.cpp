#include "pi.hpp"
#include "e.hpp"
#include "fi.hpp"
#include "zmienna.hpp"
#include "liczba.hpp"
#include "sinus.hpp"
#include "cosinus.hpp"
#include "przeciw.hpp"
#include "odwrtnosc.hpp"
#include "wartBezwz.hpp"
#include "ln.hpp"
#include "exp.hpp"
#include "podziel.hpp"
#include "pomnoz.hpp"
#include "dodaj.hpp"
#include "odejmij.hpp"
#include "modulo.hpp"
#include "potega.hpp"
#include "logarytm.hpp"


int main(){
    Wyrazenie *w = new odejmij(
            new pi(),
            new dodaj(
                    new liczba(2),
                    new pomnoz(
                            new zmienna("x"),
                            new liczba(7)
                    )
            )
    );
    std::cout<<w->opis()<<std::endl;
    zmienna::dodajZmienna("x", 1);
    std::cout<<w->oblicz()<<"\n";

    Wyrazenie *w1= new  podziel(//((x-1)*x)/2
            new pomnoz(
                    new odejmij(
                            new zmienna("x"),
                            new liczba(1)),
                    new zmienna("x")),
            new liczba(2));
    std::cout<<"pierwsze równanie: w1= "<<w1->opis()<<std::endl;
    double  it=0.0;
    while(it<1.01){
        zmienna::zmienZmienna("x", it);
        std::cout<<"w1("<<it<<")= "<<w1->oblicz()<<"\n";
        it+=0.01;
    }
    Wyrazenie *w2=new podziel(//(3+5)/(2+x*7)
            new dodaj(
                    new liczba(3),
                    new liczba(5)),
            new dodaj(
                    new liczba(2),
                    new pomnoz(
                            new zmienna("x"),
                            new liczba(7)
                    )
            )
    );
    std::cout<<"drugie równanie: w2= "<<w2->opis()<<std::endl;
    it=0.0;
    while(it<1.01){
        zmienna::zmienZmienna("x", it);
        std::cout<<"w2("<<it<<")= "<<w2->oblicz()<<"\n";
        it+=0.01;
    }
    Wyrazenie *w3=new odejmij(//2+x*7-(y*3+5)
            new dodaj(
                    new liczba(2),
                    new pomnoz(
                            new zmienna("x"),
                            new liczba(7)
                    )
            ),
            new dodaj(
                    new pomnoz(
                            new zmienna("y"),
                            new liczba(3)
                    ),
                    new liczba(5)
            )
    );
    zmienna::dodajZmienna("y", 0);

    std::cout<<"trzecie równanie: w3= "<<w3->opis()<<std::endl;
    it=0.0;
    while(it<1.01){
        zmienna::zmienZmienna("x", it);
        zmienna::zmienZmienna("y", it);
        std::cout<<"w3("<<it<<" "<<it<<")= "<<w3->oblicz()<<"\n";
        it+=0.01;
    }

    Wyrazenie *w4=new podziel(//cos((x+1)*x)/e^x^2
            new Cos(
                    new pomnoz(
                            new dodaj(
                                    new zmienna("x"),
                                    new liczba(1)
                            ),
                            new zmienna("x")
                    )
            ),
            new Exp(
                    new potega(
                            new zmienna("x"),
                            new liczba(2)
                    )
            )

    );

    std::cout<<"czwarte równanie: w3= "<<w4->opis()<<std::endl;
    it=0.0;
    while(it<1.01){
        zmienna::zmienZmienna("x", it);
        std::cout<<"w4("<<it<<")= "<<w4->oblicz()<<"\n";
        it+=0.01;
    }


}
