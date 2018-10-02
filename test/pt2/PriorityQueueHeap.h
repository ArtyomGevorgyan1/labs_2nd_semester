#pragma once
#include "PriorityQueue.h"

template <typename T>
class PriorityQueueHeap: public PriorityQueue<T> {
public:
    PriorityQueueHeap() {
        heapSize = 0;
        queueSize = 0;
        heapSpace = nullptr;
    }
    ~PriorityQueueHeap() {
        delete[] heapSpace;
    }
    T pullMaxKey() {
        T res = heapSpace[0];
        heapSpace[0] = heapSpace[heapSize - 1];
        heapSize--;
        siftDown(0);
        return res;
    }
    T peekMaxKey() const {
        T res = heapSpace[0];
        return res;
    }
    void pushElem(T d) {
        heapSize++;
        heapSpace[heapSize - 1] = d;
        siftUp(heapSize - 1);
    }
    bool isEmpty() const {
        return heapSize <= 0;
    }

private:
    void siftUp (int i) {
        while (heapSpace[i].priority < heapSpace[(i - 1) / 2].priority) {
            swap(heapSpace[(i - 1) / 2], heapSpace[i]);
            i = (i - 1) / 2;
        }
    }
    void siftDown (int i) {
        while (2 * i + 1 < heapSize) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;
            if (right < heapSize && heapSpace[right].priority > heapSpace[left].priority) {
                j = right;
            }
            if (heapSpace[i].priority >= heapSpace[j].priority) {
                break;
            }
            swap(heapSpace[i], heapSpace[j]);
            i = j;
        }
    }
    T* heapSpace;
    int queueSize;
    int heapSize;
};
