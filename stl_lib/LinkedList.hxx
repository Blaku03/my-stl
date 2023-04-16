#include "LinkedList.h"

template<typename T>
T* LinkedList<T>::operator[](size_t index) {
    if(first == nullptr) return nullptr;

    Node<T>* current_node = first;
    for(int i = 0; i < index; i++){
        if(current_node == nullptr) return nullptr;
        current_node = current_node->next;
    }

    return &current_node->data;
}

template<typename T>
void LinkedList<T>::push_back(T item_data) {

    //push back in linked list
    Node<T> *new_node = new Node<T>(item_data);
    if(first == nullptr){
        first = new_node;
        last = new_node;
    } else {
        last->next = new_node;
        new_node->previous = last;
        last = new_node;
    }
    number_of_nodes++;
}

template<typename T>
void LinkedList<T>::push_front(T item_data) {

    //push front in linked list
    Node<T> *new_node = new Node<T>(item_data);
    if(first == nullptr){
        first = new_node;
        last = new_node;
    } else {
        first->previous = new_node;
        new_node->next = first;
        first = new_node;
    }
    number_of_nodes++;
}

template<typename T>
void LinkedList<T>::pop_index(size_t index) {

    //pop index in linked list
    if(first == nullptr) return;

    Node<T>* current_node = first;

    //iterate to index
    for(int i = 0; i < index; i++){
        if(current_node == nullptr) return;
        current_node = current_node->next;
    }

    if(current_node == first){
        first = current_node->next;
        first->previous = nullptr;
    } else if(current_node == last){
        last = current_node->previous;
        last->next = nullptr;
    } else {
        current_node->previous->next = current_node->next;
        current_node->next->previous = current_node->previous;
    }

    delete current_node;
    number_of_nodes--;
}

template<typename T>
LinkedList<T>::~LinkedList<T>() {
    while(first != nullptr){
        Node<T> *temp = first;
        first = first->next;
        delete temp;
    }
}