#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void instrukcja(){
    std::cerr<<" Aby uzyskać rozkład liczby na czynniki pierwsze nalerzy uruchomić program podając jako parametry liczby, których rozkład chcem otrzymać.";
}

long long zamien(std::string *tablicaZnakow){
     int poczatek=0;
    std::string MAX_LL("9223372036854775807");
    if((*tablicaZnakow)[0]=='-') {
        poczatek = 1;
        MAX_LL.back()='8';
    }

    if((int)tablicaZnakow->size() > 19+poczatek) throw std::length_error("podano zbyt długą liczbę");

    for(int i=poczatek; i<(int)tablicaZnakow->size(); i++){
        if(!((*tablicaZnakow)[i]<='9' and (*tablicaZnakow)[i]>='0'))  throw std::logic_error("niedozwolony znak");
    }
    if(tablicaZnakow->size()-poczatek==19){
        int j=poczatek;
        switch (poczatek){
            case (1):
                while((*tablicaZnakow)[j]==MAX_LL[j-1]) j++;
                if(j<(int)tablicaZnakow->size()  and(*tablicaZnakow)[j]>MAX_LL[j-1]) throw std::range_error("Podano za dużą liczbę");
                break;
            default:
                while((*tablicaZnakow)[j]==MAX_LL[j]) j++;
                if(j<(int)tablicaZnakow->size()  and(*tablicaZnakow)[j]>MAX_LL[j]) throw std::range_error("Podano za dużą liczbę");
                break;
        }

    }
    long long zwracane=0;
    for(int i=poczatek; i<(int)tablicaZnakow->size(); i++){
        zwracane*=10;
        zwracane+=((*tablicaZnakow)[i]-'0');
    }
    if(poczatek==1) zwracane*=(-1);
    return zwracane;
}

std::vector<long long > rozloz(long long liczba, bool czypierwsza) {
    std::vector<long long > pierwsze;
    if(liczba==0 || liczba==1 || liczba==-1){
        pierwsze.push_back(liczba);
        return pierwsze;
    }
    if(liczba<0){
        pierwsze.push_back(-1);
        if(liczba==-9223372036854775808){
            pierwsze.push_back(2);
            liczba/=2;
        }
        liczba=-liczba;
    }
    if(czypierwsza){
        pierwsze.push_back(liczba);
        return pierwsze;
    }
    for(long long i=2; i<=sqrt(liczba); i++) while(liczba%i==0){
            pierwsze.push_back(i);
            liczba/=i;
        }
    if(liczba>1) pierwsze.push_back(liczba);
    return pierwsze;
}

bool czypierwsza(long long liczba){
    if(liczba==-9223372036854775808) return false;
    if(liczba<0) liczba=-liczba;
    auto SQRT= static_cast<const long long int>(sqrt(liczba));
    if(liczba%2==0)return false;
    for(int i=3; i<=SQRT; i+=2) if(liczba%i==0) return false;
    return true;
}
void wypis(long long x){
    std::cout<<x<<"*";
}

void wypisz(std::vector<long long> *rozklad, const long long *liczba){
    std::cout<<*liczba<<"=";
    long long ostatnie=(*rozklad)[rozklad->size()-1];
    rozklad->pop_back();
    std::for_each(rozklad->begin(), rozklad->end(), wypis);
    std::cout<<ostatnie<<"\n";
}

int main(int argc, char **argv)
{
    if(argc<2) {
        instrukcja();
        return 0;
    }
    for(int i=1; i<argc; i++) {
        std::string slowo(argv[i]);
        long long liczba;
        try {
            liczba = zamien(&slowo);
            std::vector<long long> rozklad = rozloz(liczba, czypierwsza(liczba));
            wypisz(&rozklad, &liczba);
        }
        catch (const std::exception &e) {
            std::cout << "Niepoprawna liczba: " << e.what() << "\n";

        }
    }
}