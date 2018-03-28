#include "stos.h"
stos* nowy(int poj) {
    auto s = new stos(poj);
    return s;
}
int main(){
    auto s1 = new stos();
    s1->wloz("poprawny");
    std::cout<<"Utworzono stos konstruktorem domyślnym, włożono jedno słowo\n";
    std::cout<<"rozmiar stosu: "<<s1->rozmiar()<<"\n";
    std::cout<<"próba włożenia drugiego elemenu:\n";
    try{
        s1->wloz("drugie");
    }
    catch (const std::exception &e) {
        std::cout << e.what() << "   - proba włożenia więcej elementów niż pozwala zdeklarowana pojemność\n";
    }
    auto s2=new stos(*s1);
    delete s1;
    std::cout<<"\nskopiowano powyższy stos, parametry drugiego:\n";
    std::cout<<"rozmiar stosu: "<<s2->rozmiar()<<"\n";
    std::cout<<"element z wierzchu stosu: "<<s2->sprawdz()<<"\n";

    auto  s3=std::move(*s2);
    delete s2;

       std::cout<<"\nprzeniesiono powyższy stos, parametry nowego:\n";
    std::cout<<"rozmiar stosu: "<<s3.rozmiar()<<"\n";
    std::cout<<"element z wierzchu stosu: "<<s3.sprawdz()<<"\n";
    auto s4=new stos({"jeden", "dwa", "trzy"});
    std::cout<<"\n\n utworzono nowy stos za pomocą <initializer list>, stos składa się z 3-ech elementów\n";
    for(int i=1; i<=4; i++){
        try{
            std::cout<<s4->sciagnij()<<" ";
        }
        catch (const std::exception &e) {
            std::cout << e.what() << "\n";
        }
    }
    delete  s4;


    std::cout<<"\n\nczas na testowanie interaktywne (ta część używa kontruktora od rozmiaru)\n";
    bool czyTestowacNadal=1;
    std::cout<<"\n\nproszę podać pojemność nowego stosu: ";
    int poj;
    std::cin>>poj;
    auto s=nowy(poj);
    while (czyTestowacNadal){

        std::cout<<"wprowadź:\n         1 - jesli chcesz wlozyc element na stos\n"
                "         2 - jesli chcesz zdjąc elemnt ze stosu\n"
                "         3 - jesli chcesz odczytac element z ierzchu stosu\n"
                "         4 - jesli chcesz poznac rozmiar stosu\n"
                "         0 - jesli chcesz zakonczyc testowanie\n";
        int coZrobic;
        std::cin>>coZrobic;
        std::string nowy;
        switch (coZrobic){
            case 0:
                czyTestowacNadal=0;
                break;

            case 1:
                std::cout<<" podaj element do włożenia na stos: ";

                std::cin>>nowy;
                try {
                    s->wloz(nowy);
                }
                catch (const std::exception &e) {
                    std::cout << e.what() << "\n";
                }
                break;
            case 2:
                try {
                    std::cout<<"element, ktory byl na wierzchu stosu: "<<s->sciagnij()<<"\n";
                }
                catch (const std::exception &e) {
                    std::cout << e.what() << "\n";
                }
                break;
            case 3:
                try {
                    std::cout<<"element, ktory jest na wierzchu stosu: "<<s->sprawdz()<<"\n";
                }
                catch (const std::exception &e) {
                    std::cout << e.what() << "\n";
                }
                break;
            case 4:
                std::cout<<"rozmiar : "<<s->rozmiar()<<"\n";
                break;
            default:
                std::cout<<"wprowadź:\n         1 - jesli chcesz wlozyc element na stos\n"
                        "         2 - jesli chcesz zdjąc elemnt ze stosu\n"
                        "         3 - jesli chcesz odczytac element z ierzchu stosu\n"
                        "         4 - jesli chcesz poznac rozmiar stosu\n"
                        "         0 - jesli chcesz zakonczyc testowanie\n";

        }

    }


}