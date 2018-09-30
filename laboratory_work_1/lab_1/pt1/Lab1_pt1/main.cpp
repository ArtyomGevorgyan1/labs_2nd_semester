#include <bits/stdc++.h>
using namespace std;

struct Data {
    int value;
    int priority;
};

// works fro structs defined in this file, going to rewrite it using templates later
class PriorityQueue {
public:
    virtual Data pullMaxKey() = 0;
    virtual Data peekMaxKey() const = 0;
    virtual void pushElem(Data) = 0;
    virtual bool isEmpty() const = 0;
    virtual ~PriorityQueue() = 0;
};

struct Node {
    Node* next;
    Data data;
};

class PriorityQueueList: public PriorityQueue {
public:
    PriorityQueueList() {
        head = nullptr;
        queueSize = 0;
    }
    ~PriorityQueueList() {
        Node* cur = head;
        while (cur -> next) {
            Node* tmp = cur;
            cur = cur -> next;
            delete tmp;
        }
        delete cur;
    }
    Data pullMaxKey() {
        if (queueSize <= 0) {
            /*todo: exception handling*/
        }
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
        if (queueSize <= 0) {
            // throw exception???
        }
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
    bool isEmpty() {
        return queueSize > 0;
    }
private:
    // deletion
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

int main() {
    return 0;
}
