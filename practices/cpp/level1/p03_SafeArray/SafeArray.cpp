#include "iostream"
#include "SafeArray.h"

SafeArray::SafeArray(int n)
{
    arr = new int[n];
    size = n;
}

SafeArray::SafeArray(SafeArray &sa)
{
    size = sa.size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = sa.arr[i];
    }
}

SafeArray::~SafeArray()
{
    delete []arr;
}

Status SafeArray::insert(int pos, int a)
{
    if (pos >= size || pos < 0)
    {
        std::cout << "Error! You are visiting an invalid address!\n";
        return FAIL;
    }
    arr[pos] = a;
    return SUCCESS;
}

int SafeArray::get(int pos)
{
    if (pos >= size || pos < 0)
    {
        std::cout << "Error! You are visiting an invalid address!\n";
        abort();
    }
    return arr[pos];
}

Status SafeArray::opp()
{
    char o;
    while ((o = getchar()) != '*')
    {
        if (o == 'i')
        {
            int p, a;
            std::cin >> p >> a;
            insert(p, a);
        }
        if (o == 'g')
        {
            int p;
            std::cin >> p;
            std::cout << get(p) << std::endl;
        }
    }
    return SUCCESS;
}

int main()
{
    SafeArray sa(2), sa2;
    sa.opp();
    sa2.opp();
    return 0;
}
