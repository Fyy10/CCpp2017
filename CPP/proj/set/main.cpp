#include "set.h"
#include "iostream"

using namespace std;

int main()
{
	/*MySet s(10);
	cout << s << endl;
	s += 1;
	s += 2;
	cout << s << endl;
	s -= 1;
	cout << s << endl;
	MySet s1, s2;
	s1 += 1;
	s2 += 2;
	s = s1 | s2;
	cout << s << endl;
	s = s1 & s2;
	cout << s << endl;
	s1 += 2;
	cout << s1 << endl;
	s = s1 - s2;
	cout << s << endl;
	cout << (s <= s1) << endl;
	cout << (s1 == s2) << endl;*/
	MySet s1, s2;
	cout << "Please input the operation:" << endl;
	cout << "1: insert to set 1" << endl;
	cout << "2: insert to set 2" << endl;
	cout << "3: and s1, s2" << endl;
	cout << "4: or s1, s2" << endl;
	cout << "5: minus s1, s2" << endl;
	cout << "6: erase from set 1" << endl;
	cout << "7: erase from set 2" << endl;
	int o;
	while (cin >> o)
	{
		switch (o)
		{
			case 1:
				{
					int a;
					cout << "please input the number you want to insert:";
					while (cin >> a)
					{
						if (a == -1) break;
						s1 += a;
					}
					cout << "s1:" << s1 << endl;
					cout << "Done!" << endl;
					break;
				}
			case 2:
				{
					int a;
					cout << "please input the number you want to insert:";
					while (cin >> a)
					{
						if (a == -1) break;
						s2 += a;
					}
					cout << "s2:" << s2 << endl;
					cout << "Done!" << endl;
					break;
				}
			case 3:
				{
					cout << "s1 & s2:";
					cout << (s1 & s2) << endl;
					break;
				}
			case 4:
				{
					cout << "s1 | s2:";
					cout << (s1 | s2) << endl;
					break;
				}
			case 5:
				{
					cout << "s1 - s2:";
					cout << (s1 - s2) << endl;
					break;
				}
			case 6:
				{
					int a;
					cout << "please input the number you want to erase:";
					while (cin >> a)
					{
						if (a == -1) break;
						s1 -= a;
					}
					cout << "s1:" << s1 << endl; 
					cout << "Done!" << endl;
					break;
				}
			case 7:
				{
					int a;
					cout << "please input the number you want to erase:";
					while (cin >> a)
					{
						if (a == -1) break;
						s2 -= a;
					}
					cout << "s2:" << s2 << endl;
					cout << "Done!" << endl;
					break;
				}
			default:;
		}
	}
	return 0;
}
