#ifndef RECT_H

#define RECT_H

class Rect
{
    public:
        Rect(double l = 0.0, double h = 0.0, double x = 0.0, double y = 0.0);
        Rect(Rect&);
        ~Rect();

        void display();
        void moveto(double x = 0.0, double y = 0.0);
        void setlh(double l = 0.0, double h = 0.0);
    private:
        double l, h;
        double x, y;
};

#endif
