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
