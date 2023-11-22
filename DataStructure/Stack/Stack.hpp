#ifndef STACK_HPP
#define STACK_HPP

#include <cstdlib>
#include <iostream>

using namespace std;

namespace consts {
    const int default_cap = 1;
}

template <class T>
class Stack {
private:
    T *arr;
    int cap;
    int len;

public:
    Stack(int=consts::default_cap);
    Stack(const Stack&);
    Stack(Stack&&);
    ~Stack();

    void push(const T&);
    void pop();
    T top();

    bool empty();
    int size();
    int capacity();
    void clear();
};

template <class T>
Stack<T>::Stack(int n) {
    // initialize cap and len
    cap = n;
    len = 0;

    // allocate memory for arr
    arr = (T*)malloc(sizeof(T) * cap);
    if (arr == nullptr) {
        cerr << "malloc failed" << endl;
        cap = 0;
        return;
    }
}

template <class T>
Stack<T>::Stack(const Stack& s) {
    // deep copy of stack data structure
    cap = s.cap;
    len = s.len;
    if (s.arr == nullptr) {
        cerr << "s.arr is nullptr" << endl;
        arr = nullptr;
        return;
    }

    arr = (T*)malloc(sizeof(T) * cap);
    if (arr == nullptr) {
        cerr << "malloc failed" << endl;
        return;
    }
    for (int i = 0; i < len; i++) {
        arr[i] = s.arr[i];
    }
}

template <class T>
Stack<T>::Stack(Stack&& s) {
    // shallow copy of stack data structure
    cap = s.cap;
    len = s.len;
    arr = s.arr;
    s.arr = nullptr;
}

template <class T>
Stack<T>::~Stack() {
    // release memory for arr
    free(arr);
}

template <class T>
void Stack<T>::push(const T& v) {
    // check if we need to realloc
    if (len == cap) {
        // double the size, could have other choices
        int new_cap = 2 * cap;
        if (cap == 0) {
            new_cap = consts::default_cap;
        }

        T *new_arr = (T*)realloc(arr, new_cap * sizeof(T));
        if (new_arr == nullptr) {
            cerr << "realloc failed" << endl;
            return;
        } else if (new_arr != arr) {
            // copy data
            for (int i = 0; i < cap; i++) {
                new_arr[i] = arr[i];
            }
            free(arr);
            this->arr = new_arr;
        }
        cap = new_cap;
    }

    arr[len] = v;
    len++;
}

template <class T>
void Stack<T>::pop() {
    if (len == 0) {
        cerr << "pop(): stack is empty" << endl;
        return;
    }
    len--;
}

template <class T>
T Stack<T>::top() {
    if (len == 0) {
        cerr << "top(): stack is empty" << endl;
        // what should we return here?
        return T();
    }

    if (arr == nullptr) {
        cerr << "arr is nullptr" << endl;
        return T();
    }

    return arr[len-1];
}

template <class T>
bool Stack<T>::empty() {
    return len == 0;
}

template <class T>
int Stack<T>::size() {
    return len;
}

template <class T>
int Stack<T>::capacity() {
    return cap;
}

template <class T>
void Stack<T>::clear() {
    len = 0;
}

#endif
