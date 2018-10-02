#include "FileSystem.h"
#include "PriorityQueueHeap.h"
#include "PriorityQueueList.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

template <typename T>
void testingFunction(vector<pair<T, int>> test, int mode = 0) {
    PriorityQueue<T>* PQueue;
    if (mode) {
        PQueue = new PriorityQueueHeap<T>();
    } else {
        PQueue = new PriorityQueueList<T>();
    }
    for (int i = 0; i < 2*test.size(); i++) {
        if (i > test.size()) {
            T highest = PQueue.peekMaxKey();
            T popped = PQueue.pullMaxKey();
            if (highest == popped) {
                cout << "The highest and the popped elements match\n";
            }
        } else {
            if (PQueue.isEmpty()) {
                cout << "Is empty\n";
            }
            PQueue.pushElem(test[i]);
        }
    }
}

// function to serve as a filter for the operation of searching for files in FileSystem
bool parameters(File* file) {
    if (file-> getSize() > 10) {
        return 1;
    }
}

int main() {
    File f;
    return 0;
}
