#include "wydarzenie.hpp"
#include <algorithm>
#include <vector>

int main() {

    std::cout<<"Testy dla klasy Data\n\n";

    std::cout<<" Próba utorzenia błędniej daty:  ";
    try{
        Data blad(29, 2, 1900);
    }
    catch (const std::exception &e ){
        std::cout<<e.what()<<"\n";
    }


   Data Wielkanoc(1, 4, 2018);
    Data teraz;

    std::cout<<"Zostało "<< Wielkanoc-teraz <<" dni do świąt\n";
    std::cout<<"Jutro będzie "<<(--Wielkanoc)-(++teraz)<<" dni do wielkiej soboty\n";
    ++Wielkanoc;
    --teraz;
    std::cout<<"I tym samym sprawdzone inkrementacja oraz dekrementacja\n";


    teraz+=4;
    if(teraz.getDzien()!= Wielkanoc.getDzien() or teraz.getMiesiac()!=Wielkanoc.getMiesiac()
       or teraz.getRok()!=Wielkanoc.getRok()) std::cout<<"źle dodaje dni\n";
    else std::cout<<"Dobrze dodaje dni\n";
    Wielkanoc-=4;
    if(teraz-Wielkanoc!=4) std::cout<<"Źle odejmuje dni";
    Wielkanoc-=366;
    if(Wielkanoc.getRok()!=2017 or Wielkanoc.getMiesiac()!=3 or Wielkanoc.getDzien()!=27)
        std::cout<<"Żle odejmuje dni\n";

    std::cout<<"\n\nTesty dla klasy DataGodz\n\n";



    DataGodz p(1998,5,23,22,15,0);
    std::vector<Wydarzenie> vec;
    vec.emplace_back(Wydarzenie(DataGodz(),"teraz"));
    vec.emplace_back(Wydarzenie(p,"dzień urodzenia"));
    vec.emplace_back(Wydarzenie(DataGodz(2017),"początek studiów"));
    sort(vec.begin(),vec.end());
    for (auto v:vec)std::cout << v.zdarzenie << std::endl;
    p-=3600;
    std::cout << "Seconds on this cruel world: " << DataGodz()-p << std::endl;
}
