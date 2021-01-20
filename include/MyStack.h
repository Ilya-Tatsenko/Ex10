// Copyright 2021 Ilya Tatsenko
#pragma once
#include<vector>

template <class T>
class MyStack {
 private:
    std::vector<T>* mas;
    int length;

 public:
    explicit MyStack(int x) : length(x) {
        mas = new std::vector<T>;
        mas->reserve(x);
    }
    MyStack(const MyStack& x) {
        mas = x.mas;
        length = x.length;
    }
    ~MyStack() {
        delete mas;
        mas = nullptr;
    }
    T get() const {
        return mas->back();
    }
    T pop() {
        T p_ = mas->back();
        mas->pop_back();
        return p_;
    }
    void push(T x) {
        if (mas->empty() == 1) mas->insert(mas->begin(), x);
        else
            mas->push_back(x);
    }
    bool isFull() const {
        if (mas->size() == length) return true;
        else
            return false;
    }
    bool isEmpty() const {
        return mas->empty() == true;
    }
};
