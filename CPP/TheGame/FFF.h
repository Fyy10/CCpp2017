#ifndef FFF_H
#define FFF_H

#include "human.h"

class FFF : public human
{
	point dir;
public:
    FFF(const char*, int x = 0, int y = 0, int step = 10, int selfHeight = 100, int selfWidth = 100, int dx = 0, int dy = 0);
    FFF(FFF&);
    ~FFF();

    int self_move();
};
#endif // FFF_H
