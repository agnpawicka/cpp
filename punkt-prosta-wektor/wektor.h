//
// Created by aga on 04.03.18.
//

#ifndef CPP_WEKTOR_H
#define CPP_WEKTOR_H

class  Wektor{
public:
    const double dx=0;
    const double dy=0;
    Wektor();
    Wektor(const  double &dx, const double &dy);
    Wektor(const Wektor & wektor);
    static  Wektor ZlozWektor(const Wektor & wektor1, const Wektor & wektor2);
    Wektor &operator=(const Wektor &) = delete;
    ~Wektor();
};

#endif //CPP_WEKTOR_H
