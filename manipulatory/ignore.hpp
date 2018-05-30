#ifndef CPP_IGNORE_HPP
#define CPP_IGNORE_HPP
#include "indeks.hpp"
namespace Strumienie {
    class ignore {
    public:
        int x;

        friend std::istream &operator>>(std::istream &is, ignore i);

    public:
        ignore(int x);
    };
}
#endif //CPP_IGNORE_HPP
