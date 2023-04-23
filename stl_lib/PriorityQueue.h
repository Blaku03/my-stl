#ifndef MY_STL_PRIORITYQUEUE_H
#define MY_STL_PRIORITYQUEUE_H

#include "vector.hxx"

using my_stl::vector;

//default compare function
template<typename T, typename functionCompare = std::greater<T>>
class PriorityQueue {
private:
    vector<T> heap;
    functionCompare compare;

    void swap(T &a, T &b);

    void heapifyDown(int index);

    void heapifyUp(int index);

    int parent(int index);

    int leftChild(int index);

    int rightChild(int index);

public:
    explicit PriorityQueue(functionCompare compare) : compare(compare) {}

    PriorityQueue() = default;

    void push(const T &value);

    void pop();

    const T &top();

    bool empty();

    [[nodiscard]] int size() const;

};


#endif //MY_STL_PRIORITYQUEUE_H
