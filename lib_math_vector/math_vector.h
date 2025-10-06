#include "../lib_vector/vector.h"
#pragma once

template <class T>
class Math_vector;
template <class T>
std::ostream& operator<< (std::ostream& out, Math_vector<T>& obj);
template <class T>
std::istream& operator>> (std::istream& in, Math_vector<T>& obj);

template <class T>

class Math_vector : public TVector<T> {
protected:
    size_t _start_index = 0;
public:
    Math_vector();
    Math_vector(size_t size);
    Math_vector(const T* arr, size_t n);
    Math_vector(const Math_vector<T>& other);
    Math_vector(size_t size, size_t start_index);
    size_t get_start_index() const;
    Math_vector<T> operator+(const Math_vector<T> vec);
    Math_vector<T> operator-(const Math_vector<T> vec);
    Math_vector<T> operator*(T val);
    T operator*(const Math_vector<T> vec);
    Math_vector<T>& operator-=(const Math_vector<T>& vec);
    Math_vector<T>& operator+=(const Math_vector<T>& vec);
    Math_vector<T>& operator*=(T val);
    Math_vector<T>& operator=(const Math_vector<T>& other);
    bool operator==(const Math_vector<T>& other) const;
    bool operator!=(const Math_vector<T>& other) const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    friend std::ostream& operator<< <T>(std::ostream& out, Math_vector<T>& obj);
    friend std::istream& operator>> <T>(std::istream& in, Math_vector<T>& obj);
};

template <class T>
Math_vector<T>::Math_vector() : _start_index(0), TVector<T>() {}

template <class T>
Math_vector<T>::Math_vector(size_t size) : _start_index(0), TVector<T>(size) {}

template <class T>
Math_vector<T>::Math_vector(const T* arr, size_t n) : _start_index(0), TVector<T>(arr, n) {}

template <class T>
Math_vector<T>::Math_vector(const Math_vector<T>& other) :
    TVector<T>(other), _start_index(other._start_index) {}

template <class T>
Math_vector<T>::Math_vector(size_t size, size_t start_index)
    : TVector<T>(size), _start_index(start_index) {}

template <class T>
size_t Math_vector<T>::get_start_index() const {
    return _start_index;
}

template <class T>
Math_vector<T> Math_vector<T>::operator+(const Math_vector<T> vec) {
    if (this->_size != vec._size || this->_start_index != vec._start_index) {
        throw std::invalid_argument("vectors must be the same size");
    }
    Math_vector<T> result(this->_size, this->_start_index);
    for (int i = 0; i < vec._size; i++) {
        //result[i] = (*this)[i] + vec[i];
        result._data[i] = this->_data[i] + vec._data[i];
    }
    return result;
}

template <class T>
Math_vector<T> Math_vector<T>::operator-(const Math_vector<T> vec) {
    if (this->_size != vec._size) {
        throw std::invalid_argument("vectors must be the same size");
    }
    Math_vector<T> result(this->_size, this->_start_index);
    for (int i = 0; i < vec._size; i++) {
        //result[i] = (*this)[i] - vec[i];
        result._data[i] = this->_data[i] - vec._data[i];
    }
    return result;
}

template <class T>
Math_vector<T> Math_vector<T>::operator*(T val) {
    Math_vector<T> result(this->_size, this->_start_index);
    for (int i = 0; i < this->_size; i++) {
        //result[i] = (*this)[i] * val;
        result._data[i] = this->_data[i] * val;
    }
    return result;
}

template <class T>
T Math_vector<T>::operator*(const Math_vector<T> vec) {
    if (this->_size != vec._size) {
        throw std::invalid_argument("vectors must be the same size");
    }
    T result = T();
    for (int i = 0; i < vec._size; i++) {
        result += (*this)[i] * vec[i];
    }
    return result;
}

template <class T>
Math_vector<T>& Math_vector<T>::operator+=(const Math_vector<T>& vec) {
    if (this->_size != vec._size) {
        throw std::invalid_argument("vectors must be the same size");
    }
    for (size_t i = 0; i < this->_size; i++) {
        (*this)[i] += vec[i];
    }
    return *this;
}

template <class T>
Math_vector<T>& Math_vector<T>::operator-=(const Math_vector<T>& vec) {
    if (this->_size != vec._size) {
        throw std::invalid_argument("vectors must be the same size");
    }
    for (size_t i = 0; i < this->_size; i++) {
        (*this)[i] -= vec[i];
    }
    return *this;
}

template <class T>
Math_vector<T>& Math_vector<T>::operator*=(T val) {
    for (size_t i = 0; i < this->_size; i++) {
        (*this)[i] *= val;
    }
    return *this;
}

template <class T>
Math_vector<T>& Math_vector<T>::operator=(const Math_vector<T>& other) {
    TVector<T>::operator=(other);
    this->_start_index = other._start_index;
    return *this;
}

template <class T>
bool Math_vector<T>::operator==(const Math_vector<T>& other) const {
    if (this->_size != other._size) return false;
    for (size_t i = 0; i < this->_size; i++) {
        if ((*this)[i] != other[i]) return false;
    }
    return true;
}

template <class T>
bool Math_vector<T>::operator!=(const Math_vector<T>& other) const {
    return !(*this == other);
}

template <class T>
T& Math_vector<T>::operator[](size_t index) {
    if (index - _start_index < 0) {
        throw std::invalid_argument("start_index can't be > index");
    }
    return _data[index - _start_index];
}

template <class T>
const T& Math_vector<T>::operator[](size_t index) const {
    if (index - _start_index < 0) {
        throw std::invalid_argument("start_index can't be > index");
    }
    return _data[index - _start_index];
}

template <class T>
std::ostream& operator<< <T>(std::ostream& out, Math_vector<T>& obj) {
    out << "( ";
    for (size_t i = 0; i < obj._size; i++) {
        out << obj[i];
        if (i < (obj._size - 1)) {
            out << ", ";
        }
    }
    out << " )";
    return out;
}

template <class T>
std::istream& operator>>(std::istream& in, Math_vector<T>& obj) {
    for (size_t i = 0; i < obj._size; i++) {
        in >> obj[i];
    }
    return in;
}