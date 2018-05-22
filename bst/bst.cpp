
#include "bst.hpp"

template <typename T, class cmp> std::ostream& operator<< (std::ostream &, const Struktury::Bst<T, cmp> &);


///funkcje klasy node
template<typename T, class cmp>
Struktury::Bst<T, cmp>::node::node(Struktury::Bst<T, cmp>::node *N) {
    this->var = N->var;
    if (N->leftSon != nullptr) this->leftSon = new node(N->leftSon);
    if (N->rightSon != nullptr) this->rightSon = new node(N->rightSon);
}

template<typename T, class cmp>
Struktury::Bst<T, cmp>::node::node(T var) {
    this->var = var;
}

template<typename T, class cmp>
Struktury::Bst<T, cmp>::node::~node() {
    if (leftSon != nullptr) delete leftSon;
    if (rightSon != nullptr) delete rightSon;
    leftSon = nullptr;
    rightSon = nullptr;
}

///definicja drugiego komparatora

template<typename T, class cmp>
bool Struktury::Bst<T, cmp>::sndCmp(const T &a,const  T &b) {
    if(cmp(a, b)){
        if (cmp(b ,a)) return true;
        return false;
    }
    return true;
}

///konstruktory i destruktor


template<typename T, class cmp>///tylko do operatora <<, kontruktor prywatny
Struktury::Bst<T, cmp>::Bst(Struktury::Bst<T, cmp>::node *N) {
    this->top=N;
}


template<typename T, class cmp>
::Struktury::Bst<T, cmp>::Bst(Bst<T, cmp> &bst) {
    this->top = bst.top;
}

template<typename T, class cmp>
::Struktury::Bst<T, cmp>::Bst(Struktury::Bst<T, cmp> &&bst) noexcept {
    this->top = bst.top;
    bst.top = nullptr;
}

template<typename T, class cmp>
::Struktury::Bst<T, cmp>::Bst(std::initializer_list<T> l) {
    for (auto it : l){
        insideInsert(top, (it));
    }
}


template<typename T, class cmp>
::Struktury::Bst<T, cmp>::~Bst() {
    delete top;
}

/// Przeciążone operatory

template<typename T, class cmp>
Struktury::Bst<T, cmp> &Struktury::Bst<T, cmp>::operator=(const Struktury::Bst<T, cmp> &bst) {
    if (this == &bst) return *this;
    delete this->top;
    top = new node(bst.top);
    return *this;
}

template<typename T, class cmp>
Struktury::Bst<T, cmp> &Struktury::Bst<T, cmp>::operator=(Struktury::Bst<T, cmp> &&bst) noexcept {
    delete this->top;
    this->top = bst.top;
    bst.top = nullptr;
    return *this;
}

template<typename T, class cmp> std::ostream &operator<<(std::ostream &wy, const Struktury::Bst<T, cmp> &bst){

    return wy;
}

template<typename T, class cmp>
void Struktury::Bst<T, cmp>::insert(T elem) {
    insideInsert(top, elem);
}

template<typename T, class cmp>
void Struktury::Bst<T, cmp>::erase(T elem) {
    insideErase(top, elem);
}

template<typename T, class cmp>
bool Struktury::Bst<T, cmp>::search(T elem) {
    return insideSearch(top, elem);
}

template<typename T, class cmp>
void Struktury::Bst<T, cmp>::insideInsert(Struktury::Bst<T, cmp>::node *current, const T &elem) {
    if (current == nullptr) current = &elem;
    else if (cmp(current->var, elem) and cmp(top, current->var)) throw std::exception();
    else if (cmp(current->var, elem)) insideInsert(current->rightSon, elem);
    else insideInsert(current->leftSon, elem);
}

template<typename T, class cmp>
bool Struktury::Bst<T, cmp>::insideSearch(const Struktury::Bst<T, cmp>::node *current, const T &elem) {
    if (current == nullptr) return false;
    else if (cmp(current->var, elem) and cmp(top, current->var)) return true;
    else if (cmp(current->var, elem)) insideSearch(current->rightSon, elem);
    else insideSearch(current->leftSon, elem);
}

template<typename T, class cmp>
void Struktury::Bst<T, cmp>::insideErase(Struktury::Bst<T, cmp>::node *current, const T &elem) {
    if (current == nullptr) throw std::exception();
    else if (cmp(current->var, elem) and cmp(top, current->var)){
        //uzupełnić ensownie jakos
    }
    else if (cmp(current->var, elem)) insideErase(current->rightSon, elem);
    else insideErase(current->leftSon, elem);
}


