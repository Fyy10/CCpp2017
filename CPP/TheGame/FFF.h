#ifndef FFF_H
#define FFF_H

#include "human.h"

class FFF : public human
{
public:
    FFF(const char*, int x = 0, int y = 0, int step = 10, int selfHeight = 100, int selfWidth = 100);
    FFF(FFF&);
    ~FFF();

    int self_move();
};
#endif // FFF_H
