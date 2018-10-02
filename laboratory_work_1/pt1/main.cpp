#include <bits/stdc++.h>
using namespace std;

// todo:
// 1) group the code into h files
// 2*) use template
// 3) exception handling
// 4) testing (unit tests?)
template <typename T>
struct Node{
    Node<T>* next;
    pair<T,int> data;
};

template <typename T>
class PriorityQueue {
public:
    virtual T pullMaxKey() = 0;
    virtual T peekMaxKey() const = 0;
    virtual void pushElem(T, int) = 0;
    virtual bool isEmpty() const = 0;
    virtual ~PriorityQueue() {};
};

template <typename T>
class PriorityQueueList: public PriorityQueue<T> {
public:
    PriorityQueueList() {
        head = nullptr;
        queueSize = 0;
    }
    ~PriorityQueueList()  {
        Node<T>* cur = head;
        while (cur -> next) {
            Node<T>* tmp = cur;
            cur = cur -> next;
            delete tmp;
        }
        delete cur;
    }
    T pullMaxKey() {
        Node<T>* res = head;
        Node<T>* cur = head;
        int index = 0;
        while (1) {
            if (cur -> next -> data.second > res -> data.second) {
                res = cur;
            }
            if (cur -> next) {
                cur = cur -> next;
                index++;
            } else {
                break;
            }
        }
        T result = (res -> data.first);
        deleteNdElem(index);
        return result;
    }
    T peekMaxKey() const {
        Node<T>* res = head;
        Node<T>* cur = head;
        while (1) {
            if (cur -> next -> data.second > res -> data.second) {
                res = cur;
            }
            if (cur -> next) {
                cur = cur -> next;
            } else {
                break;
            }
        }
        T result = (res -> data.first);
        return result;
    }
    void pushElem(T first, int second) {
        Node<T>* tmp = new Node<T>;
        tmp -> data.first = first;
        tmp -> data.second = second;
        tmp -> next = head;
        head = tmp;
        queueSize++;
    }
    bool isEmpty() const {
        return queueSize <= 0;
    }
private:
    void deleteNdElem(int index) {
        Node<T>* cur = head;
        for (int i = 0; i < index - 1; i++) {
            cur = cur -> next;
        }
        Node<T>* tmp = cur -> next;
        cur -> next = cur -> next -> next;
        delete tmp;
    }
    Node<T>* head;
    int queueSize;
};

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
/*
void testFunction() {

}
*/

int main() {
    PriorityQueueList<int> Heap;
    int d = 3;
    Heap.pushElem(d, d);
    return 0;
}
