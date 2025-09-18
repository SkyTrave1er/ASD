#include "../lib_vector/vector.h"
#pragma once

template <class T>
class Math_vector;
template <class T>
std::ostream& operator<< (std::ostream& out, const Math_vector<T>& obj);
template <class T>
std::istream& operator>> (std::istream& in, const Math_vector<T>& obj);

template <class T>

class Math_vector : private TVector<T> {
private:
    size_t start_index;
public:
    Math_vector();
    Math_vector(size_t size);
    Math_vector<T> operator+(Math_vector<T> vec);
    Math_vector<T> operator-(Math_vector<T> vec);
    Math_vector<T> operator*(T val);
    T operator*(Math_vector<T> vec);
    friend std::ostream& operator<< <T>(std::ostream& out, const Math_vector<T>& obj);
    friend std::istream& operator>> <T>(std::istream& in, const Math_vector<T>& obj);
};

template <class T>
Math_vector<T>::Math_vector() : TVector() {}

template <class T>
Math_vector<T>::Math_vector(size_t size) : TVector(size) {}

template <class T>
Math_vector<T> Math_vector<T>::operator+(Math_vector<T> vec) {
    /*Math_vector<T> result(size);
    for (int i = 0; i < _size; i++) {
        result[i] = (*this)[i] + vec[i];
    }
    return result;*/
    return Math_vector();
}

template <class T>
Math_vector<T> Math_vector<T>::operator-(Math_vector<T> vec) {
    return Math_vector();
}

template <class T>
Math_vector<T> Math_vector<T>::operator*(T val) {
    /*Math_vector<T> result(size);
    for (int i = 0; i < _size; i++) {
        result[i] = (*this)[i] * val;
    }
    return result;*/
    return Math_vector();
}

template <class T>
T Math_vector<T>::operator*(Math_vector<T> vec) {
    /*T result = T();
    for (i = 0; i < _size; i++) {
        result += (*this)[i] * vec[i];
    }
    return result;*/
    return T();
}

template <class T>
std::ostream& operator<< <T>(std::ostream& out, const Math_vector<T>& obj) {
    return out;
}

template <class T>
std::istream& operator>>(std::istream& in, const Math_vector<T>& obj) {
    return in;
}