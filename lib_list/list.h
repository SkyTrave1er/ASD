#pragma once
#include <iostream>

template <class T>
struct Node {
    T _value;
    Node<T>* _next;
    Node(T value, Node<T>* next = nullptr);
};

template <class T>
Node<T>::Node(T value, Node<T>* next) {
    _value = value;
    _next = next;
}

template <class T>
class List {
    Node<T>* _head;
    Node<T>* _tail;
    size_t _count;
public:
    List();
    ~List();
    List(const List<T>& other);
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
};

template <class T>
List<T>::List() : _head(nullptr), _tail(nullptr), _count(0) {}

template <class T>
List<T>::~List() {
    while (!is_empty()) {
        pop_front();
    }
}

template <class T>
List<T>::List(const List<T>& other) : _head(nullptr), _tail(nullptr), _count(0) {
    Node<T>* current = other._head;
    while (current != nullptr) {
        push_back(current->_value);
        current = current->_next;
    }
}

template <class T>
bool List<T>::is_empty() {
    return _head == nullptr;
}

template <class T>
size_t List<T>::get_count() const {
    return _count;
}

template <class T>
Node<T>* List<T>::head() {
    return _head;
}

template <class T>
Node<T>* List<T>::tail() {
    return _tail;
}

template <class T>
void List<T>::push_front(const T& value) noexcept {
    Node<T>* node = new Node<T>(value);
    if (is_empty()) {
        _head = node;
        _tail = node;
        _count++;
        return;
    }
    node->_next = _head;
    _head = node;
    _count++;
}

template <class T>
void List<T>::push_back(const T& value) noexcept {
    Node<T>* node = new Node<T>(value);
    if (is_empty()) {
        _head = node;
        _tail = node;
        _count++;
        return;
    }
    _tail->_next = node;
    _tail = node;
    _count++;
}

template <class T>
void List<T>::insert(Node<T>* node, const T& value) {
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
void List<T>::insert(size_t pos, const T& value) {
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
void List<T>::pop_back() {
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
    Node<T>* current = _head;
    while (current->_next != _tail) {
        current = current->_next;
    }
    delete _tail;
    _tail = current;
    current->_next = nullptr;
    _count--;
}

template <class T>
void List<T>::pop_front() {
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
    _count--;
}

template <class T>
void List<T>::erase(Node<T>* node) {
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
void List<T>::erase(size_t pos) {
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