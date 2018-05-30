
#include <vector>
#include <algorithm>
#include "ignore.hpp"
#include "Out.hpp"
#include "In.hpp"

typedef std::pair <std::string, int> psi;
namespace Strumienie {
    inline std::basic_istream<char> &clearline(std::istream &is) {
        std::string a;
        getline(is, a);
        return is;

    }

    inline std::ostream &endline(std::ostream &os) {
        return (os << '\n');
    }

    inline std::ostream &comma(std::ostream &os) {
        return os << ", ";
    }

    inline std::ostream &colon(std::ostream &os) {
        return os << ": ";
    }
}
int main(int argc, char **argv){
        if(argc>2) {
        std::string aa="sialala";
        std::string bb="";
        std::string cc="";
        int  c;
        std::string nazwa = argv[1];
        try {
            auto wyj = new Out(nazwa);
            for(int i=0; i<aa.size(); i++) {
                (*wyj) << (int)aa[i];
            }
            delete wyj;
        }
        catch (std::ofstream::failure &e){
            std::cout<<e.what();
        }
        try {
            auto wej = new In(nazwa);
            for(int i=0; i<aa.size(); i++){
                *wej >>  c;
                bb.push_back((char)((c+1)%128));
            }
            delete wej;
        }catch (std::ifstream::failure &e){
            std::cout<<e.what();
        }
        nazwa = argv[2];
        try {
            auto wyj2 = new Out(nazwa);
            for(int i=0; i<bb.size(); i++) {
                (*wyj2) << (int)bb[i];
            }
            delete wyj2;
        }
        catch (std::ofstream::failure &e){
            std::cout<<e.what();
        }
        try {
            auto wej2 = new In(nazwa);
            for(int i=0; i<bb.size(); i++) {
                (*wej2) >> c;
                cc.push_back((char)((c+127)%128));
            }
            delete wej2;
        }catch (std::ifstream::failure &e){
            std::cout<<e.what();
            std::cout<<e.what();
        }

        std::cout<<"zawartoć pierwszego pliku"<<Strumienie::colon<<aa<<Strumienie::endline<<"modyfikacja"<<Strumienie::colon;
        std::cout<<bb<<Strumienie::endline<<"odwrócenie modyfikacji"<<Strumienie::colon<<cc<<Strumienie::endline;

    }
    std::cout<<"Proszę podać 3 linie znaków"<<Strumienie::colon<<Strumienie::endline;
    std::string a, b;
    std::cin>>Strumienie::clearline>>a>>b;
    std::cout<<"wczytane linie"<<Strumienie::colon<<a<<" "<<b<<" ";
    std::cout << "x"<<Strumienie::colon<<"123123"<<Strumienie::comma <<"123"<<Strumienie::endline;
    std::cout<<Strumienie::indeks(123, 5)<<Strumienie::endline<<Strumienie::indeks(7, 5);
    std::cout<<"proszę podać słowo dla przetestowania manipulatora 'ignore'"<<Strumienie::colon;
    std::cin >> Strumienie::ignore(5)>>a;
    std::cout<<a<<Strumienie::endline;




    std::cout<<"Proszę podać kilka łańcuchów znaków, zakończć EOF"<<Strumienie::colon<<Strumienie::endline;
    std::vector<psi> vec;
    int num=1;
    std::string s;
    while (getline(std::cin, s)){
        vec.emplace_back(psi(s, num));
        num++;
    }
    std::sort(vec.begin(), vec.end());
    for(int i=0; i<num; i++){
        if(vec[i].second!=0)std::cout<<Strumienie::indeks(vec[i].second, 5)<<Strumienie::colon<<vec[i].first<<Strumienie::endline;
    }


}