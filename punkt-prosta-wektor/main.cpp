#include <iostream>
#include "prosta.h"

int main() {
    auto *p1 = new Punkt(1.0, 1.0);
    auto *p2 = new Punkt(*p1);
    auto *w1 = new Wektor(2.0, 7.0);
    auto *p3 = new Punkt(*p2, *w1);
    auto *w2 = new Wektor(*w1);
    auto w12 = Wektor::ZlozWektor(*w1, *w2);
    auto *p0 = new Punkt();
    auto *w0 = new Wektor();

    std::cout << "p1 " << p1->x << " " << p1->y << " " << "p2 " << p2->x << " " << p2->y << " " << "p3 " << p3->x << " "
              << p3->y << "\n";

    std::cout << "w1 " << w1->dx << " " << w1->dy << " " << "w2 " << w2->dx << " " << w2->dy << " " << "w12 " << w12.dx
              << " " << w12.dy << "\n";

    try {
        auto *sl1 = new Prosta(*p1, *p3);
        auto *sl2 = new Prosta(*w1);

        std::cout << sl2->WektorRownoleglDoProstej(*w1) << " ";
        std::cout << sl2->WektorProstodadlyDoProstej(*w1) << "\n";


        std::cout << sl1->odlegloscPunktuOdProstej(*p1) << " odleglosc punktu na prostej od prostej\n";
        std::cout << sl1->punktNaProstej(*p1) << " czy punkt na prostej jest na prostej\n";
        std::cout << sl2->odlegloscPunktuOdProstej(*p1) << " odleglosc punktu poza prostą od prostej\n";
        std::cout << sl2->punktNaProstej(*p1) << " czy punkt poza prostą jest na prostej\n";


        std::cout << Prosta::ProsteRownolegle(*sl1, *sl2) << " ";
        std::cout << Prosta::ProsteProstopadle(*sl1, *sl2) << " \n";
        auto *p4 = new Punkt(Prosta::PunktPrzeciecia(*sl1, *sl2));
        std::cout << p4->x << " " << p4->y << " punkt przeciecia\n";
        auto *sl3 = new Prosta(sl1->getA(), sl1->getB(), sl1->getC());
        std::cout << Prosta::ProsteRownolegle(*sl1, *sl3) << " ";
        std::cout << Prosta::ProsteProstopadle(*sl1, *sl3) << "\n";
        auto *sl4 = new Prosta(*sl1, *w2);

        std::cout << "sl1 " << sl1->getA() << " " << sl1->getB() << " " << sl1->getC() << "\n";
        std::cout << "sl2 " << sl2->getA() << " " << sl2->getB() << " " << sl2->getC() << "\n";
        std::cout << "sl3 " << sl3->getA() << " " << sl3->getB() << " " << sl3->getC() << "\n";
        std::cout << "sl4 " << sl4->getA() << " " << sl4->getB() << " " << sl4->getC() << "\n";

        auto *sl5 = new Prosta(*p1, *p2);

    }
    catch (const std::exception &e) {
        std::cout << e.what() << " z 2 identycznych punktów\n";
    }

    try {
        auto *sl6 = new Prosta(0, 0, 1);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << " \n";
    }

    try {
        auto *w4 = new Wektor(0, 0);
        auto *sl7 = new Prosta(*w4);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << "  z wektora zero\n";
    }


    return 0;
}