#include <bits/stdc++.h>
using namespace std;

// todo:
// 1) group the code into h files
// 2) use templates
// 3) exception handling
// 4) testing (unit tests?)

// BUG! NEED TO PASS 2 ARGUMENTS: T AND INT
template <typename T>
struct Node{
    Node<T>* next;
    T data;
};

template <typename T>
class PriorityQueue {
public:
    virtual T pullMaxKey() = 0;
    virtual T peekMaxKey() const = 0;
    virtual void pushElem(T) = 0;
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
            if (cur -> next -> data > res -> data) {
                res = cur;
            }
            if (cur -> next) {
                cur = cur -> next;
                index++;
            } else {
                break;
            }
        }
        T result = (res -> data);
        deleteNdElem(index);
        return result;
    }
    T peekMaxKey() const {
        Node<T>* res = head;
        Node<T>* cur = head;
        while (1) {
            if (cur -> next -> data > res -> data) {
                res = cur;
            }
            if (cur -> next) {
                cur = cur -> next;
            } else {
                break;
            }
        }
        T result = (res -> data);
        return result;
    }
    void pushElem(T data) {
        Node<T>* tmp = new Node<T>(/*parameters to initialize it*/);
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

void driverFunction() {
    cout << "Please select what type of a priority queue you want to use.\n";
    cout << "1 - naive, 2 - effective\n";

    bool gotAnswer = 0;
    char ans;
    PriorityQueue* PQ;
    while (!gotAnswer) {
        cin >> ans;
        switch(ans) {
        case '1':
            PQ = new PriorityQueueList();
            gotAnswer = 1;
            break;
        case '2':
            PQ = new PriorityQueueHeap();
            gotAnswer = 1;
            break;
        default:
            cout << "Please choose the correct answer or exit the program\n";
        }
    }

    cout << "Great! Now you are able to test the appropriate class against your data\n"
         << "There are 4 methods available on the Priority Queue data structure. Insert \n" <<
         << "an element, pop an element with highest priority, see what the element with the\n" <<
         << "highest priority is, and check whether the Queue is empty. Type " << "[push, " <<
         << "pop, peek, empty] to call these methods. If you want to exit, type exit\n\n";
    cout << "But first of all, choose the type (int, double, string, vector)";

    string type;
    bool isVector = 0;
    while (1) {
        cin >> type;
        if (type == "int") {
            using type = int;
            break;
        }
        if (type == "double") {
            using type = double;
            break;
        }
        if (type == "string") {
            using type = string;
            break;
        }
        if (type == "vector") {
            cout << "Vector contains what? Int or double?\n";
            string contains;
            cin >> contains;
            if (contains == "int") {
                using type = vector<int>;
            } else if (contains == "double") {
                using type = vector<double>;
            }
            break;
        } else {
            cout << "Try again\n";
        }
    }

    if (isVector) {
        while (1) {
            string command;
            cin >> command;
            if (command == "exit") {
                break;
            }
            // ...
        }
    }

    while (1 && !isVector) {
        string command;
        cin >> command;
        if (command == "exit") {
            break;
        }
        if (command == "push") {
            type item;
            cin >> item;
            int priority;
            cin >> priority;
            PQ.pushElem(item,priority);
        }
        // ans so on
    }
    cout << "Do you want to run the test again? y/n";
    string command;
    cin >> command;
    if (command == "y") {
        driverFunction();
    } else if (command == "n") {
        "Goodbye\n";
    }
    cout << "Good luck\n";
}

int main() {

    PriorityQueueList<int> Heap;
    int d = 3;
    Heap.pushElem(d);
    return 0;
}
