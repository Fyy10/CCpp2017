#include "148.h"

User::User(std::string uname, std::string upass)
{
    this->name = uname;
    this->pass = upass;
}

User::User(User &usr)
{
    this->name = usr.name;
    this->pass = usr.pass;
}

User::~User()
{
}

Status User::Login(std::string uname, std::string upass)
{
    if (name == uname && pass == upass)
    {
        return OK;
    }
    else
    {
        return NO;
    }
    return ERR;
}

int main()
{
    std::string name, pass;
    std::cin >> name >> pass;
    User u1(name, pass);
    std::cin >> name >> pass;
    if (u1.Login(name, pass) == OK)
    {
        std::cout << "Success Login!\n";
    }
    else
    {
        std::cout << "Login failed!\n";
    }
    return 0;
}
