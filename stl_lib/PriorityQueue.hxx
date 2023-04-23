#pragma once

#include "PriorityQueue.h"

template<typename T, typename functionCompare>
void PriorityQueue<T, functionCompare>::swap(T &a, T &b) {

    T temp = a;
    a = b;
    b = temp;
}

template<typename T, typename functionCompare>
bool PriorityQueue<T, functionCompare>::empty() {
    return heap.size() == 0;
}

template<typename T, typename functionCompare>
int PriorityQueue<T, functionCompare>::size() const {
    return heap.size();
}

template<typename T, typename functionCompare>
int PriorityQueue<T, functionCompare>::rightChild(int index) {
    return 2 * index + 2;
}

template<typename T, typename functionCompare>
int PriorityQueue<T, functionCompare>::leftChild(int index) {
    return 2 * index + 1;
}

template<typename T, typename functionCompare>
int PriorityQueue<T, functionCompare>::parent(int index) {
    return (index - 1) / 2;
}

template<typename T, typename functionCompare>
void PriorityQueue<T, functionCompare>::heapifyUp(int index) {

    while (index > 0 && compare(heap[index], heap[parent(index)])) {
        swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

template<typename T, typename functionCompare>
void PriorityQueue<T, functionCompare>::heapifyDown(int index) {
    int child = leftChild(index);

    while (child < heap.size()) {
        if (child + 1 < heap.size() && compare(heap[child + 1], heap[child])) {
            child++;
        }
        if (compare(heap[index], heap[child])) {
            break;
        }
        swap(heap[index], heap[child]);
        index = child;
        child = leftChild(index);
    }
}

template<typename T, typename functionCompare>
const T &PriorityQueue<T, functionCompare>::top() {
    return heap[0];
}

template<typename T, typename functionCompare>
void PriorityQueue<T, functionCompare>::pop() {
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop();
    heapifyDown(0);
}

template<typename T, typename functionCompare>
void PriorityQueue<T, functionCompare>::push(const T &value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}
