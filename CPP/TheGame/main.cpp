#include "main.h"

using namespace std;

//set<girl> girls;
//set<FFF> FFFs;
//boy user;

human usr("boy.bmp");

const int WIDTH = 800;
const int HEIGHT = 500;
const char* TITLE = "TheGame";

const int MAXG = 20;
const int MAXF = 5;

int initALL();
int paint();

int Setup()
{
    initALL();
    paint();
    return 0;
}

int initALL()
{
    initWindow(TITLE, 400, 200, WIDTH, HEIGHT);
    return 0;
}

int paint()
{
    beginPaint();

    //setPenColor(GREEN);     //�߽���
    //setBrushColor(RED);     //����
    //rectangle(0, 0, 400, 250);

    setTextColor(BLACK);
    setTextBkColor(WHITE);
    //setTextFont("����");
    paintText(100, 100, "hello world!");
    usr.draw();

    endPaint();
    return 0;
}
