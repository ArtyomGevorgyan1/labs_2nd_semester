#include "FileSystem.h"
#include "PriorityQueueHeap.h"
#include "PriorityQueueList.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

template <typename T>
void testingFunction(vector<pair<T, int>> test, int mode = 1) {
    PriorityQueue<T>* PQueue;
    if (mode) {
        PQueue = new PriorityQueueHeap<T>();
    } else {
        PQueue = new PriorityQueueList<T>();
    }
    for (int i = 0; i < test.size(); i++) {
        if (PQueue->isEmpty()) {
            cout << "Is empty\n";
        }
        PQueue->pushElem(test[i]);
        cout << "ff\n";
    }
    for (int i = 0; i < test.size(); i++) {
        T highest = PQueue->peekMaxKey();
        T popped = PQueue->pullMaxKey();
        if (highest == popped) {
            cout << "The highest and the popped elements match\n";
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
    /*
    vector <pair<int, int>> vec = {make_pair(1, 1)};
    testingFunction<int>(vec);
    */
    /*
    PriorityQueue<int> *P = new PriorityQueueList<int>();
    pair<int,int> elem = {3, 3};
    P->pushElem(elem);
    if (P->isEmpty()) {
        cout << "empty\n";
    } else {
        cout<<"np]\n";
    }
    int m = P->peekMaxKey();
    cout << m;
    P->pullMaxKey();
    if (P->isEmpty()) {
        cout << "empty\n";
    } else {
        cout<<"np]\n";
    }
    */
    return 0;
}
