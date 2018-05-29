
#include "bst.hpp"


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
    this->leftSon= nullptr;
    this->rightSon= nullptr;
}

template<typename T, class cmp>
Struktury::Bst<T, cmp>::node::~node() {
    if (leftSon != nullptr) delete leftSon;
    if (rightSon != nullptr) delete rightSon;
    //leftSon = nullptr;
    //rightSon = nullptr;
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
        if(top== nullptr) top=new node((it));
        else    insideInsert(top, (it));
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

template<typename T, class cmp>
void Struktury::Bst<T, cmp>::insert(T elem) {
    if(top== nullptr) top=new node(elem);
    else    insideInsert(top, elem);
}

template<typename T, class cmp>
void Struktury::Bst<T, cmp>::erase(T elem) {
    if (top== nullptr) throw std::logic_error("elementu do usunięcia nie ma w drzewie");
    if(cmp()(top->var,elem) and cmp()(elem, top->var)){
        if(top->leftSon== nullptr) top=top->rightSon;
        else if(top->rightSon== nullptr) top=top->leftSon;
        else{
            auto l=top->leftSon;
            auto r=top->rightSon;
            if(l->rightSon== nullptr){
                l->rightSon=r;
                top=l;
                return;
            }
            if(r->leftSon== nullptr){
                r->leftSon=l->rightSon;
                l->rightSon=r;
                top=l;
                return;
            }
            auto ll=l->rightSon;
            l->rightSon=r;
            top=l;
            while(r->leftSon!= nullptr)r=r->leftSon;
            r->leftSon=ll;
            return;
        }
    }
    else insideErase(top, elem);
}

template<typename T, class cmp>
bool Struktury::Bst<T, cmp>::search(T elem) {
    bool x = insideSearch(top, elem);
    return x;
}

template<typename T, class cmp>
void Struktury::Bst<T, cmp>::insideInsert(Struktury::Bst<T, cmp>::node *current,  T elem) {
    if (current == nullptr)throw std::exception();
    else if (cmp()(current->var, elem) and cmp()(elem, current->var)) throw std::logic_error("element do wstawienia już jest w drzewie");
    else if (cmp()(current->var, elem)){
        if(current->rightSon== nullptr){
            current->rightSon=new node(elem);
        }
        else insideInsert(current->rightSon, elem);
    }
    else {
        if(current->leftSon== nullptr){
            current->leftSon=new node(elem);
        }
        else
            insideInsert(current->leftSon, elem);
    }
}

template<typename T, class cmp>
bool Struktury::Bst<T, cmp>::insideSearch(const Struktury::Bst<T, cmp>::node *current, T elem) {
    if (current == nullptr) return false;
    else if (cmp()(current->var, elem) and cmp()(elem, current->var)) return true;
    else if (cmp()(current->var, elem)) return  insideSearch(current->rightSon, elem);
    else return insideSearch(current->leftSon, elem);
}

template<typename T, class cmp>
void Struktury::Bst<T, cmp>::insideErase(Struktury::Bst<T, cmp>::node *current,  T elem) {
    if (current == nullptr) throw std::logic_error("elementu do usunięcia nie ma w drzewie");
    else if (cmp()(current->var, elem)){//jeśli coś z prawego poddrzewa:
        if(current->rightSon== nullptr) throw std::logic_error("elementu do usunięcia nie ma w drzewie");
        if(cmp()(current->rightSon->var, elem) and cmp()(elem, current->rightSon->var)){
            if(current->rightSon->leftSon== nullptr){
                current->rightSon=current->rightSon->rightSon;
                return;
            }
            if(current->rightSon->rightSon== nullptr){
                current->rightSon=current->rightSon->leftSon;
                return;
            }
            auto l=current->rightSon->leftSon;
            auto r=current->rightSon->rightSon;
            if(l->rightSon== nullptr){
                l->rightSon=r;
                current->rightSon=l;
                return;
            }
            if(r->leftSon== nullptr){
                r->leftSon=l->rightSon;
                l->rightSon=r;
                current->rightSon=l;
                return;
            }
            auto ll=l->rightSon;
            l->rightSon=r;
            current->rightSon=l;
            while(r->leftSon!= nullptr)r=r->leftSon;
            r->leftSon=ll;
            return;

        }else insideErase(current->rightSon, elem);
    }
    else {
        if(current->leftSon== nullptr) throw std::logic_error("elementu do usunięcia nie ma w drzewie");;
        if(cmp()(current->leftSon->var, elem) and cmp()(elem, current->leftSon->var)){
            if(current->leftSon->leftSon== nullptr){
                current->leftSon=current->leftSon->rightSon;
                return;
            }
            if(current->leftSon->rightSon== nullptr){
                current->leftSon=current->leftSon->leftSon;
                return;
            }
            auto l=current->leftSon->leftSon;
            auto r=current->leftSon->rightSon;
            if(l->rightSon== nullptr){
                l->rightSon=r;
                current->leftSon=l;
                return;
            }
            if(r->leftSon== nullptr){
                r->leftSon=l->rightSon;
                l->rightSon=r;
                current->leftSon=l;
                return;
            }
            auto ll=l->rightSon;
            l->rightSon=r;
            current->leftSon=l;
            while(r->leftSon!= nullptr)r=r->leftSon;
            r->leftSon=ll;
            return;

        }else insideErase(current->rightSon, elem);
    }
}


