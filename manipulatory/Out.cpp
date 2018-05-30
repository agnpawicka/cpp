#include <netinet/in.h>
#include "Out.hpp"


Out::Out(std::string name) {
    try {
        file.open(name, std::ofstream::out | std::ofstream::app);
    }
    catch (const std::ofstream::failure &e) {
        throw e;
    }
}

Out::~Out(){
    file.close();
    if(file.is_open()){
        throw std::exception();
    }
}

Out &operator<<(Out &o, const char &a) {
    o.file<<a;
    return o;
}
