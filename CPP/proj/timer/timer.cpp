#include "timer.h"

timer::timer()
{
	hour = minute = second = totalsecond = 0;
	disabled = false;
}

void timer::increase()
{
	if (disabled) return;
    second++;
	totalsecond++;
    if (second == 60)
    {
        second = 0;
        minute++;
        if (minute == 60)
        {
            minute = 0;
            hour++;
        }
    }
    if (hour == 24 && second > 0)
    {
		minute = second = 0;
		totalsecond--;
        cout << "Time limit exceeded!" << endl;
    }
}

void timer::reset()
{
	hour = minute = second = 0;
	disabled = false;
}

void timer::pause()
{
	disabled = true;
}

void timer::start()
{
	disabled = false;
}

int main()
{
    timer t;
	for (int i = 0; i < 100; i++)	//给计时器加上100s
	{
		t.increase();
	}
    t.display();
	t.pause();						//暂停计时器
	for (int i = 0; i < 100; i++)
	{
		t.increase();
	}
	t.display();					//因为暂停了所以读数不会变化
	t.start();						//开始计时器
	t.increase();
	t.display();					//此时能计时了
	t.reset();						//重置计时器（仅重置时分秒，不重置总秒数）
	t.display();
	for (int i  = 0; i < 24 * 3600 + 1; i++)	//最后一次计时会超出上限并报错
	{
		t.increase();
	}
	t.display();					//计时器达到24:0:0的计时上限
    return 0;
}
