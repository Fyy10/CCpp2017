#include "150.h"

Rectangle::Rectangle(float xx, float yy, float w, float h):Point(xx, yy)
{
    width = w;
    high = h;
}

float Rectangle::Area()
{
    return width * high;
}

Circle::Circle(float xx, float yy, float r):Point(xx, yy)
{
    radius = r;
}

float Circle::Area()
{
    return 3.14f * radius * radius;
}

int main()
{
    Rectangle rect(1, 2, 3, 4);
    Circle c(5, 6, 7);
    cout << rect.Area() << endl << c.Area();
    return 0;
}
