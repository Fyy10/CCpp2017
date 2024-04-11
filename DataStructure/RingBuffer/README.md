# RingBuffer

- [RingBuffer](#ringbuffer)
  - [Member functions](#member-functions)
    - [RingBuffer(int)](#ringbufferint)
    - [bool push\_back(const T\&)](#bool-push_backconst-t)
    - [T pop\_front()](#t-pop_front)
    - [T\& front()](#t-front)
    - [T\& back()](#t-back)
    - [bool empty()](#bool-empty)
    - [int size()](#int-size)
    - [int capacity()](#int-capacity)
    - [void clear()](#void-clear)

A C++ implementation of a ring buffer.

## Member functions

### RingBuffer(int)

Construct the ring buffer with the given capacity. The default capacity is `10`.

```cpp
RingBuffer<int> rb(5);
```

### bool push_back(const T&)

Push an element to the back of the ring buffer.

```cpp
RingBuffer<int> rb;
rb.push_back(1);
rb.push_back(3);
```

### T pop_front()

Pop the front element from the ring buffer.

```cpp
RingBuffer<int> rb;
rb.push_back(2);
rb.pop_front(); // 2
```

### T& front()

Retrieve (and not remove) the front element.

```cpp
RingBuffer<int> rb;
rb.push_back(20);
rb.push_back(30);
rb.front(); // 20
```

### T& back()

Retrieve (and not remove) the back element.

```cpp
RingBuffer<int> rb;
rb.push_back(20);
rb.push_back(30);
rb.back(); // 30
```

### bool empty()

Check if the ring buffer is empty.

```cpp
RingBuffer<int> rb;
rb.empty();  // true
rb.push(1);
rb.empty();  // false
```

### int size()

Return the number of elements stored in the ring buffer.

```cpp
RingBuffer<int> rb;
rb.size();   // 0
rb.push(1);
rb.size();   // 1
rb.push(3);
rb.size();   // 2
```

### int capacity()

Return the maximum size of the ring buffer.

```cpp
RingBuffer<int> rb(10);
rb.size();       // 0
rb.capacity();   // 10
```

### void clear()

Clear the ring buffer, pop all the elements.

```cpp
RingBuffer<int> rb;
rb.push(1);
rb.push(2);
rb.size();   // 2
rb.clear();
rb.size();   // 0
```
