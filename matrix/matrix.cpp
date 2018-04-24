#include <exception>
#include <algorithm>
#include "matrix.hpp"

namespace obliczenia {
    Matrix::Matrix(int n) {
        this->n = n;
        m = n;
        M = new double *[n];
        for (int i = 0; i < n; i++) {
            M[i] = new double[n];
            for (int j = 0; j < n; j++) {
                M[i][j] = 0;
            }
            M[i][i] = 1;
        }
    }

    Matrix::Matrix(int n, int m) {
        this->n = n;
        this->m = m;
        M = new double *[n];
        for (int i = 0; i < n; i++) {
            M[i] = new double[m];
            for (int j = 0; j < m; j++) M[i][j] = 0;
        }
    }

    Matrix::Matrix(const Matrix &matrix) {
        n = matrix.n;
        m = matrix.m;
        M = new double *[n];
        for (int i = 0; i < n; i++) {
            M[i] = new double[m];
            for (int j = 0; j < m; j++) M[i][j] = matrix.M[i][j];
        }
    }

    Matrix::Matrix(Matrix &&matrix) noexcept {
        M = matrix.M;
        m = matrix.m;
        n = matrix.n;
        matrix.M = nullptr;
    }

    Matrix::~Matrix() {
        if(this!= nullptr) {
            for (int i = 0; i < n; i++) delete[] M[i];
            delete[] M;
        }
    }

    Matrix &Matrix::operator=(const Matrix &matrix) {
        if (this == &matrix) return *this;
        for (int i = 0; i < n; i++) {
            delete[] M[i];
        }
        delete[] M;
        n = matrix.n;
        m = matrix.m;
        M = new double *[n];
        for (int i = 0; i < n; i++) {
            M[i] = new double[m];
            for (int j = 0; j < m; j++) M[i][j] = matrix.M[i][j];
        }
        return *this;
    }

    Matrix &Matrix::operator=(Matrix &&matrix) noexcept {
        std::swap(this->M, matrix.M);
        delete matrix;
        /*
        for (int i = 0; i < n; i++) {

            delete[] M[i];
        }
        delete[] M;
        M = matrix.M;
        m = matrix.m;
        n = matrix.n;
        matrix.M = nullptr;*/
        return *this;
    }

    Matrix &Matrix::operator+=(const Matrix &y) throw(DiferentSize){
        if (n != y.n or m != y.m) throw DiferentSize();
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) M[i][j] += y.M[i][j];
        return *this;
    }

    Matrix operator+(const Matrix &x, const Matrix &y)throw(DiferentSize) {
        if (x.n != y.n or x.m != y.m) throw DiferentSize();
        auto nowe = new Matrix(x);
        (*nowe) += y;
        return *nowe;
    }

    Matrix &Matrix::operator*=(const double &skalar) {
       // if (skalar == 0) throw Skalar0();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                M[i][j] *= skalar;
            }
        return *this;
    }

    Matrix operator*(const Matrix &x, const double &skalar)  {
        if (skalar == 0) throw Skalar0();
        auto nowe = new Matrix(x);
        (*nowe) *= skalar;
        return *nowe;
    }

    Matrix &Matrix::operator-=(const Matrix &y) throw(DiferentSize){
        if (n != y.n or m != y.m) throw DiferentSize();
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) M[i][j] -= y.M[i][j];
        return *this;
    }

    Matrix operator-(const Matrix &x, const Matrix &y)throw(DiferentSize) {
        if (x.n != y.n or x.m != y.m) throw DiferentSize();
        auto nowe = new Matrix(x);
        (*nowe) -= y;
        return *nowe;
    }

    Matrix &Matrix::operator*=(const Matrix &y)throw(DiferentSize) {
        if (m != y.n) throw DiferentSize();
        double **nowe = new double *[n];
        for (int i = 0; i < n; i++)nowe[i] = new double[y.m];

        double obliczane = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < y.m; j++) {
                obliczane = 0.0;
                for (int k = 0; k < m; k++) obliczane += M[i][k] * y.M[k][j];
                nowe[i][j] = obliczane;
            }
        }
        for (int i = 0; i < n; i++) delete[] M[i];
        delete[] M;
        M = nowe;
        return *this;
    }

    Matrix operator*(const Matrix &x, const Matrix &y)throw(DiferentSize) {
        if (x.m != y.n) throw DiferentSize();
        auto nowe = new Matrix(x.n, y.m);
        for (int i = 0; i < x.n; i++) {
            for (int j = 0; j < std::min(y.m, x.m); j++) {
                nowe->M[i][j] = x.M[i][j];
            }
        }
        *nowe *= y;
        return *nowe;
    }

