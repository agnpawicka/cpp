#include <cstring>
#include "bst.hpp"
#include "bst.cpp"

class ConstCharStarComparator {
public:
    bool operator()(std::string s1, std::string s2) const {
        return s1<=s2;
    }
};
namespace Struktury {
    template<>
    class Bst<const char *> : public Bst<std::string, ConstCharStarComparator> {
    public:
        Bst() : Bst<std::string, ConstCharStarComparator>() {};

        Bst(std::initializer_list<const char *> list) : Bst<std::string, ConstCharStarComparator> (){
            for (auto elem : list)
                insert(elem);
        }



        void insert(const char * elem) {
            Bst<std::string, ConstCharStarComparator>::insert(std::string(elem));
        }

        void erase(const char * elem) {
            Bst<std::string, ConstCharStarComparator>::erase(std::string(elem));
        }

        bool search(const char * elem) {
            return Bst<std::string, ConstCharStarComparator>::search(std::string(elem));
        }

        friend std::ostream &operator<<(std::ostream &out, const Bst<const char *> &bst) {
            out << dynamic_cast<const Bst<std::string, ConstCharStarComparator>&>(bst);
            return out;
        }
    };
}

template<typename A>
class PointerCmp {
public:
    bool operator()(A *s1, A *s2) const {
        return *s1 <= *s2;
    }
};

int main() {
    ///testy konstruktorów, destruktorów, funkcji słownikowych bst
    auto n = new Struktury::Bst<int>();
    n->insert(2);
    n->insert(5);
    n->insert(1);
    std::cout << n->search(1) << n->search(2) << n->search(3) << n->search(4) << n->search(5) << "\n";
    std::cout << *n << "\n";
    n->erase(5);
    n->erase(2);

    std::cout << n->search(1) << n->search(2) << n->search(3) << n->search(4) << n->search(5) << "\n";
    std::cout << *n << "\n";
    delete n;
    auto in = new Struktury::Bst<int>({1, 5, 7, 3, 6, 2, 0});
    std::cout << in->search(5) << " " << in->search(4) << "\n";
    auto cop = *in;
    std::cout << cop.search(2);
    auto m = std::move(cop);
    std::cout << m.search(0) << "\n";
    delete in;
    ///test innego trejta
    auto mi = new Struktury::Bst<int, std::greater_equal<int> >();
    mi->insert(2);
    mi->insert(5);
    mi->insert(1);
    std::cout << *mi << "\n";
    delete mi;

    ///test dla wkaźników na int
    auto wsk = new Struktury::Bst<int *, PointerCmp<int> >();
    int a = 1;
    int b = 2;
    int c = 3;
    wsk->insert(&a);
    wsk->insert(&b);
    wsk->insert(&c);
    std::cout << wsk->search(&a) << "\n";
    wsk->erase(&a);
    std::cout << wsk->search(&a) << "\n";

    auto ws = new Struktury::Bst<char *, PointerCmp<char> >();
    char d = 'd';
    char e = 'e';
    char f = 'f';
    ws->insert(&d);
    ws->insert(&e);
    ws->insert(&f);
    std::cout << ws->search(&d) << "\n";
    ws->erase(&d);
    std::cout << ws->search(&d) << "\n";

    delete ws;

    /// test dla stringów:
    auto str = new Struktury::Bst<const char *, ConstCharStarComparator>({"ala", "ma", "kota"});
    std::cout << *str << "\n";
    str->insert("ajfj");
    std::cout << *str << "\n";
    str->erase("ajfj");
    std::cout << *str << "\n";
    std::cout
            << "Aby dodać słowo wpisz 1\nAby usunąc 2\nAby sprawdzić, czy jest w drzewie 3\nAby wypisać in-order 4\n";
    int i = 5;
    std::string sl;
    while (i != 0) {
        std::cin >> i;

        switch (i) {
            case 1:
                std::cout << "podaj słowo\n";
                std::cin >> sl;
                try {
                    str->insert(sl.c_str());
                }
                catch (const std::exception &e) {
                    std::cout << e.what();
                }
                break;
            case 2:
                std::cout << "podaj słowo\n";
                std::cin >> sl;
                try {
                    str->erase(sl.c_str());
                }
                catch (const std::exception &e) {
                    std::cout << e.what();
                }
                break;
            case 3:
                std::cout << "podaj słowo\n";
                std::cin >> sl;
            std::cout<<sl;
                try {
                    std::cout << "Wartość boolowska: " << str->search(sl.c_str()) << "\n";
                }
                catch (const std::exception &e) {
                    std::cout << e.what();
                }
                break;
            case 4:
                std::cout << *str << "\n";
                break;
            default:
                break;
        }
    }
    delete str;
    /// test trejta

    auto st = new Struktury::Bst<const char *>({"ala", "ma", "kota"});
    std::cout << *st << "\n";
    st->insert("ajfj");
    std::cout << *st << "\n";
    st->erase("ajfj");
    std::cout << *st << "\n";
    return 0;
}