#include "iostream"
#include "IntStack.h"

IntStack::IntStack()
{
    st = new int[MAX_SIZE];
    top = 0;
}

IntStack::IntStack(IntStack &isl)
{
    st = new int[MAX_SIZE];
    top = isl.top;
    for (int i = 0; i != top; i++)
    {
        st[i] = isl.st[i];
    }
}

IntStack::~IntStack()
{
    delete []st;
}

Status IntStack::push(int a)
{
    if (full())
    {
        std::cout << "Error! The stack is already full! Pushing failed!\n";
        return FAIL;
    }
    st[top++] = a;
    return SUCCESS;
}

int IntStack::pop()
{
    if (empty())
    {
        std::cout << "Error! The stack is now empty! Popping failed!\n";
        abort();
    }
    return st[--top];
}

bool IntStack::empty()
{
    return top == 0;
}

bool IntStack::full()
{
    return top == MAX_SIZE;
}

int main()
{
    char o;
    IntStack is;
    while ((o = getchar()) != '*')
    {
        if (o == 'i')
        {
            int a;
            std::cin >> a;
            is.push(a);
        }
        if (o == 'o')
        {
            std::cout << is.pop() << std::endl;
        }
    }
    return 0;
}
