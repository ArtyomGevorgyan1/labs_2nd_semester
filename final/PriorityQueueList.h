#pragma once

#include "PriorityQueue.h"

template <typename T>
struct Node{
    Node<T>* next;
    pair<T,int> data;
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
            if (cur ->next && cur -> next -> data.second > res -> data.second) {
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
            if (cur -> next && cur -> next -> data.second > res -> data.second) {
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
    void pushElem(pair<T,int> data) {
        Node<T>* tmp = new Node<T>;
        tmp -> data.first = data.first;
        tmp -> data.second = data.second;
        tmp -> next = head;
        head = tmp;
        queueSize++;
    }
    bool isEmpty() const {
        return queueSize <= 0;
    }
private:
    void deleteNdElem(int index) {
        /*
        Node<T>* cur = head;
        for (int i = 0; i < index - 1 && cur -> next; i++) {
            cur = cur -> next;
        }
        Node<T>* tmp = cur -> next;
        if (tmp == nullptr) {
            delete cur;
            return;
        }
        cur -> next = cur -> next -> next;
        delete tmp;
        */
        Node<T>* tmp = head;
        if (index == 0) {
            head = head -> next;
            delete tmp;
            return;
        }
        for (int i = 0; tmp != nullptr && i < index - 1; i++) {
            tmp = tmp -> next;
        }
        Node<T>* next = tmp -> next -> next;
        delete tmp -> next;
        tmp -> next = next;
    }
    Node<T>* head;
    int queueSize;
};
