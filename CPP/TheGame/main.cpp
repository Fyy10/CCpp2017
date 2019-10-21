#include "main.h"

using namespace std;

set<girl*> girls;               //the set of girls
set<girl*>::iterator itgirl;    //the iterator of set of girls
set<FFF*> FFFs;                 //the set of FFFs
set<FFF*>::iterator itFFF;      //the iterator of set of FFFs
//stack<star*> stars;				//the set of stars
boy* pusr;

const int WIDTH = 800;      //size of new window
const int HEIGHT = 500;
const int imgHeight = 100; //size of new image
const int imgWidth = 100;
const char* TITLE = "TheGame";      //title of new window

const int MAXG = 20;        //max number of girl
const int MAXF = 1;         //max number of FFF
//const int MAXS = 2;			//max number of star

int initALL();
void usrInput(int, int);    //get user's input of direction(up down left right)
void objAutoMove(int);		//time event of moving objects
int paint();
int paintEnd();
int randomX();
int randomY();
int endGame();				//close all time events and disable keyboard events(now being done)

bool gameOver = 0;

int Setup()
{
    initALL();
    //paint();
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
    registerTimerEvent(objAutoMove);
    startTimer(0, 1000);		//generate new girl
    startTimer(1, 2000);		//generate new FFF
    startTimer(2, 50);			//girl move
    startTimer(3, 100);			//FFF move
    startTimer(4, 5000);		//generate new star
    registerKeyboardEvent(usrInput);
    paint();
    paintEnd();
    return 0;
}

void usrInput(int key, int event)
{
    if (event != KEY_DOWN || gameOver) return;
    pusr->key_move(key);
    for (itgirl = girls.begin(); itgirl != girls.end(); itgirl++)
    {
        if (pusr->interact(**itgirl))
        {
            delete *itgirl;
            girls.erase(itgirl);
            pusr->incScore();
        }
    }
    for (itFFF = FFFs.begin(); itFFF != FFFs.end(); itFFF++)
	{
		if (pusr->interact(**itFFF))
		{
			if (pusr->getLife())
			{
				pusr->loseLife();
				delete *itFFF;
				FFFs.erase(itFFF);
			}
			else
			{
				delete pusr;
				pusr = NULL;
			}
		}
	}
    paint();
}

void objAutoMove(int id)
{
	switch (id)
	{
	case 0:
		if (girls.size() < MAXG)
		{
			girl* tmp = new girl("girl.jpg", randomX(), randomY(), 10, imgHeight, imgWidth, randomX() % 5 + 1, randomY() % 5 + 1);
			girls.insert(tmp);
		}
		break;
	case 1:
		if (FFFs.size() < MAXF)
		{
			FFF* tmp = new FFF("FFF.jpg", randomX(), randomY(), 10, imgHeight, imgWidth, randomX() % 5 + 1, randomY() % 5 + 1);
			FFFs.insert(tmp);
		}
		break;
	case 2:
		for (itgirl = girls.begin(); itgirl != girls.end(); itgirl++)
		{
			(*itgirl)->self_move();
			if (pusr->interact(**itgirl))
			{
				delete *itgirl;
				girls.erase(itgirl);
				pusr->incScore();
			}
		}
		paint();
		break;
	case 3:
		for (itFFF = FFFs.begin(); itFFF != FFFs.end(); itFFF++)
		{
			(*itFFF)->self_move();
			if (pusr->interact(**itFFF))
			{
				if (pusr->getLife())
				{
					pusr->loseLife();
					delete *itFFF;
					FFFs.erase(itFFF);
				}
				else
				{
					delete pusr;
					pusr = NULL;
				}
			}
		}
		paint();
		break;
	case 4:
		break;
	default:;
	}
}

int paint()
{
    beginPaint();
    clearDevice();
    for (itgirl = girls.begin(); itgirl != girls.end(); itgirl++)
	{
		(*itgirl)->draw();
	}
	for (itFFF = FFFs.begin(); itFFF != FFFs.end(); itFFF++)
	{
		(*itFFF)->draw();
	}
	if (pusr)
	{
		pusr->draw();
	}
	else
	{
		endGame();
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

int paintEnd()
{
	beginPaint();
	clearDevice();
	//output the final information of TheGame
	paintText(10, 10, "Gameover");
	endPaint();
	return 0;
}

int endGame()
{
	for (int i = 0; i <= 4; i++) cancelTimer(i);
	gameOver = 1;
	paintEnd();
	return 0;
}
