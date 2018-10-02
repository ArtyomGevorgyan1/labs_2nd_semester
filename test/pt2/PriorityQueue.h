#pragma once

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class PriorityQueue {
public:
    virtual T pullMaxKey() = 0;
    virtual T peekMaxKey() const = 0;
    virtual void pushElem(T, int) = 0;
    virtual bool isEmpty() const = 0;
    virtual ~PriorityQueue() {};
};
