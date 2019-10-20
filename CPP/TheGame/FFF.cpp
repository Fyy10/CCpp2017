#include "FFF.h"

FFF::FFF(const char* imgName, int x, int y, int step, int selfHeight, int selfWidth, int dx, int dy):human(imgName, x, y, step, selfHeight, selfWidth)
{
	dir.x = dx;
	dir.y = dy;
}

FFF::FFF(FFF& f):human(f)
{
	this->dir = f.dir;
}

FFF::~FFF()
{
}

int FFF::self_move()
{
	pos += dir;
	int winW = getWidth();
	int winH = getHeight();
	if (pos.x < 0 || pos.x > winW - selfWidth) dir.x *= -1;
	if (pos.y < 0 || pos.y > winH - selfHeight) dir.y *= -1;
    return 0;
}
