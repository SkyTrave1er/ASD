#pragma once
#include <iostream>

template <class T>
class Queue {
    T* _data;
    int _size;
    int _head;
    int _tail;
    int _count;
public:
    Queue(int size);
    Queue(const Queue<T>& other);
    void push(T val);
    void pop();
    T tail() const;
    T head() const;
    int get_size() const;
    int get_count() const;
    int get_head() const;
    int get_tail() const;
    inline bool is_empty() const noexcept;
    inline bool is_full() const noexcept;
    void clear() noexcept;
};

template <class T>
Queue<T>::Queue(int size) : _size(size), _count(0), _head(0), _tail(0) {
    if (size < 0) {
        throw std::logic_error("Size can't be negative");
    }
    _data = new T[_size];
}

template <class T>
Queue<T>::Queue(const Queue<T>& other) {
    this->_size = other._size;
    this->_count = other._count;
    this->_head = other._head;
    this->_tail = other._tail;
    _data = new T[_size];

    for (int i = 0; i < _size; i++) {
        _data[i] = other._data[i];
    }
}

template <class T>
bool Queue<T>::is_empty() const noexcept {
    if (_count == 0 && _tail == _head) {
        return true;
    }
    return false;
}

template <class T>
bool Queue<T>::is_full() const noexcept {
    return _count == _size;
}

template <class T>
void Queue<T>::push(T val) {
    if (is_full()) {
        throw std::invalid_argument("Queue is full!");
    }
    _data[_tail] = val;
    _tail = (_tail + 1) % _size;
    _count++;
}

template <class T>
void Queue<T>::pop() {
    if (is_empty()) {
        throw std::invalid_argument("Queue is empty!");
    }
    _head = (_head + 1) % _size;
    _count--;
}

template <class T>
void Queue<T>::clear() noexcept {
    _head = 0;
    _tail = 0;
    _count = 0;
}

template <class T>
int Queue<T>::get_size() const {
    return _size;
}

template <class T>
int Queue<T>::get_count() const {
    return _count;
}

template <class T>
int Queue<T>::get_head() const {
    return _head;
}

template <class T>
int Queue<T>::get_tail() const {
    return _tail;
}

template <class T>
T Queue<T>::tail() const {
    if (is_empty()) {
        throw std::invalid_argument("Queue is empty!");
    }
    return _data[_tail - 1];
}

template <class T>
T Queue<T>::head() const {
    if (is_empty()) {
        throw std::invalid_argument("Queue is empty!");
    }
    return _data[_head];
}