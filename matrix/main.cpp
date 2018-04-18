#include "matrix.hpp"
using namespace obliczenia;
int main(){
    std::cout<<"Proszę wpisać macierz 3x3\n";
    auto mat=new Matrix(3);
    std::cin>>*mat;
    std::cout<<"Macierz tranponowana\n"<<(-(*mat));
    std::cout<<"Wyznacznik "<<mat->det();
    std::cout<<"Macierz odwrotna\n"<<*mat->rev();
    auto mat2=new Matrix(3);
    std::cout<<"Pierwsza macierz+Id\n"<<*mat+*mat2;
    std::cout<<"Proszę wpisać drugą macierz 3x3\n";

   // std::cin>>





}