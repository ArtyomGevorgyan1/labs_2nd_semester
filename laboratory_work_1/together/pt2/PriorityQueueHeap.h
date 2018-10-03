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
        pair<T,int> res = heapSpace[0];
        heapSpace[0] = heapSpace[heapSize - 1];
        heapSize--;
        siftDown(0);
        return res.first;
    }
    T peekMaxKey() const {
        pair<T,int> res = heapSpace[0];
        return res.first;
    }
    void pushElem(pair<T,int> d) {
        heapSize++;
        if (heapSpace == nullptr) {
            heapSpace = new pair<T, int>;
        }
        heapSpace[heapSize - 1] = d;
        siftUp(heapSize - 1);
    }
    bool isEmpty() const {
        return heapSize <= 0;
    }

private:
    void siftUp (int i) {
        while (heapSpace[i].second < heapSpace[(i - 1) / 2].second) {
            swap(heapSpace[(i - 1) / 2], heapSpace[i]);
            i = (i - 1) / 2;
        }
    }
    void siftDown (int i) {
        while (2 * i + 1 < heapSize) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;
            if (right < heapSize && heapSpace[right].second > heapSpace[left].second) {
                j = right;
            }
            if (heapSpace[i].second >= heapSpace[j].second) {
                break;
            }
            swap(heapSpace[i], heapSpace[j]);
            i = j;
        }
    }
    pair<T,int>* heapSpace;
    int queueSize;
    int heapSize;
};