Matrix &Matrix::operator-() {
    auto T= new Matrix(m, n);
    for(int i=0; i<T->n; i++) for(int j=0; j<T->m; j++){
            T->M[i][j]=M[j][i];
        }
    return *T;
}


    void Matrix::swapRows(int r1, int r2) throw(DiferentSize){
        if (r1 >= n or r1 < 0 or r2 >= n or r2 < 0) throw DiferentSize();
        else std::swap(M[r1], M[r2]);
    }

    void Matrix::multiplyRow(int r1, double mult) throw(DiferentSize, Skalar0){
        if (r1 < 0 or r1 >= n) throw DiferentSize();
        if (mult == 0.0 or mult == -0.0) throw Skalar0();
        for (int i = 0; i < m; i++) M[r1][i] *= mult;
    }

    void Matrix::addMultRowToRow(int r1, int r2, double mult) throw(DiferentSize, Skalar0){
        if (r1 >= n or r1 < 0 or r2 >= n or r2 < 0) throw DiferentSize();
        if (mult == 0.0 or mult == -0.0) throw Skalar0();
        for (int i = 0; i < m; i++) M[r1][i] += M[r2][i] * mult;
    }

    void Matrix::swapColumns(int c1, int c2) throw(DiferentSize){
        if (c1 >= m or c1 < 0 or c2 >= m or c2 < 0) throw DiferentSize();
        for (int i = 0; i < n; i++) std::swap(M[i][c1], M[i][c2]);
    }

    void Matrix::multiplyColumn(int c1, double mult) throw(DiferentSize, Skalar0){
        if (c1 < 0 or c1 >= m) throw DiferentSize();
        if (mult == 0.0 or mult == -0.0) throw Skalar0();
        for (int i = 0; i < n; i++) M[i][c1] *= mult;
    }

    void Matrix::addMultColumnToColumn(int c1, int c2, double mult) throw(DiferentSize, Skalar0){
        if (c1 >= m or c1 < 0 or c2 >= m or c2 < 0) throw DiferentSize();
        if (mult == 0.0 or mult == -0.0) throw Skalar0();
        for (int i = 0; i < n; i++) M[i][c1] += M[i][c2] * mult;
    }

    Matrix *Matrix::remove(int col, int row) throw(DiferentSize){
        if (col < 0 or row < 0 or col >= m or row >= n) throw DiferentSize();
        auto nowe = new Matrix(n - 1, m - 1);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) nowe->M[i][j] = M[i][j];
            for (int j = col + 1; j < m; j++) nowe->M[i][j - 1] = M[i][j];
        }
        for (int i = row + 1; i < n; i++) {
            for (int j = 0; j < col; j++) nowe->M[i - 1][j] = M[i][j];
            for (int j = col + 1; j < m; j++) nowe->M[i - 1][j - 1] = M[i][j];
        }
        return nowe;
    }

    std::istream &operator>>(std::istream &we, Matrix &x) {

        for (int i = 0; i < x.n; i++) {
            for (int j = 0; j < x.m; j++) {
                we >> x.M[i][j];
            }
        }
        return we;
    }

    std::ostream &operator<<(std::ostream &wy, const Matrix &x) {
        for (int i = 0; i < x.n; i++) {
            for (int j = 0; j < x.m; j++) {
                wy << x.M[i][j] << " ";
            }
            wy << "\n";
        }
        return wy;
    }

    Matrix *Matrix::rev()throw(Undefined) {
        if (n != m or det()==0) throw Undefined();
        auto same= new Matrix(*this);
        auto reversed  = new Matrix(n);
        double mult;
        for(int i=0; i<n; i++){
            if(same->M[i][i]==0){
                for(int j=i+1; j<n; j++) if(M[j][i]!=0){
                        same->swapRows(j, i);
                        reversed->swapRows(j, i);
                        j=n;
                }
            }
            if(same->M[i][i]!=0) {
                for (int j = 0; j < n; j++)
                    if (j != i) {
                        mult = same->M[j][i] / same->M[i][i];
                        if (mult != 0.0 and mult != -0.0) {
                            same->addMultRowToRow(j, i, -mult);
                            reversed->addMultRowToRow(j, i, -mult);
                            //std::cout << "reversed\n" << *reversed;
                            //std::cout << "orginal\n" << *same;
                        }
                    }

                mult = 1 / same->M[i][i];
                same->multiplyRow(i, mult);
                reversed->multiplyRow(i, mult);


            }
        }
        delete same;
        return reversed;
    }

    double Matrix::det()throw(Undefined) {
        if (n != m) throw Undefined();
        auto same= new Matrix(*this);
        double mult;
        bool minus=0;
        for(int i=0; i<n; i++) {
            if (same->M[i][i] == 0) {
                for (int j = i+1; j < n; j++) if(j!=i)
                    if (M[j][i] != 0) {
                        same->swapRows(j, i);
                        minus ^= ((j - i) % 2);
                        //std::cout << "swaped\n" << *same;
                        j = n;
                    }
            }
            if (same->M[i][i] != 0) {
                for (int j = i + 1; j < n; j++) {
                    mult = same->M[j][i] / same->M[i][i];
                    if (mult != 0.0 and mult != -0.0) {
                        same->addMultRowToRow(j, i, -mult);
                        //std::cout << "sub\n" << *same;



                    }
                }
            }

        }
        double determine=1.0;
        for(int i=0; i<n; i++) determine*=same->M[i][i];
        if(minus)determine*=(-1);
        return determine;
    }


}