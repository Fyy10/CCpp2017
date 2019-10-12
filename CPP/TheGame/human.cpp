#include "human.h"

point::point(int px, int py)
{
    x = px;
    y = py;
}

point::point(point& p)
{
    x = p.x;
    y = p.y;
}

point::~point()
{
}

human::human(const char* imgName, int x, int y, int step, int selfHeight, int selfWidth)
{
    loadImage(imgName, &img);
    pos.x = x;
    pos.y = y;
    this->step = step;
    this->selfHeight = selfHeight;
    this->selfWidth = selfWidth;
}

human::human(human& h)
{
    img = h.img;
    pos = h.pos;
    step = h.step;
    selfHeight = h.selfHeight;
    selfWidth = h.selfWidth;
}

human::~human()
{
}

int human::interact(human& obj)
{
    return 0;
}

int human::draw()
{
    putImageScale(&img, pos.x, pos.y, selfWidth, selfHeight);
    return 0;
}
