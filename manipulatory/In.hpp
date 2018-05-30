
#ifndef CPP_IN_HPP
#define CPP_IN_HPP

#include <fstream>

class In{
public:
    std::ifstream file;
public:
    friend In& operator>>(In &ini, int& a);
    In(std::string name);
    ~In();
};
#endif //CPP_IN_HPP
