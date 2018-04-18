#ifndef CPP_MATRIX_HPP
#define CPP_MATRIX_HPP

#include "Except.hpp"

namespace obliczenia {
    class Matrix {
    private:
        double **M;
        int n = 0;
        int m = 0;
    public:
        Matrix(int n);

        Matrix(int n, int m);

        Matrix(const Matrix &matrix);

        Matrix(Matrix &&matrix) noexcept;

        ~Matrix();

    public:
        Matrix &operator=(const Matrix &matrix);

        Matrix &operator=(Matrix &&matrix) noexcept;

        friend std::istream &operator>>(std::istream &we, Matrix &x);

        friend std::ostream &operator<<(std::ostream &wy, const Matrix &x);

        friend Matrix operator+(const Matrix &x, const Matrix &y) throw(DiferentSize);

        Matrix &operator+=(const Matrix &y) throw(DiferentSize);

        friend Matrix operator*(const Matrix &x, const Matrix &y) throw(DiferentSize);

        Matrix &operator*=(const Matrix &y)throw(DiferentSize);

        friend Matrix operator*(const Matrix &x, const double &skalar) throw(Skalar0);

        Matrix &operator*=(const double &skalar)  throw(Skalar0);

        friend Matrix operator-(const Matrix &x, const Matrix &y) throw(DiferentSize);

        Matrix &operator-=(const Matrix &y) throw(DiferentSize);
        Matrix & operator-(const Matrix &y) throw(NotDefined);

    public:
        void swapRows(int r1, int r2)throw(DiferentSize);

        void multiplyRow(int r1, double mult) throw(DiferentSize, Skalar0);

        void addMultRowToRow(int r1, int r2, double mult)  throw(DiferentSize, Skalar0);

        void swapColumns(int c1, int c2)  throw(DiferentSize);

        void multiplyColumn(int c1, double mult) throw(DiferentSize, Skalar0);

        void addMultColumnToColumn(int c1, int c2, double mult) throw(DiferentSize, Skalar0);

    private:
        Matrix *remove(int col, int row  )throw(DiferentSize);

    public:
        Matrix *rev() throw(NotDefined);
        double det() throw(NotDefined);
    };

}
#endif //CPP_MATRIX_HPP
