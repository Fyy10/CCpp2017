#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T> class RingBuffer;
template <class T> ostream& operator<<(ostream&, const RingBuffer<T>&);

template <class T>
class RingBuffer {
private:
    T *arr;
    int cap;
    int len;
    int head;
    int tail;

public:
    RingBuffer(int=10);
    RingBuffer(const RingBuffer&);
    RingBuffer(RingBuffer&&);
    ~RingBuffer();

    bool push_back(const T&);
    T pop_front();
    T& front();
    T& back();

    bool empty();
    int size();
    int capacity();
    void clear();

    friend ostream& operator<< <T>(ostream&, const RingBuffer<T>&);
};

template <class T>
RingBuffer<T>::RingBuffer(int n) {
    // initialize cap and len
    cap = n;
    len = 0;
    head = 0;
    tail = 0;

    // allocate memory for arr
    arr = (T*)malloc(sizeof(T) * cap);
    if (arr == nullptr) {
        cerr << "RingBuffer(int): malloc failed with n=" << n << endl;
        cap = 0;
        return;
    }
}

template <class T>
RingBuffer<T>::RingBuffer(const RingBuffer& rb) {
    // deep copy of ring buffer data structure
    cap = rb.cap;
    len = rb.len;
    head = rb.head;
    tail = rb.tail;
    if (rb.arr == nullptr) {
        cerr << "RingBuffer(const&): rb.arr is nullptr" << endl;
        arr = nullptr;
        return;
    }

    // allocate memory for arr
    arr = (T*)malloc(sizeof(T) * cap);
    if (arr == nullptr) {
        cerr << "RingBuffer(const&): malloc failed" << endl;
        cap = 0;
        return;
    }

    // copy elements from rb.arr to arr
    memcpy(arr, rb.arr, sizeof(T) * cap);
}

template <class T>
RingBuffer<T>::RingBuffer(RingBuffer&& rb) {
    // shallow copy of ring buffer data structure
    cap = rb.cap;
    len = rb.len;
    head = rb.head;
    tail = rb.tail;
    arr = rb.arr;
    rb.arr = nullptr;
}

template <class T>
RingBuffer<T>::~RingBuffer() {
    if (arr != nullptr) {
        free(arr);
    }
}

template <class T>
bool RingBuffer<T>::push_back(const T& val) {
    if (len == cap) {
        cerr << "RingBuffer::push_back: buffer is full" << endl;
        return false;
    }

    arr[tail] = val;
    tail = (tail + 1) % cap;
    len++;
    return true;
}

template <class T>
T RingBuffer<T>::pop_front() {
    if (len == 0) {
        cerr << "RingBuffer::pop_front: buffer is empty" << endl;
        return T();
    }

    T val = arr[head];
    head = (head + 1) % cap;
    len--;
    return val;
}

template <class T>
T& RingBuffer<T>::front() {
    if (len == 0) {
        cerr << "RingBuffer::front: buffer is empty" << endl;
        return arr[0];
    }

    return arr[head];
}

template <class T>
T& RingBuffer<T>::back() {
    if (len == 0) {
        cerr << "RingBuffer::back: buffer is empty" << endl;
        return arr[0];
    }

    return arr[(tail - 1 + cap) % cap];
}

template <class T>
bool RingBuffer<T>::empty() {
    return len == 0;
}

template <class T>
int RingBuffer<T>::size() {
    return len;
}

template <class T>
int RingBuffer<T>::capacity() {
    return cap;
}

template <class T>
void RingBuffer<T>::clear() {
    len = 0;
    head = 0;
    tail = 0;
}

template <class T>
ostream& operator<<(ostream& os, const RingBuffer<T>& rb) {
    os << "RingBuffer: ";
    for (int i = 0; i < rb.len; i++) {
        os << rb.arr[(rb.head + i) % rb.cap];
        if (i < rb.len - 1) {
            os << ", ";
        }
    }
    return os;
}

#endif
