
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
int main(){
    /*std::string a, b;
    std::cin>>Strumienie::clearline>>a>>b;
    std::cout<<a<<" "<<b<<" ";
    std::cout << "x"<<Strumienie::colon<<"123123"<<Strumienie::comma <<"123"<<Strumienie::endline;
    std::cout<<Strumienie::indeks(123, 5)<<Strumienie::endline<<Strumienie::indeks(7, 5);
    std::cin >> Strumienie::ignore(5)>>a;
    std::cout<<a<<Strumienie::endline;*/

//    std::vector<psi> vec;
//    int num=1;
//    std::string s;
//    while (getline(std::cin, s)){
//        vec.emplace_back(psi(s, num++));
//    }
//    std::sort(vec.begin(), vec.end());
//    for(int i=0; i<num; i++){
//        std::cout<<Strumienie::indeks(vec[i].second, 5)<<Strumienie::colon<<vec[i].first<<Strumienie::endline;
//    }

    std::string aa="sialala";
    std::string bb="";
    char c;
    try {
        auto wyj = new Out("name");
        for(int i=0; i<aa.size(); i++) {
            (*wyj).file << aa[i];
        }
        delete wyj;
    }
    catch (std::ofstream::failure &e){

    }
    try {
        auto wej = new In("name");
        for(int i=0; i<aa.size(); i++) {
            (*wej).file >> c;
            bb.push_back(c);
        }
        delete wej;
    }catch (std::ifstream::failure &e){

    }
    std::cout<<"a"<<Strumienie::colon<<aa<<Strumienie::endline<<"b"<<Strumienie::colon<<bb<<Strumienie::endline;

}