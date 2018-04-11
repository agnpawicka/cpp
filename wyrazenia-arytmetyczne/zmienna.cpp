#include "zmienna.hpp"
std::vector<std::pair<std::string, double >> zmienna::zmienne;

std::string zmienna::opis(){
    return Nazwa;
}

double zmienna::oblicz() {
    try{
        double wart=znajdzZmienna(Nazwa);
        return wart;
    }
    catch (std::exception &e){
        throw std::logic_error("nie podano wartoci używanej zmiennej "+Nazwa+"\n");
    }

}

std::string zmienna::getNazwa() {
    return Nazwa;
}

zmienna::zmienna(std::string nazwa)  {
    Nazwa=nazwa;
    priorytet=7;
}

double zmienna::znajdzZmienna(std::string Nazwa) {
    for(int i=0; i<zmienne.size(); i++){
        if(zmienne[i].first==Nazwa) return zmienne[i].second;
    }
    throw std::exception();
}

void zmienna::dodajZmienna(std::string klucz, double wartosc) {
    zmienne.push_back(std::make_pair(klucz, wartosc));
}

void zmienna::zmienZmienna(std::string klucz, double wartosc) {
    for(int i=0; i<zmienne.size(); i++){
        if(zmienne[i].first==klucz){
            zmienne[i].second=wartosc;
            return;
        }
    }
    throw std::invalid_argument("nie znaleziono zmiennej do zmiany\n");
}

