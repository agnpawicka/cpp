
#ifndef CPP_WYJATEK_WYMIERNY_HPP
#define CPP_WYJATEK_WYMIERNY_HPP

#include <iostream>
class wyjatek_wymierny : public std::exception{
public:
    virtual const char * what(){
        return "";
    }
};

class dzielenie_przez_0 : public wyjatek_wymierny{
public:
    const char * what() override {
        return "Nastąpiło dzielenie przez zero\n";
    }
};
class wyjscie_poza_zakres : public wyjatek_wymierny{
public:
    const char * what() override {
        return "Wyjście poza zakres\n";
    }
};

#endif //CPP_WYJATEK_WYMIERNY_HPP
