#ifndef BOY_H
#define BOY_H

#include "human.h"

class boy : public human
{
public:
    boy(const char*, int x = 0, int y = 0, int step = 10, int selfHeight = 100, int selfWidth = 100);
    boy(boy&);
    ~boy();

    int key_move(int);     //return 0
};
#endif // BOY_H
