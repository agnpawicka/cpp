#ifndef CPP_INDEKS_HPP
#define CPP_INDEKS_HPP

#include <iostream>
namespace Strumienie {
    class indeks {
    public:
        int x;
        int spacje;

        friend std::ostream &operator<<(std::ostream &os, const indeks &i);

    public:
        indeks(int x, int w);
    };
}
#endif //CPP_INDEKS_HPP
