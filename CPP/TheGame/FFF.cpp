#include "FFF.h"

FFF::FFF(const char* imgName, int x, int y, int step, int selfHeight, int selfWidth):human(imgName, x, y, step, selfHeight, selfWidth)
{
}

FFF::FFF(FFF& f):human(f)
{
}

FFF::~FFF()
{
}

int FFF::self_move()
{
    return 0;
}
