#include "Stack.hpp"

#include <iostream>

using namespace std;

int main() {
    Stack<float> s;
    for (int i = 0; i < 100; i++) {
        s.push(i);
    }
    for (int i = 0; i < 100; i++) {
        cout << s.top() << endl;
        s.pop();
    }

    // empty stack here
    cout << s.top() << endl;
    s.pop();

    // empty stack here
    cout << s.top() << endl;

    s.push(10);
    cout << s.top() << endl; // 10
    s.pop();

    // throw bad alloc exception
    try {
        throw std::bad_alloc();
    } catch (const std::bad_alloc &e) {
        cout << e.what() << endl;
    }

    return 0;
}
