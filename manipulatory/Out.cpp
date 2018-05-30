#include <netinet/in.h>
#include "Out.hpp"


Out::Out(std::string name) {
    try {
        file.open(name, std::ofstream::out | std::ofstream::binary);
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

Out &operator<<(Out &o, const int &a) {
    try{
        o.file.write((char*)&a, 1);
    }
    catch (std::ofstream::failure &e){
        throw e;
    }
    return o;
}
