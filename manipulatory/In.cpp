#include "In.hpp"

In& operator>>(In &ini, int &a) {
    try{
        ini.file.read((char*)&a, 1);
        a=a&(127);
    }
    catch (std::ifstream::failure &e){
        throw e;
    }
    return ini;
}

In::In(std::string name) {
    try {
        file.open(name, std::ifstream::in | std::ifstream::binary );
    }
    catch (const std::ifstream::failure &e) {
        throw e;
    }
}

In::~In() {
    file.close();
    if(file.is_open()){
        throw std::exception();
    }
}
