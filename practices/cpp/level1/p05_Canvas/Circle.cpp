#include "iostream"
#include "Circle.h"

Circle::Circle(double x, double y, double R)
{
    this->x = x;
    this->y = y;
    this->R = R;
}

Circle::Circle(Circle &cir)
{
    x = cir.x;
    y = cir.y;
    R = cir.R;
}

Circle::~Circle()
{
}

void Circle::display()
{
    std::cout << "******Circle******\n";
    std::cout << "Position: x = " << x << " y = " << y << std::endl;
    std::cout << "Radius: R = " << R << std::endl;
}

void Circle::moveto(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Circle::setR(double R)
{
    this->R = R;
}
