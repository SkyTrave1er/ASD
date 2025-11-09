#include "../lib_matrix/matrix.h"
#pragma once

template <class T>
class Triangle_matrix;
template <class T>
std::ostream& operator<< (std::ostream& out, const Triangle_matrix<T>& obj);
template <class T>
std::istream& operator>> (std::istream& in, Triangle_matrix<T>& obj);

template <class T>
class Triangle_matrix : public Matrix<T> {
private:
    size_t _N;
public:
    Triangle_matrix();
    Triangle_matrix(size_t N);
    Triangle_matrix(const Math_vector<Math_vector<T>>&);
    Triangle_matrix(const Matrix<T>& other);
    Triangle_matrix(const Triangle_matrix&);
    size_t get_n() const;
    Triangle_matrix<T>& operator=(const Triangle_matrix& other);
    Triangle_matrix operator+(const Triangle_matrix& other);
    Triangle_matrix operator-(const Triangle_matrix& other);
    Triangle_matrix<T> operator*(T val);
    Triangle_matrix<T> operator*(const Triangle_matrix<T>& matr) const;
    friend std::ostream& operator<< <T>(std::ostream& out, const Triangle_matrix<T>& obj);
    friend std::istream& operator>> <T>(std::istream& in, Triangle_matrix<T>& obj);
};

template <class T>
Triangle_matrix<T>::Triangle_matrix() : Matrix<T>(), _N(0) {}

template <class T>
Triangle_matrix<T>::Triangle_matrix(size_t N) : Matrix<T>(N, N), _N(N) {
    for (size_t i = 0; i < N; i++) {
        (*this)[i] = Math_vector<T>(N - i, i);
    }
}

template <class T>
size_t Triangle_matrix<T>::get_n() const {
    return _N;
}

template <class T>
Triangle_matrix<T>::Triangle_matrix(const Math_vector<Math_vector<T>>& other) : Matrix<T>(other), _N(0) {
    if (this->get_rows() > 0) {
        _N = this->get_rows();
        for (size_t i = 0; i < _N; i++) {
            if ((*this)[i].size() != (_N - i)) {
                throw std::invalid_argument("Invalid triangle matrix dimensions");
            }
        }
    }
}

template <class T>
Triangle_matrix<T>::Triangle_matrix(const Matrix<T>& other) : Matrix<T>(other), _N(0) {
    if (this->get_rows() > 0) {
        _N = this->get_rows();
        for (size_t i = 0; i < _N; i++) {
            if ((*this)[i].size() != (_N - i)) {
                throw std::invalid_argument("Invalid triangle matrix dimensions");
            }
        }
    }
}

template <class T>
Triangle_matrix<T>::Triangle_matrix(const Triangle_matrix& other) : Matrix<T>(other), _N(other._N) {}

template <class T>
Triangle_matrix<T>& Triangle_matrix<T>::operator=(const Triangle_matrix& other) {
    if (this != &other) {
        this->Matrix<T>::operator=(other);
        _N = other._N;
    }
    return *this;
}

template <class T>
Triangle_matrix<T> Triangle_matrix<T>::operator*(T val) {
    Triangle_matrix result(_N);
    result = this->Matrix<T>::operator*(val);
    /*for (size_t i = 0; i < _N; i++) {
        result[i] = (*this)[i] * val;
    }*/
    return result;
}

template <class T>
Triangle_matrix<T> Triangle_matrix<T>::operator+(const Triangle_matrix& other) {
    if (_N != other._N) {
        throw std::invalid_argument("Triangle matrices must have same size");
    }

    Triangle_matrix result(_N);
    //result = this->Matrix<T>::operator+(other);
    for (size_t i = 0; i < _N; i++) {
        result[i] = (*this)[i] + other[i];
    }
    return result;
}

template <class T>
Triangle_matrix<T> Triangle_matrix<T>::operator-(const Triangle_matrix& other) {
    if (_N != other._N) {
        throw std::invalid_argument("Triangle matrices must have same size");
    }

    Triangle_matrix result(_N);
    //result = this->Matrix<T>::operator-(other);
    for (size_t i = 0; i < _N; i++) {
        result[i] = (*this)[i] - other[i];
    }
    return result;
}

template <class T>
Triangle_matrix<T> Triangle_matrix<T>::operator*(const Triangle_matrix<T>& matr) const {
    if (_N != matr._N) {
        throw std::invalid_argument("Triangle matrices must have same size");
    }

    Triangle_matrix result(_N);
    for (size_t i = 0; i < _N; i++) {
        for (size_t j = i; j < _N; j++) {
            T sum = T();
            for (size_t k = i; k <= j; k++) {
                sum += (*this)[i][k] * matr[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

template <class T>
std::ostream& operator<< <T>(std::ostream& out, const Triangle_matrix<T>& obj) {
    out << "Triangle matrix " << obj._N << "x" << obj._N << ":\n";
    for (size_t i = 0; i < obj._N; i++) {
        out << "[ ";
        for (size_t j = 0; j < obj._N; j++) {
            if (j < obj[i].get_start_index()) {
                out << "0";
            }
            else {
                out << obj[i][j];
            }
            if (j < obj._N - 1) out << ", ";
        }
        out << " ]\n";
    }
    return out;
}

template <class T>
std::istream& operator>>(std::istream& in, Triangle_matrix<T>& obj) {
    for (size_t i = 0; i < obj._N; i++) {
        for (size_t j = obj[i].get_start_index(); j < obj._N; j++) {
            in >> obj[i][j];
        }
    }
    return in;
}