#ifndef SCORE_H

#define SCORE_H

#include "string"

const int NORMAL_SIZE = 100;

enum Status
{
    SUCCESS,
    FAIL,
    ERR
};

struct student
{
    std::string name;
    int score;
    bool valid;
};

class ScoreBook
{
    public:
        ScoreBook(int n = NORMAL_SIZE);
        ScoreBook(ScoreBook&);
        ~ScoreBook();

        void display();
        Status add();
        Status del();
        Status insert();
        Status clear();
    private:
        student *stu;
        int size;
};

#endif
