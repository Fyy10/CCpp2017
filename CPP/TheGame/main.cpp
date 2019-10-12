#include "main.h"

using namespace std;

set<girl*> girls;               //the set of girls
set<girl*>::iterator itgirl;    //the iterator of set of girls
set<FFF*> FFFs;                 //the set of FFFs
set<FFF*>::iterator itFFF;      //the iterator of set of FFFs
boy* pusr;

const int WIDTH = 800;      //size of new window
const int HEIGHT = 500;
const int imgHeight = 100; //size of new image
const int imgWidth = 100;
const char* TITLE = "TheGame";      //title of new window

const int MAXG = 20;        //max number of girl
const int MAXF = 5;         //max number of FFF

int initALL();
void usrInput(int, int);    //get user's input of direction(up down left right)
int paint();
int randomX();
int randomY();

int Setup()
{
    initALL();
    paint();
    registerKeyboardEvent(usrInput);
    return 0;
}

int initALL()
{
    initWindow(TITLE, 400, 200, WIDTH, HEIGHT);
    /*setPenColor(BLACK);
    setBrushColor(BLUE);
    setTextBkColor(WHITE);
    setTextColor(BLACK);
    setTextSize(20);*/
    srand((unsigned)time(NULL));
    int x = randomX(), y = randomY(), step = 10;
    pusr = new boy("boy.jpg", x, y, step, imgHeight, imgWidth);
    x = randomX();
    y = randomY();
    step = 5;
    girl* tmp = new girl("girl.jpg", x, y, step);
    girls.insert(tmp);
    return 0;
}

void usrInput(int key, int event)
{
    if (event != KEY_DOWN) return;
    pusr->key_move(key);
    for (itgirl = girls.begin(); itgirl != girls.end(); itgirl++)
    {
        if (pusr->interact(**itgirl))
        {
            delete *itgirl;
            girls.erase(itgirl);
            s:int x = randomX();
            int y = randomY();
            int step = 5;
            girl* tmp = new girl("girl.jpg", x, y, step);
            if (pusr->interact(*tmp)) goto s;
            girls.insert(tmp);
        }
    }
    paint();
}

int paint()
{
    beginPaint();
    clearDevice();
    pusr->draw();
    for (itgirl = girls.begin(); itgirl != girls.end(); itgirl++)
	{
		(*itgirl)->draw();
	}
    //paintText(0, 0, "Welcome to TheGame!");
    endPaint();
    return 0;
}

int randomX()
{
	int tmp = rand() % WIDTH;
    if (tmp > WIDTH - imgWidth) tmp = WIDTH - imgWidth;
    return tmp;
}

int randomY()
{
	int tmp = rand() % HEIGHT;
    if (tmp > HEIGHT - imgHeight) tmp = HEIGHT - imgHeight;
    return tmp;
}
