#include "iostream"
#include "Score.h"

ScoreBook::ScoreBook(int n)
{
    stu = new student[n];
    size = n;
    for (int i = 0; i < size; i++)
    {
        stu[i].valid = false;
    }
}

ScoreBook::ScoreBook(ScoreBook &stub)
{
    size = stub.size;
    stu = new student[size];
    for (int i = 0; i < size; i++)
    {
        stu[i].name = stub.stu[i].name;
        stu[i].score = stub.stu[i].score;
        stu[i].valid = stub.stu[i].valid;
    }
}

ScoreBook::~ScoreBook()
{
    delete []stu;
}

void ScoreBook::display()
{
    for (int i = 0; i < size; i++)
    {
        if (stu[i].valid)
        {
            std::cout << std::endl;
            std::cout << "Number: " << i << std::endl;
            std::cout << "Name: " << stu[i].name << std::endl;
            std::cout << "Score: " << stu[i].score << std::endl;
        }
    }
    std::cout << "\nPress Enter to continue...\n";
    getchar();
    getchar();
}

Status ScoreBook::add()
{
    int p;
    for (p = 0; p < size; p++)
    {
        if (!stu[p].valid)
        {
            break;
        }
    }
    if (p == size)
    {
        std::cout << "Oops! The score book is full!\n";
        getchar();
        getchar();
        return FAIL;
    }
    std::cout << "Name: ";
    std::cin >> stu[p].name;
    std::cout << "Score: ";
    std::cin >> stu[p].score;
    stu[p].valid = true;
    return SUCCESS;
}

Status ScoreBook::del()
{
    std::cout << "Name: ";
    std::string str;
    std::cin >> str;
    for (int i = 0; i < size; i++)
    {
        if (stu[i].name == str)
        {
            stu[i].valid = false;
            return SUCCESS;
        }
    }
    std::cout << "No such student.\n";
    getchar();
    getchar();
    return FAIL;
}

Status ScoreBook::insert()
{
    char o = 'y';
    int p = 0;
    while (o == 'y')
    {
        while (stu[p].valid && p < size)
        {
            p++;
        }
        if (p == size)
        {
            std::cout << "Oops! The score book is full!\n";
            getchar();
            getchar();
            return FAIL;
        }
        std::cout << "Now the number is " << p << ".\n";
        std::cout << "Name: ";
        std::cin >> stu[p].name;
        std::cout << "Score: ";
        std::cin >> stu[p].score;
        stu[p].valid = true;
        std::cout << "Continue?(y/n)";
        getchar();
        o = getchar();
    }
    return SUCCESS;
}

Status ScoreBook::clear()
{
    for (int i = 0; i < size; i++)
    {
        stu[i].valid = false;
    }
}
