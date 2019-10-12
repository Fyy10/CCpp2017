#include "girl.h"

girl::girl(const char* imgName, int x, int y, int step, int selfHeight, int selfWidth):human(imgName, x, y, step, selfHeight, selfWidth)
{
}

girl::girl(girl& g):human(g)
{
}

girl::~girl()
{
}

int girl::self_move()
{
    return 0;
}
