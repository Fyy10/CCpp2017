# Stack

- [Stack](#stack)
  - [Member functions](#member-functions)
    - [Stack(int)](#stackint)
    - [void push(const T\&)](#void-pushconst-t)
    - [void pop()](#void-pop)
    - [T top()](#t-top)
    - [bool empty()](#bool-empty)
    - [int size()](#int-size)
    - [int capacity()](#int-capacity)
    - [void clear()](#void-clear)

A C++ implementation of stack.

## Member functions

### Stack(int)

Construct the stack with the given capacity. The default capacity is `1`.

```cpp
Stack<int> s(10);
```

### void push(const T&)

Push an element onto the top of the stack.

```cpp
Stack<int> s;
s.push(1);
s.push(3);
```

### void pop()

Pop the top element from the stack.

```cpp
Stack<int> s;
s.push(2);
s.pop();
```

### T top()

Retrieve the top element from the stack.

```cpp
Stack<int> s;
s.push(5);
s.top();    // 5
```

### bool empty()

Check if the stack is empty.

```cpp
Stack<int> s;
s.empty();  // true
s.push(1);
s.empty();  // false
```

### int size()

Return the number of elements stored in the stack.

```cpp
Stack<int> s;
s.size();   // 0
s.push(1);
s.size();   // 1
s.push(3);
s.size();   // 2
```

### int capacity()

Return the maximum size of stack before reallocating new memory.

```cpp
Stack<int> s(10);
s.size();       // 0
s.capacity();   // 10
```

### void clear()

Clear the stack, pop all the elements.

```cpp
Stack<int> s;
s.push(1);
s.push(2);
s.size();   // 2
s.clear();
s.size();   // 0
```
