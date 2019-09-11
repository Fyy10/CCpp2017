#ifndef QUEUE_H

#define QUEUE_H

#include "iostream"

const int MAX_SIZE = 100;

enum Status
{
    SUCCESS,
    FAIL,
    ERR
};

class queue
{
    public:
        queue();
        queue(queue&);
        ~queue();

        Status append(int a);
        Status clear();
        int pop();
        bool empty();
        bool full();
    private:
        int *q;
        int p1, p2;
        int size;
        int nxt(int p)
        {
            return (p + 1) % MAX_SIZE;
        }
};

#endif
