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

bool opp(ScoreBook&);

int main()
{
    ScoreBook s1(10);
    while (opp(s1));
    return 0;
}

bool opp(ScoreBook &s)
{
    system("clear");
    std::cout << "Which option would you like to choose?\n";
    std::cout << "1: Display all information\n2: Add student\n3: Delete student\n4: Insert scores\n5: clear\n6: exit\n";
    int opt;
    std::cin >> opt;
    switch(opt)
    {
        case 1:
            {
                s.display();
                break;
            }
        case 2:
            {
                s.add();
                break;
            }
        case 3:
            {
                s.del();
                break;
            }
        case 4:
            {
                s.insert();
                break;
            }
        case 5:
            {
                s.clear();
                break;
            }
        default: return false;
    }
    return true;
}
