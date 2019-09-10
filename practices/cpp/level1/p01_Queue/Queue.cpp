#include "Queue.h"

queue::queue()
{
    q = new int[MAX_SIZE];
    p1 = p2 = 0;
    size = 0;
}

queue::queue(queue &ql)
{
    q = new int[MAX_SIZE];
    p1 = ql.p1;
    p2 = ql.p2;
    size = ql.size;
    for (int i = p1; i != p2; i = nxt(i))
    {
        q[i] = ql.q[i];
    }
}

queue::~queue()
{
    delete []q;
}

Status queue::append(int a)
{
    if (full())
    {
        std::cout << "Error! The queue is already full! Appending failed!\n";
        return FAIL;
    }
    q[p2] = a;
    p2 = nxt(p2);
    size++;
    return SUCCESS;
}

int queue::pop()
{
    if (empty())
    {
        std::cout << "Error! The queue is now empty! Popping failed!\n";
        abort();
    }
    int ans = q[p1];
    p1 = nxt(p1);
    size--;
    return ans;
}

bool queue::empty()
{
    return size == 0;
}

bool queue::full()
{
    return size == MAX_SIZE;
}

int main()
{
    queue q1;
    char o;
    while ((o = getchar()) != '*')
    {
        if (o == 'a')
        {
            int a;
            std::cin >> a;
            q1.append(a);
        }
        if (o == 'p')
        {
            std::cout << q1.pop() << std::endl;
        }
    }
    return 0;
}
