#include "boy.h"

boy::boy(const char* imgName, int x, int y, int step, int selfHeight, int selfWidth):human(imgName, x, y, step, selfHeight, selfWidth)
{
	score = 0;
	life = 3;
}

boy::boy(boy& b):human(b)
{
	score = b.score;
}

boy::~boy()
{
}

int boy::incScore()
{
	score++;
	selfHeight += 1;
	selfWidth += 1;
	return 0;
}

int boy::getScore()
{
	return score;
}

int boy::loseLife()
{
	if (life) life--;
	return 0;
}

int boy::getLife()
{
	return life;
}

int boy::addLife()
{
	life++;
	return 0;
}

int boy::key_move(int key)
{
    switch(key)
    {
        case VK_UP:
            {
                pos.y -= step;
                if (pos.y < 0) pos.y = 0;
                break;
            }
        case VK_LEFT:
            {
                pos.x -= step;
                if (pos.x < 0) pos.x = 0;
                break;
            }
        case VK_DOWN:
            {
                int winH = getHeight();
                pos.y += step;
                if (pos.y > winH - selfHeight) pos.y = winH - selfHeight;
                break;
            }
        case VK_RIGHT:
            {
                int winW = getWidth();
                pos.x += step;
                if (pos.x > winW - selfWidth) pos.x = winW - selfWidth;
                break;
            }
        default:;
    }
    return 0;
}
