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

void point::operator += (const point& p)
{
	x += p.x;
	y += p.y;
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
	//if (abs(pos.x - obj.pos.x) <= selfWidth && abs(pos.y - obj.pos.y) <= selfHeight) return 1;
	bool L = 0, R = 0, U = 0, D = 0;
	if ((pos.x > obj.pos.x) && (pos.x - obj.pos.x <= obj.selfWidth)) L = 1;
	if ((obj.pos.x > pos.x) && (obj.pos.x - pos.x <= selfWidth)) R = 1;
	if ((pos.y > obj.pos.y) && (pos.y - obj.pos.y <= obj.selfHeight)) U = 1;
	if ((obj.pos.y > pos.y) && (obj.pos.y - pos.y <= selfHeight)) D = 1;
	if ((L&&U)||(L&&D)||(R&&U)||(R&&D)) return 1;
    return 0;
}

int human::draw()
{
    putImageTransparent(&img, pos.x, pos.y, selfWidth, selfHeight, WHITE);
    return 0;
}
