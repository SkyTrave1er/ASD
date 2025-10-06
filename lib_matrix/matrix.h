#include "../lib_math_vector/math_vector.h"
#include "math.h"
#pragma once

template <class T>
class Matrix;
template <class T>
std::ostream& operator<< (std::ostream& out, const Matrix<T>& obj);
template <class T>
std::istream& operator>> (std::istream& in, Matrix<T>& obj);

template <class T>
class Matrix : public Math_vector<Math_vector<T>> {
protected:
    size_t _rows, _cols;
public:
    Matrix();
    Matrix(size_t rows, size_t cols);
    Matrix(const Math_vector<Math_vector<T>>&);
    Matrix(const Matrix&);
    size_t get_rows() const;
    size_t get_cols() const;
    Matrix<T> transp() const;
    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix<T> operator*(T val);
    Math_vector<T> operator*(const Math_vector<T> vec);
    Matrix<T> operator*(const Matrix<T>& matr);
    Matrix<T>& operator=(const Matrix<T>& other);
    bool operator==(const Matrix<T>& other) const;
    bool operator!=(const Matrix<T>& other) const;
    Matrix<T>& operator+=(const Matrix<T>& other);
    Matrix<T>& operator-=(const Matrix<T>& other);
    Matrix<T>& operator*=(T val);
    Matrix<T>& operator*=(const Matrix<T>& other);
    friend std::ostream& operator<< <T>(std::ostream& out, const Matrix<T>& obj);
    friend std::istream& operator>> <T>(std::istream& in, Matrix<T>& obj);
};

template <class T>
Matrix<T>::Matrix() : _rows(0), _cols(0), Math_vector<Math_vector<T>>() {}

template <class T>
Matrix<T>::Matrix(size_t rows, size_t cols) : _rows(rows), _cols(cols), Math_vector<Math_vector<T>>(rows) {
    /*for (size_t i = 0; i < _cols; i++) {
        _data[i] = new Math_vector<T>(rows);
    }*/
    for (size_t i = 0; i < _rows; i++) {
        (*this)[i] = Math_vector<T>(_cols);
    }
}

template <class T>
Matrix<T>::Matrix(const Math_vector<Math_vector<T>>& other) : Math_vector<Math_vector<T>>(other) {
    if (this->_size > 0) {
        _rows = this->_size;
        _cols = (*this)[0].size();
        for (size_t i = 1; i < _rows; ++i) {
            if ((*this)[i].size() != _cols) {
                throw std::invalid_argument("all rows must have the same length");
            }
        }
    }
    else {
        _rows = 0;
        _cols = 0;
    }
}

template <class T>
Matrix<T>::Matrix(const Matrix& other) : Math_vector<Math_vector<T>>(other), _rows(other._rows), _cols(other._cols) {}

template <class T>
size_t Matrix<T>::get_rows() const {
    return _rows;
}

template <class T>
size_t Matrix<T>::get_cols() const {
    return _cols;
}

template <class T>
Matrix<T> Matrix<T>::transp() const {
    Matrix<T> result(_cols, _rows);
    for (size_t i = 0; i < _rows; i++) {
        for (size_t j = 0; j < _cols; j++) {
            result[j][i] = (*this)[i][j];
        }
    }
    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator*(T val) {
    Matrix<T> result(_rows, _cols);
    for (int i = 0; i < _rows; i++) {
        result[i] = (*this)[i] * val;
    }
    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) {
    if (this->get_cols() != other.get_cols() || this->get_rows() != other.get_rows()) {
        throw std::invalid_argument("Matrixes must be the same size");
    }
    return this->Math_vector<Math_vector<T>>::operator+(other);
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix& other) {
    if (this->get_cols() != other.get_cols() || this->get_rows() != other.get_rows()) {
        throw std::invalid_argument("Matrixes must be the same size");
    }
    return this->Math_vector<Math_vector<T>>::operator-(other);
}

template <class T>
Math_vector<T> Matrix<T>::operator*(const Math_vector<T> vec) {
    if (this->get_cols() != vec.size()) {
        throw std::invalid_argument("Matrixes must be the same size");
    }
    Math_vector<T> result(_rows);
    for (int i = 0; i < _rows; i++) {
        result[i] = (*this)[i] * vec;
    }
    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& matr) {
    if (this->get_cols() != matr.get_rows()) {
        throw std::invalid_argument("Matrixes must be the same size");
    }
    Matrix<T> result(_rows, matr._cols);
    Matrix<T> matr_t = matr.transp();

    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < matr._cols;j++) {
            result[i][j] = (*this)[i] * matr_t[j];
        }
    }
    return result;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
    if (this != &other) {
        Math_vector<Math_vector<T>>::operator=(other);
        _rows = other._rows;
        _cols = other._cols;
    }
    return *this;
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T>& other) const {
    if (_rows != other._rows || _cols != other._cols) {
        return false;
    }
    return Math_vector<Math_vector<T>>::operator==(other);
}

template <class T>
bool Matrix<T>::operator!=(const Matrix<T>& other) const {
    return !(*this == other);
}

template <class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& other) {
    if (this->get_cols() != other.get_cols() || this->get_rows() != other.get_rows()) {
        throw std::invalid_argument("Matrixes must be the same size");
    }
    *this = *this + other;
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& other) {
    if (this->get_cols() != other.get_cols() || this->get_rows() != other.get_rows()) {
        throw std::invalid_argument("Matrixes must be the same size");
    }
    *this = *this - other;
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator*=(T val) {
    for (size_t i = 0; i < _rows; i++) {
        (*this)[i] *= val;
    }
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& other) {
    if (this->get_cols() != other.get_rows()) {
        throw std::invalid_argument("Matrixes must be the same size");
    }
    *this = *this * other;
    return *this;
}

template <class T>
std::ostream& operator<< <T>(std::ostream& out, const Matrix<T>& obj) {
    out << "Matrix " << obj._rows << "x" << obj._cols << ":\n";
    for (size_t i = 0; i < obj._rows; i++) {
        out << "[ ";
        for (size_t j = 0; j < obj._cols; j++) {
            out << obj[i][j];
            if (j < obj._cols - 1) out << ", ";
        }
        out << " ]\n";
    }
    return out;
}

template <class T>
std::istream& operator>>(std::istream& in, Matrix<T>& obj) {
    for (size_t i = 0; i < obj._rows; ++i) {
        for (size_t j = 0; j < obj._cols; ++j) {
            in >> obj[i][j];
        }
    }
    return in;
}