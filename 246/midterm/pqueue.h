#pragma once

#include <list>
using namespace std;

template <typename T>
class PQueue {
protected:
    list<pair<int,T>> queue;

public:
    PQueue() {};

    T pop() {
        auto x=this->queue.front();
        this->queue.pop_front();
        return x.second;
    }

    virtual void insert(int priority, T val) = 0;
};

template <typename T>
    class DescendingPQueue : public PQueue<T> {
        using PQueue<T>::PQueue;
        public : void insert(int priority, T val) {
            pair<int, T> value;
            value.first = priority;
            value.second = val;
            this->queue.push_back(value);
            this->queue.sort();
            this->queue.reverse();
        }
};

template <typename T>
class AscendingPQueue : public PQueue<T> {
    using PQueue<T>::PQueue;
    public : void insert(int priority, T val) {
        pair<int, T> value;
        value.first = priority;
        value.second = val;
        this->queue.push_back(value);
        this->queue.sort();
    }
};
