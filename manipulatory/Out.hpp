#ifndef CPP_OUT_HPP
#define CPP_OUT_HPP

#include <fstream>

class Out{
public:
    std::ofstream file;
public:
    friend Out& operator<<( Out &o, const int &a);
    Out(std::string name);
    ~Out();
};
#endif //CPP_OUT_HPP
