#ifndef BOY_H
#define BOY_H

#include "human.h"

class boy : public human
{
	int score;
	int life;
public:
    boy(const char*, int x = 0, int y = 0, int step = 10, int selfHeight = 100, int selfWidth = 100);
    boy(boy&);
    ~boy();

    int incScore();			//return 0
    int getScore();
    int loseLife();			//return 0
    int getLife();
    int addLife();			//return 0
    int key_move(int);		//return 0
};
#endif // BOY_H
