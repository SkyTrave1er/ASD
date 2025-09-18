#include "../lib_math_vector/math_vector.h"
#include "math.h"
#pragma once

template <class T>
class Matrix;
template <class T>
std::ostream& operator<< (std::ostream& out, const Matrix<T>& obj);
template <class T>
std::istream& operator>> (std::istream& in, const Matrix<T>& obj);

template <class T>
class Matrix : public Math_vector<Math_vector<T>> {
private:
    size_t _M, _N;
    const T* _data;
public:
    Matrix();
    Matrix(size_t M, size_t N);
    Matrix(const Math_vector<Math_vector<T>>&);
    Matrix(const Matrix&);
    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix<T> operator*(T val);
    Math_vector<T> operator*(Math_vector<T> vec);
    Matrix<T> operator*(const Matrix<T>& matr);
    friend std::ostream& operator<< <T>(std::ostream& out, const Matrix<T>& obj);
    friend std::istream& operator>> <T>(std::istream& in, const Matrix<T>& obj);
};

template <class T>
Matrix<T>::Matrix() : _M(0), _N(0), _data(nullptr) {}

template <class T>
Matrix<T>::Matrix(size_t M, size_t N) : _M(M), _N(N), _data(nullptr) {}

template <class T>
Matrix<T> Matrix<T>::operator*(T val) {
    /*Matrix<T> result(M, N);
    for (int i = 0; i < M; i++) {
        result[i] = (*this)[i] * val;
    }
    return result;*/
    return Matrix();
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) {
    //return this->Math_vector<Math_vector<T>>::operator+(other);
    return Matrix<T>();
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix& other) {
    return Matrix();
}

template <class T>
Math_vector<T> Matrix<T>::operator*(Math_vector<T> vec) {
    /*Math_vector<T> result(M);
    for (int i = 0; i < M; i++) {
        result[i] = (*this)[i] * vec;
    }
    return result;*/
    return Math_vector<T>();
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& matr) {
    /*Matrix<T> result(M, matr.N);
    Matrix<T> mart_t = mart.transp();

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < matr.N;j++) {
            result[i][j] = (*this)[i] * matr_t[j];
        }
    }
    return result;*/
    return Matrix<T>();
}

template <class T>
std::ostream& operator<< <T>(std::ostream& out, const Matrix<T>& obj) {
    return out;
}

template <class T>
std::istream& operator>>(std::istream& in, const Matrix<T>& obj) {
    return in;
}