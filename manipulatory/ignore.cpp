#include "ignore.hpp"

namespace Strumienie {
    std::basic_istream<char> &operator>>(std::istream &is, Strumienie::ignore i) {
        int a = i.x;
        while (a >= 0) {
            is.get();
            a--;
        }

        return is;
    }
}


Strumienie::ignore::ignore(int x) : x(x) {}