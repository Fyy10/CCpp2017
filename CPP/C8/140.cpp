#include "140.h"

Clock::Clock(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
    if (h >= 24 || h < 0)
        hour = 0;
    if (m >= 60 || m < 0)
        minute = 0;
    if (s >= 60 || s < 0)
        second = 0;
}

void Clock::SetAlarm(int h, int m, int s)
{
    Ahour = h;
    Aminute = m;
    Asecond = s;
    if (h >= 24)
        Ahour = 0;
    if (m >= 60)
        Aminute = 0;
    if (s >= 60)
        Asecond = 0;
}

void Clock::run()
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
        if (minute == 60)
        {
            minute = 0;
            hour++;
            if (hour == 24)
                hour = 0;
        }
    }
    if (Asecond == second && Aminute == minute && Ahour == hour)
    {
        cout << "Plink!plink!plink!..." << endl;
    }
}

int main()
{
    Clock c(2, 3, 4);
    c.SetAlarm(2, 3, 5);
    c.ShowTime();
    c.run();
    return 0;
}
