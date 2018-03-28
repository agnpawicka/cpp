#include "wydarzenie.hpp"
#include <algorithm>
#include <vector>

int main() {
    std::cout<<"Kompiluję się\nale nie zamierzam dzialac\n";
    DataGodz p(1998,3,27,17,30,0);
    std::vector<Wydarzenie> vec;
    vec.emplace_back(Wydarzenie(DataGodz(),"Now"));
    vec.emplace_back(Wydarzenie(p,"Birthday"));
    p+=3600;
    vec.emplace_back(Wydarzenie(p,"Meet Dad"));
    sort(vec.begin(),vec.end());
    for (auto v:vec)std::cout << v.zdarzenie << std::endl;
    p-=3600;
    std::cout << "Seconds on this cruel world: " << DataGodz()-p << std::endl;
}



/*Elementy w programie, na które należy zwracać uwagę.

Podział programu na pliki nagłówkowe i źródłowe.

Składowe statyczne w klasie daty.

Odejmowanie dat.

Odejmowanie punktów czasowych.

Operatory dodająe i odejmujące w datach i potem w punktach czsowych.

porównywanie punktów czasowych.*/