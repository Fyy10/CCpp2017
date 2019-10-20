#ifndef GIRL_H
#define GIRL_H

#include "human.h"

class girl : public human
{
	point dir;		//direction of moving
public:
    girl(const char*, int x = 0, int y = 0, int step = 10, int selfHeight = 100, int selfWidth = 100, int dx = 0, int dy = 0);
    girl(girl&);
    ~girl();

    int self_move();
};
#endif // GIRL_H
