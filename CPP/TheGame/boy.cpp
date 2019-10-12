#include "boy.h"

boy::boy(const char* imgName, int x, int y, int step, int selfHeight, int selfWidth):human(imgName, x, y, step, selfHeight, selfWidth)
{
}

boy::boy(boy& b):human(b)
{
}

boy::~boy()
{
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
