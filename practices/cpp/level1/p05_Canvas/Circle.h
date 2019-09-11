#ifndef CIRCLE_H

#define CIRCLE_H

class Circle
{
    public:
        Circle(double x = 0.0, double y = 0.0, double R = 0.0);
        Circle(Circle&);
        ~Circle();

        void display();
        void moveto(double, double);
        void setR(double);
    private:
        double x, y;
        double R;
};

#endif
