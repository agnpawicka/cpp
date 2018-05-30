#include "In.hpp"

In& operator>>(In &ini, int &a) {
    ini.file>>a;
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
