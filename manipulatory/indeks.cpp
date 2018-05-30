#include "indeks.hpp"
namespace Strumienie {
    std::ostream &operator<<(std::ostream &os, const indeks &i) {
        os << '[';
        int a = i.spacje;
        while (a > 0) {
            os << " ";
            a--;
        }
        os << i.x;
        os << "]";
        return os;
    }
}

Strumienie::indeks::indeks(int x, int w) :x(x) {
    int a=std::abs(x);
    spacje=w-1;
    while (a>9){
        spacje--;
        a/=10;
    }
    if (x<0) spacje--;
}
