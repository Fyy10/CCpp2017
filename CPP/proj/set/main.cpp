#include "set.h"
#include "iostream"

using namespace std;

int main()
{
	MySet s(10);
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
	cout << (s1 == s2) << endl;
	return 0;
}
