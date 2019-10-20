#include "girl.h"

girl::girl(const char* imgName, int x, int y, int step, int selfHeight, int selfWidth, int dx, int dy):human(imgName, x, y, step, selfHeight, selfWidth)
{
	dir.x = dx;
	dir.y = dy;
}

girl::girl(girl& g):human(g)
{
	this->dir = g.dir;
}

girl::~girl()
{
}

int girl::self_move()
{
	pos += dir;
	int winW = getWidth();
	int winH = getHeight();
	if (pos.x < 0 || pos.x > winW - selfWidth) dir.x *= -1;
	if (pos.y < 0 || pos.y > winH - selfHeight) dir.y *= -1;
    return 0;
}
