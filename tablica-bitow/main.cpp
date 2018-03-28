#include <iostream>
#include "tabbit.hpp"



int main() {
    ///testy z polecenia
    tab_bit t(46);         // tablica 46-bitowa (zainicjalizowana zerami)
   tab_bit u(45ull);      // tablica 64-bitowa (sizeof(uint64_t)*8)
    tab_bit v(t);          // tablica 46-bitowa (skopiowana z t)
    tab_bit w({1, 0, 1, 1, 0, 0, 0, 1}); // tablica 8-bitowa (przeniesiona)
     v[0] = 1;              // ustawienie bitu 0-go bitu na 1
    t[45] = true;          // ustawienie bitu 45-go bitu na 1
    bool b = v[0];         // odczytanie bitu 1-go
    if(!b) std::cout<<"błąd";
    //u[63]=true;
    //u[45] = u[46] = u[63]; // przepisanie bitu 63-go do bitow 45-go i 46-go
    std::cout<<u[45]<<u[46]<<u[63]<<"wazne\n";
   std::cout << t << "\n\nKoniec testów z polecenia, testy własne\n\n";// wysietlenie zawartości tablicy bitów na ekranie


    ///testy własne:

    std::cout<<"Testowanie konstruktorów\n";

    tab_bit a0(70);
    unsigned long long inicjalizer= 203;
    tab_bit a1(inicjalizer);
    tab_bit a2({1, 0, 0, 0, 0 ,1, 0, 1});
    tab_bit a3(a2);
    for(int i=0; i<8; i++) if(! a2[i]==a3[i]) std::cout<<"źle kopiuje\n";
    tab_bit a4 = std::move(a2);

    for(int i=0; i<8; i++) if(! a4[i]==a3[i]) std::cout<<"źle przenosi\n";

    std::cout<<" Konstruktory poprawne\nStrumienie wejścia/wyjścia:\n";
    std::cout<<a3<<" <- jedna z tablic\n Proszę podać ciąg <=64-ech bitów:\n"
            "Konstruktor wywołany dla długości słowa 10, ale dopóki nie przekroczy długości słowa maszynowego,"
            " nie zwróci błędu\n";
    tab_bit a5(10);
    try{
        std::cin>>a5;
        std::cout<<"\n podano: "<<a5;
    }
    catch (const std::exception &e){
        std::cout<<e.what();
    }
    std::cout<<"\n \nTestowanie operatorów []:\n";

    auto tes = new tab_bit(4);
    (*tes)[1]=true;
    (*tes)[3]=true;
    auto tes1 = new tab_bit(4);
    (*tes1)[1]=(*tes)[1];
    (*tes1)[0]= (*tes)[3];
    std::cout<<"t1: "<<*tes1<<" t2: "<<*tes<<"przypisania działają\n";

    std::cout<<"\nTestowanie operacji logicznych\n";

    tab_bit wyn=((*tes)|(*tes1) );
    std::cout<<"t1|t2: "<<wyn;
    wyn=((*tes)&(*tes1) );
    std::cout<<"\nt1&t2: "<<wyn;
    wyn=((*tes)^(*tes1) );
    std::cout<<"\nt1^t2: "<<wyn;
    wyn=((~*tes1));
    std::cout<<"\n~t1: "<<wyn<<"\n ";
    std::cout<<"t1 : "<<(*tes1)<<"t2 : "<<(*tes)<<"\n\n\n";
    wyn=((*tes1)|=(*tes));
    std::cout<<"t1|=t2: "<<wyn;
    wyn=((*tes1)&=(*tes));
    std::cout<<"\nt1&=t2: "<<wyn;
    wyn=((*tes1)^=(*tes));
    std::cout<<"\nt1^=t2: "<<wyn<<"\n";
    delete tes;
    delete tes1;
}