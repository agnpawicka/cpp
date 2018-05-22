
#ifndef CPP_BST_HPP
#define CPP_BST_HPP

#include <iostream>

namespace Struktury {
    template<typename T, class cmp=std::greater<T>>
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
        };

        node *top = nullptr;

        bool sndCmp(const T &a, const T &b);

        Bst(node *N);

    public:
        Bst() = default;

        Bst(Bst &bst);

        Bst(Bst &&bst) noexcept;

        Bst(std::initializer_list<T> l);

        ~Bst();

          Bst&operator=(const Bst &bst);
          Bst&operator=(Bst &&bst) noexcept ;
          friend std::ostream &operator<< <> (std::ostream &, const Bst<T, cmp> &);
          void insert(T elem);
          void erase(T elem);
          bool search(T elem);

      private:
          void insideInsert(node *current, const T &elem);

          bool insideSearch(const node *current, const T &elem);

          void insideErase(node *current, const T &elem);

    };

};
#endif //CPP_BST_HPP