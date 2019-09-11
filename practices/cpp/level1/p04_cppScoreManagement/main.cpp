#include "main.h"

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
