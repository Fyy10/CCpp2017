#include "iostream"
#include "array.h"

using namespace std;

int main()
{
	int n1, n2;
	cin >> n1 >> n2;
	Array<int> IntArr(n1);
	Array<double> DoubleArr(n2);
	for (int i = 0; i < n1; i++)
	{
		IntArr[i] = i + 1;
	}
	for (int i = 0; i < n2; i++)
	{
		DoubleArr[i] = (double)(i + 1) + 0.1;
	}
	cout << IntArr << endl;
	cout << DoubleArr << endl;
	return 0;
}
