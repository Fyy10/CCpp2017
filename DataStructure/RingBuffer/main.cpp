#include "RingBuffer.hpp"
#include <iostream>

using namespace std;

int main() {
    RingBuffer<int> rb(5);
    for (int i = 0; i < 5; i++) {
        rb.push_back(i+20);
    }

    rb.push_back(25); // err: push_back() full

    // RingBuffer: 20, 21, 22, 23, 24
    // 20, 21, 22, 23, 24
    cout << rb << endl;
    for (int i = 0; i < 5; i++) {
        cout << rb.front() << endl;
        rb.pop_front();
    }

    // empty ring buffer here
    cout << rb.front() << endl; // err: front() empty, returns arr[0] here so prints 20
    cout << rb.back() << endl; // err: back() empty, returns arr[0] here so prints 20
    rb.pop_front(); // err: pop_front() empty

    rb.push_back(10);
    cout << rb.front() << endl; // 10
    rb.push_back(20);
    cout << rb.front() << endl; // 10
    cout << rb.back() << endl; // 20

    rb.pop_front();
    rb.push_back(30);

    cout << rb << endl; // RingBuffer: 20, 30

    return 0;
}
