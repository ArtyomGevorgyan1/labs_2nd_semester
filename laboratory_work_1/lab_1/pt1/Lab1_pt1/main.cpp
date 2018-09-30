#include <bits/stdc++.h>
using namespace std;

struct Data {
    int value;
    int priority;
};

// works fro structs defined in this file, going to rewrite it using templates later
class PriorityQueue {
public:
    virtual Data pullMaxKey() const = 0;
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


private:
    Node* head;
};

int main() {
    return 0;
}
