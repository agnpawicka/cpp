#include "matrix.hpp"
using namespace obliczenia;
int main(){
    std::cout<<"Proszę wpisać macierz 3x3\n";
    auto mat=new Matrix(3);
    std::cin>>*mat;
    std::cout<<"Macierz tranponowana\n"<<(-(*mat));
    try {
        std::cout << "Wyznacznik " << mat->det() << "\n";
        std::cout << "Macierz odwrotna\n" << *mat->rev();
    } catch(std::exception &e){
        std::cout<<e.what();
    }
    auto mat2=new Matrix(3);
    try {
        std::cout<<"Pierwsza macierz+Id\n"<<*mat+*mat2;
    }
    catch(std::exception &e){
        std::cout<<e.what();
    }

    std::cout<<"Proszę wpisać drugą macierz 3x3\n";

    try {
        std::cin>>*mat2;
        std::cout<<"wpisano\n"<<*mat2;
        std::cout<<"Różnica macierzy\n"<<*mat-*mat2;
    }
    catch(std::exception &e){
        std::cout<<e.what();
    }


    try {
        ///testowanie operacjoi elementarnych kolumnowych,
        /// wierszowe testowane przy okazji obliczania macierzy odwrotnej oraz obliczania wyznacznika

        std::cout<<"Iloczyn\n"<<*mat**mat2;
        mat->swapColumns(1, 2);
        std::cout<<"pierwsza macierz z zamienionymi 0. i 2-gą kolumną\n"<<*(mat);
        mat->multiplyColumn(0, 2);
        std::cout<<"pierwsza macierz z 0-wą kolumną przemnożoną prze 2\n"<<*(mat);
        mat->addMultColumnToColumn(2, 0, 0.5);
        std::cout<<"pierwsza macierz, do 2-giej kolumny dodano 1/2*0-wą\n"<<*mat;

    }
    catch(std::exception &e){
        std::cout<<e.what();
    }

    delete mat;
    delete mat2;



}