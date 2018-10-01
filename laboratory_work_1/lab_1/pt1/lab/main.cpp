#include <bits/stdc++.h>
using namespace std;

// todo:
// 1) group the code into h files
// 2) use templates
// 3) exception handling
// 4) testing (unit tests?)


struct Data {
    int value;
    int priority;
};

template <typename T>
struct Node {
    Node* next;
    Data data;
};

class PriorityQueue {
public:
    virtual Data pullMaxKey() = 0;
    virtual Data peekMaxKey() const = 0;
    virtual void pushElem(Data) = 0;
    virtual bool isEmpty() const = 0;
    virtual ~PriorityQueue() {};
};

class PriorityQueueList: public PriorityQueue {
public:
    PriorityQueueList() {
        head = nullptr;
        queueSize = 0;
    }
    ~PriorityQueueList()  {
        Node* cur = head;
        while (cur -> next) {
            Node* tmp = cur;
            cur = cur -> next;
            delete tmp;
        }
        delete cur;
    }
    Data pullMaxKey() {
        Node* res = head;
        Node* cur = head;
        int index = 0;
        while (1) {
            if (cur -> next -> data.priority > res -> data.priority) {
                res = cur;
            }
            if (cur -> next) {
                cur = cur -> next;
                index++;
            } else {
                break;
            }
        }
        Data result = (res -> data);
        deleteNdElem(index);
        return result;
    }
    Data peekMaxKey() const {
        Node* res = head;
        Node* cur = head;
        while (1) {
            if (cur -> next -> data.priority > res -> data.priority) {
                res = cur;
            }
            if (cur -> next) {
                cur = cur -> next;
            } else {
                break;
            }
        }
        Data result = (res -> data);
        return result;
    }
    void pushElem(Data data) {
        Node* tmp = new Node(/*parameters to initialize it*/);
        tmp -> next = head;
        head = tmp;
        queueSize++;
    }
    bool isEmpty() const {
        return queueSize <= 0;
    }
private:
    void deleteNdElem(int index) {
        Node* cur = head;
        for (int i = 0; i < index - 1; i++) {
            cur = cur -> next;
        }
        Node* tmp = cur -> next;
        cur -> next = cur -> next -> next;
        delete tmp;
    }
    Node* head;
    int queueSize;
};

class PriorityQueueHeap: public PriorityQueue {
public:
    PriorityQueueHeap() {
        heapSize = 0;
        queueSize = 0;
        heapSpace = nullptr;
    }
    ~PriorityQueueHeap() {
        delete[] heapSpace;
    }
    Data pullMaxKey() {
        Data res = heapSpace[0];
        heapSpace[0] = heapSpace[heapSize - 1];
        heapSize--;
        siftDown(0);
        return res;
    }
    Data peekMaxKey() const {
        Data res = heapSpace[0];
        return res;
    }
    void pushElem(Data d) {
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
    Data* heapSpace;
    int queueSize;
    int heapSize;
};

int main() {
    PriorityQueueList Heap;
    Data d;
    Heap.pushElem(d);
    return 0;
}
