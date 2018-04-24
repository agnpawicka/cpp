#include <iostream>
#include "wymierna.hpp"
using namespace obliczenia;
int main(){
    auto w=new Wymierna(5, 2);
    auto z=new Wymierna(4);
    auto x= *w+*z;
    std::cout<<*w<<" + "<<*z<<" = "<<(*w)+(*z)<<"\n";
    std::cout<<*w<<" - "<<*z<<" = "<<*w-*z<<"\n";
    std::cout<<*w<<" * "<<*z<<" = "<<*w**z<<"\n";
    std::cout<<*w<<" / "<<*z<<" = "<<*w/(*z)<<"\n";
    std::cout<<"-"<<*w<<" = "<<-*w<<"\n";
    std::cout<<"1/"<<*w<<" = "<<!*w<<"\n";
    int a=x;
    int b=(int)x;

    std::cout<<a<<" "<<b<<"\n";

    ///testowanie wyjątków::
    auto x1 = new Wymierna(1, INT32_MAX);
    auto x2= new Wymierna(1, 1<<15);




    ///ułamki okresowe
    auto a1=new Wymierna(1, 9);
    std::cout<<*a1<<"\n";
    auto a2=new Wymierna(4, 30);
    std::cout<<*a2;
    std::cout<<"1/2^15 + 1/MAXINT"<<*x1+*x2<<"\n";
}