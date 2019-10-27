#include "iostream"

using namespace std;

class timer
{
public:
	timer();

	void increase();
	void reset();
	void pause();
	void start();
	void display()
    {
        cout << "Now:" << hour << ":" << minute << ":" << second << endl;
		cout << "The total second is: " << totalsecond << endl;
	}
private:
	int hour;   //时
	int minute;  //分
	int second;  //秒
	int totalsecond;
	bool disabled;
};
