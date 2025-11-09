#pragma once

#include <iostream>

template <class T>
struct Node {
    T _value;
    Node<T>* _next;
    Node<T>* _prev;
    Node(T value, Node<T>* next = nullptr, Node<T>* prev = nullptr);
};

template <class T>
Node<T>::Node(T value, Node<T>* next, Node<T>* prev) {
    _value = value;
    _next = next;
    _prev = prev;
}

template <class T>
class Dl_list {
    Node<T>* _head;
    Node<T>* _tail;
    size_t _count;
public:
    class Iterator {
    protected:
        Node<T>* _current;
    public:
        Iterator() {
            _current = _head;
        }
        Iterator(Node<T>* node) {
            _current = node;
        }

        T& operator*() {
            return _current->_value;
        }

        Iterator& operator++() {
            _current = _current->_next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        Iterator& operator--() {
            _current = _current->_prev;
            return *this;
        }

        Iterator operator--(int) {
            Iterator tmp = *this;
            --(*this);
            return tmp;
        }

        Iterator& operator=(Iterator& other) {
            if (this != &other) {
                _current = other._current
            }
            return *this;
        }

        bool operator!=(Iterator& other) {
            return (_current != other._current);
        }
    };

    Dl_list();
    ~Dl_list();
    Dl_list(const Dl_list<T>& other);
    bool is_empty();
    size_t get_count() const;
    Node<T>* head();
    Node<T>* tail();
    void push_front(const T& value) noexcept;
    void push_back(const T& value) noexcept;
    void insert(size_t pos, const T& value);
    void insert(Node<T>* node, const T& value);
    void pop_front();
    void pop_back();
    void erase(size_t pos);
    void erase(Node<T>* node);
    Iterator begin();
    Iterator end();

};

template <class T>
Dl_list<T>::Dl_list() : _head(nullptr), _tail(nullptr), _count(0) {}

template <class T>
Dl_list<T>::~Dl_list() {
    Node<T>* current = _head;
    while (current != nullptr) {
        Node<T>* next = current->_next;
        delete current;
        current = next;
    }
}

template <class T>
Dl_list<T>::Dl_list(const Dl_list<T>& other) : _head(nullptr), _tail(nullptr), _count(0) {
    Node<T>* current = other._head;

    while (current != nullptr) {
        push_back(current->_value);
        current = current->_next;
    }
}

template <class T>
typename Dl_list<T>::Iterator Dl_list<T>::begin() {
    return Iterator(_head);
}

template <class T>
typename Dl_list<T>::Iterator Dl_list<T>::end() {
    return Iterator(_tail);
}

template <class T>
bool Dl_list<T>::is_empty() {
    return _head == nullptr;
}

template <class T>
size_t Dl_list<T>::get_count() const {
    return _count;
}

template <class T>
Node<T>* Dl_list<T>::head() {
    return _head;
}

template <class T>
Node<T>* Dl_list<T>::tail() {
    return _tail;
}

template <class T>
void Dl_list<T>::push_front(const T& value) noexcept {
    Node<T>* node = new Node<T>(value, _head, nullptr);
    if (is_empty()) {
        _head = node;
        _tail = node;
        _count++;
        return;
    }
    if (_head != nullptr) {
        _head->_prev = node;
    }
    _head = node;
    _count++;
}

template <class T>
void Dl_list<T>::push_back(const T& value) noexcept {
    Node<T>* node = new Node<T>(value, nullptr, _tail);
    if (is_empty()) {
        _head = node;
        _tail = node;
        _count++;
        return;
    }
    if (_tail != nullptr) {
        _tail->_next = node;
    }
    _tail = node;
    _count++;
}

template <class T>
void Dl_list<T>::insert(Node<T>* node, const T& value) {
    if (node == nullptr || is_empty()) {
        throw std::logic_error("empty");
    }
    Node<T>* new_node = new Node<T>(value);
    new_node->_next = node->_next;
    node->_next = new_node;
    if (node == _tail) {
        _tail = new_node;
    }
    _count++;
}

template <class T>
void Dl_list<T>::insert(size_t pos, const T& value) {
    if (pos == 0) {
        push_front(value);
        return;
    }
    if (pos == _count - 1) {
        push_back(value);
        return;
    }
    Node<T>* current = _head;
    size_t current_pos = 0;
    while (current != nullptr) {
        if (current_pos == pos - 1) {
            break;
        }
        current_pos++;
        current = current->_next;
    }
    if (current == nullptr) {
        throw std::logic_error("nullptr");
    }
    insert(current, value);
}

template <class T>
void Dl_list<T>::pop_back() {
    if (is_empty()) {
        throw std::logic_error("empty");
    }
    if (_head == _tail) {
        delete _head;
        _head = nullptr;
        _tail = nullptr;
        _count--;
        return;
    }
    Node<T>* current = _tail->_prev;
    delete _tail;
    _tail = current;
    _tail->_next = nullptr;
    _count--;
}

template <class T>
void Dl_list<T>::pop_front() {
    if (is_empty()) {
        throw std::logic_error("empty");
    }
    if (_head == _tail) {
        delete _head;
        _head = nullptr;
        _tail = nullptr;
        _count--;
        return;
    }
    Node<T>* current = _head->_next;
    delete _head;
    _head = current;
    _head->_prev = nullptr;
    _count--;
}

template <class T>
void Dl_list<T>::erase(Node<T>* node) {
    if (node == nullptr || is_empty()) {
        throw std::logic_error("empty");
    }
    if (node == _head) {
        pop_front();
        return;
    }
    if (node == _tail) {
        pop_back();
        return;
    }
    Node<T>* current = _head;
    Node<T>* next = node->_next;
    while (current->_next != node) {
        current = current->_next;
    }
    delete node;
    current->_next = next;
    _count--;
}

template <class T>
void Dl_list<T>::erase(size_t pos) {
    if (is_empty()) {
        throw std::logic_error("empty");
    }
    if (pos == 0) {
        pop_front();
        return;
    }
    Node<T>* current = _head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->_next;
    }
    Node<T>* deleted = current->_next;
    current->_next = deleted->_next;
    if (deleted == _tail) {
        _tail = current;
    }

    delete deleted;
    _count--;
}