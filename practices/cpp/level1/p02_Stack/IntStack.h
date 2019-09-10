#ifndef INT_STACK_H

#define INT_STACK_H

const int MAX_SIZE = 10;

enum Status
{
    SUCCESS,
    FAIL
};

class IntStack
{
    public:
        IntStack();
        IntStack(IntStack&);
        ~IntStack();

        Status push(int);
        int pop();
        bool empty();
        bool full();
    private:
        int *st;
        int top;
};

#endif
