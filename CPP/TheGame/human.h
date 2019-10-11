#ifndef HUMAN_H
#define HUMAN_H

#include "acllib.h"

class point
{
public:
    int x, y;
    point(int px = 0, int py = 0);
    point(point& p);
    ~point();
};

class human
{
    ACL_Image img;
    point pos;
    int step;       //²½³¤
    int selfHeight;
    int selfWidth;
public:
    human(const char*, int x = 0, int y = 0, int step = 10, int selfHeight = 100, int selfWidth = 100);
    human(human& h);
    ~human();

    int key_move(char);     //return 0
    //int auto_move();    //return 0
    int interact(human& obj);   //0:none    1:meet
    int draw();         //return 0
};

#endif // HUMAN_H
