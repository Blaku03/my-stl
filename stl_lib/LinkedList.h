#ifndef MY_STL_LINKEDLIST_H
#define MY_STL_LINKEDLIST_H
#include <iostream>

namespace my_stl{
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
    private:
        void copyList(const LinkedList& user_list);
        void moveList(LinkedList&& user_list) noexcept;
    public:
        Node<T>* first = nullptr;
        Node<T>* last = nullptr;
        size_t number_of_nodes = 0;

        T* operator[](size_t index) const;
        void push_back(T item_data);
        void push_front(T item_data);
        void pop_index(size_t index);

        LinkedList& operator=(const LinkedList& user_list);
        LinkedList& operator=(LinkedList&& user_list) noexcept;

        LinkedList() = default;

        LinkedList(const LinkedList& user_list);
        LinkedList(LinkedList&& user_list) noexcept;

        ~LinkedList();
    };


}

#endif //MY_STL_LINKEDLIST_H
