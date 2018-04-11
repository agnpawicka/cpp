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

/*Funkcje pr(Wyrazenie*) oraz demo() są autorstwa Maxa Polarczyka*/

void pr(Wyrazenie *e) {
    std::cout << e->opis() << "\t=\t" << e->oblicz() << std::endl;
}

void demo() {
    std::cout << std::endl << "\t-= DEMO =-" << std::endl;
    zmienna::dodajZmienna("x", 10);
    zmienna::dodajZmienna("y", 200);
    zmienna::dodajZmienna("z", 3000);

    auto dmm = new zmienna("x");
    pr(new liczba(7));
    pr(new pi());
    pr(new e());
    pr(new fi());
    pr(new zmienna("x"));
    pr(new Sin(dmm));
    pr(new Cos(dmm));
    pr(new Exp(dmm));
    pr(new Ln(dmm));
    pr(new bezwzgledna(dmm));
    pr(new przeciw(dmm));
    pr(new odwrotnosc(dmm));
    pr(new dodaj(dmm, dmm));
    pr(new odejmij(dmm, dmm));
    pr(new pomnoz(dmm, dmm));
    pr(new podziel(dmm, dmm));
    pr(new logarytm(dmm, dmm));
    pr(new modulo(dmm, dmm));
    pr(new potega(dmm, dmm));
    std::cout << "\t-= DEMO END =-" << std::endl << std::endl;


}

int main(){
    std::cout << std::fixed;
    std::cout.precision(3);
    demo();
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
    zmienna::zmienZmienna("x", 1);
    std::cout<<w->oblicz()<<"\n";

    Wyrazenie *w1= new  podziel(//((x-1)*x)/2
            new pomnoz(
                    new odejmij(
                            new zmienna("x"),
                            new liczba(1)),
                    new zmienna("x")),
            new liczba(2));
    std::cout<<"pierwsze równanie: w1= "<<w1->opis()<<std::endl;

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
    zmienna::zmienZmienna("y", 0);

    std::cout<<"trzecie równanie: w3= "<<w3->opis()<<std::endl;

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

    std::cout<<"czwarte równanie: w4= "<<w4->opis()<<std::endl;
    double it=0.0;
    while(it<1.01) {
        zmienna::zmienZmienna("x", it);
        zmienna::zmienZmienna("y", it);
        std::cout << "w1(" << it << ")= " << w1->oblicz() << " ";
        std::cout << "w2(" << it << ")= " << w2->oblicz() << " ";
        std::cout << "w3(" << it << ")= " << w3->oblicz() << " ";
        std::cout << "w4(" << it << ")= " << w4->oblicz() << "\n";
        it += 0.01;
    }



    /**testowanie nawiasowana*/
std::cout<<"\n\n\n";

//sin(a^(b*pi) /a+log(e^(3%2))(-d+|15- 1/d|)
    Wyrazenie *test1=new dodaj(
           new podziel(
                   new Sin(
                           new potega(
                                   new zmienna("a"),
                                   new pomnoz(
                                           new zmienna("b"),
                                           new pi()
                                   )
                           )
                   ),
                   new zmienna("a")
           ),
           new logarytm(
                   new Exp(
                           new modulo(
                                   new liczba(3),
                                   new liczba(2)
                           )
                   ),
                   new dodaj(
                           new przeciw(
                                   new zmienna ("d")
                           ),
                           new bezwzgledna(
                                   new odejmij(
                                           new liczba(15),
                                           new odwrotnosc(
                                                   new zmienna("d")
                                           )
                                   )
                           )
                   )
           )
    );
    std::cout<<test1->opis()<<"\n\n";

    //ln e- (ln e^2 - ln e^3)
    Wyrazenie *test2 = new odejmij(
            new Ln(
                    new e()
            ),
            new odejmij(
                    new Ln(
                            new Exp(
                                    new liczba(2)
                            )
                    ),
                    new Ln(
                            new Exp(
                                    new liczba(3)
                            )
                    )
            )
    );
    std::cout<<test2->opis()<<" = "<<test2->oblicz()<<"\n\n";

    //ln (cos (|15-7*fi|))
    Wyrazenie *test3 = new Ln(
            new Cos(
                    new bezwzgledna(
                            new odejmij(
                                    new liczba(15),
                                    new pomnoz(
                                            new liczba(7),
                                            new fi()
                                    )
                            )
                    )
            )
    );
    std::cout<<test3->opis()<<"\n\n";

}