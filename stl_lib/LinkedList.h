#ifndef MY_STL_LINKEDLIST_H
#define MY_STL_LINKEDLIST_H
#include <iostream>

template<typename T>
class Node{
public:
    Node* next = nullptr;
    Node* previous = nullptr;
    T data;

    explicit Node(T data){
        this->data = data;
    }

    ~Node() = default;
};

template<typename T>
class LinkedList {
public:
    Node<T>* first = nullptr;
    Node<T>* last = nullptr;
    size_t number_of_nodes = 0;

    T* operator[](size_t index);
    void push_back(T item_data);
    void push_front(T item_data);
    void pop_index(size_t index);

    ~LinkedList();
};


#endif //MY_STL_LINKEDLIST_H
