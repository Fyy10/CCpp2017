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
    int x, y, step;
    x = rand() % WIDTH;
    if (x > WIDTH - imgWidth) x = WIDTH - imgWidth;
    y = rand() % HEIGHT;
    if (y > HEIGHT - imgHeight) y = HEIGHT - imgHeight;
    step = 10;
    pusr = new boy("boy.jpg", x, y, step, imgHeight, imgWidth);
    girl* tmp = new girl("girl.jpg");
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
        }
    }
    paint();
}

int paint()
{
    beginPaint();
    clearDevice();
    pusr->draw();
    //paintText(0, 0, "Welcome to TheGame!");
    endPaint();
    return 0;
}
