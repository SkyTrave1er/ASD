#pragma once
#include "../lib_matrix/matrix.h"


template <class T>
class Triangle_matrix;
template <class T>
std::ostream& operator<< (std::ostream& out, const Triangle_matrix<T>& obj);
template <class T>
std::istream& operator>> (std::istream& in, const Triangle_matrix<T>& obj);

template <class T>
class Triangle_matrix : public Matrix<T> {
private:
    size_t _N;
public:
    Triangle_matrix();
    Triangle_matrix(size_t N);
    Triangle_matrix(const Math_vector<Math_vector<T>>&);
    Triangle_matrix(const Triangle_matrix&);
    Triangle_matrix operator+(const Triangle_matrix& other);
    Triangle_matrix operator-(const Triangle_matrix& other);
    Triangle_matrix<T> operator*(T val);
    Math_vector<T> operator*(Math_vector<T> vec);
    Triangle_matrix<T> operator*(const Triangle_matrix<T>& matr);
    friend std::ostream& operator<< <T>(std::ostream& out, const Triangle_matrix<T>& obj);
    friend std::istream& operator>> <T>(std::istream& in, const Triangle_matrix<T>& obj);
};

template <class T>
Triangle_matrix<T>::Triangle_matrix() : _N(0), _data(nullptr) {}

template <class T>
Triangle_matrix<T>::Triangle_matrix(size_t N) : Math_vector<Math_vector<T>>(N) {
    for (size_t i = 0; i < N; i++) {
        _data[i] = new Math_vector<T>(N - i, i);
    }
}

template <class T>
Triangle_matrix<T>::Triangle_matrix(const Math_vector<Math_vector<T>>& other) : _N(0), _data(nullptr) {}

template <class T>
Triangle_matrix<T> Triangle_matrix<T>::operator*(T val) {
    return Matrix();
}

template <class T>
Triangle_matrix<T> Triangle_matrix<T>::operator+(const Triangle_matrix& other) {
    return Triangle_matrix<T>();
}

template <class T>
Triangle_matrix<T> Triangle_matrix<T>::operator-(const Triangle_matrix& other) {
    return Triangle_matrix();
}

template <class T>
Math_vector<T> Triangle_matrix<T>::operator*(Math_vector<T> vec) {
    return Math_vector<T>();
}

template <class T>
Triangle_matrix<T> Triangle_matrix<T>::operator*(const Triangle_matrix<T>& matr) {
    return Triangle_matrix<T>();
}

template <class T>
std::ostream& operator<< <T>(std::ostream& out, const Triangle_matrix<T>& obj) {
    return out;
}

template <class T>
std::istream& operator>>(std::istream& in, const Triangle_matrix<T>& obj) {
    return in;
}