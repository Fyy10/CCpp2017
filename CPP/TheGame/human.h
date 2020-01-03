#ifndef HUMAN_H
#define HUMAN_H

#include "acllib.h"

class point
{
public:
    int x, y;
    point(int px = 0, int py = 0);
    point(point& p);
    ~point();

    void operator += (const point&);
};

class human
{
protected:
    ACL_Image img;
    point pos;
    int step;       //步长
    int selfHeight;
    int selfWidth;
public:
    human(const char*, int x = 0, int y = 0, int step = 10, int selfHeight = 100, int selfWidth = 100);
    human(human& h);
    //virtual ~human();
    ~human();

    int interact(human& obj);   //0:none    1:meet
    int draw();         //return 0

	//boy
    virtual int incScore(){return 0;};			//return 0
    virtual int getScore(){return 0;};
    virtual int loseLife(){return 0;};			//return 0
    virtual int getLife(){return 0;};
    virtual int addLife(){return 0;};			//return 0
    virtual int key_move(int){return 0;};		//return 0
	//girl & FFF
    virtual int self_move(){return 0;};
};

#endif // HUMAN_H
