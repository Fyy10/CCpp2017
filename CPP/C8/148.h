#ifndef C148_H

#define C148_H

#include "iostream"
#include "string"

enum Status
{
    OK,
    NO,
    ERR
};

class User
{
    public:
        User(std::string, std::string);
        User(User&);
        ~User();
        Status Login(std::string, std::string);
    private:
        std::string name;
        std::string pass;
};

#endif
