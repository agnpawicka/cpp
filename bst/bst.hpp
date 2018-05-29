
#ifndef CPP_BST_HPP
#define CPP_BST_HPP

#include <iostream>
#include <functional>

namespace Struktury {
    template<typename T, class cmp=std::less_equal<T>>
    class Bst {
    private:
        class node {
        public:
            T var;
            node *leftSon = nullptr;
            node *rightSon = nullptr;

            node(T var);

            node(node *N);

            ~node();
            friend std::ostream &operator<< (std::ostream &out,  node* n){
                if(n->leftSon!= nullptr) out<<n->leftSon<<" ";
                out<<n->var;
                if(n->rightSon!= nullptr) out<<" "<<n->rightSon;
                return out;
            }
        };

        node *top = nullptr;

        Bst(node *N);

    public:
        Bst(){

        };

        Bst(Bst &bst);

        Bst(Bst &&bst) noexcept;

        Bst(std::initializer_list<T> l);

        ~Bst();

          Bst&operator=(const Bst &bst);
          Bst&operator=(Bst &&bst) noexcept ;
          friend std::ostream &operator<< (std::ostream &out, const Bst<T, cmp> &bst){
              if (bst.top!= nullptr){
                  out << bst.top;
              }
              return out;
          }
          void insert(T elem);
          void erase(T elem);
          bool search(T elem);

      private:
          void insideInsert(node *current, T elem);

          bool insideSearch(const node *current,  T elem);

          void insideErase(node *current,  T elem);

    };


};
#endif //CPP_BST_HPP