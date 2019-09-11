#include "iostream"
#include "Rect.h"

Rect::Rect(double l, double h, double x, double y)
{
    this->l = l;
    this->h = h;
    this->x = x;
    this->y = y;
}

Rect::Rect(Rect &rec)
{
    l = rec.l;
    h = rec.h;
    x = rec.x;
    y = rec.y;
}

Rect::~Rect()
{
}

void Rect::display()
{
    std::cout << "******Rect******\n";
    std::cout << "Position: x = " << x << " y = " << y << std::endl;
    std::cout << "Length and Height: L = " << l << " H = " << h << std::endl;
}

void Rect::moveto(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Rect::setlh(double l, double h)
{
    this->l = l;
    this->h = h;
}
