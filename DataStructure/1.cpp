#include "iostream"
#include "cstring"
#include "cstdlib"
using namespace std;

//extern int RandInt(int i, int j);

int RandInt(int i, int j)
{
	return rand() % (j-i+1) + i;
}

void RandomPermutation1(int n)
{
	if (n <= 0)
	{
		cout << "error";
		return;
	}
	int *ans = new int[n];
	for (int i = 0; i < n; i++)
	{
		bool flag = 1;
		while (flag)
		{
			int tmp = RandInt(1, n);
			int j;
			for (j = 0; j < i; j++)
			{
				if (ans[j] == tmp) break;
			}
			if (j < i) continue;
			ans[i] = tmp;
			flag = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << ",";
	}
	cout << 0;
	delete []ans;
}

void RandomPermutation2(int n)
{
	if (n <= 0)
	{
		cout << "error";
		return;
	}
	int *used = new int[n+1];
	int *ans = new int[n];
	for (int i = 0; i <= n; i++) used[i] = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp = RandInt(1, n);
		while (used[tmp]) tmp = RandInt(1, n);
		ans[i] = tmp;
		used[tmp] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << ",";
	}
	cout << 0;
	delete []ans;
	delete []used;
}

void RandomPermutation3(int n)
{
	if (n <= 0)
	{
		cout << "error";
		return;
	}
	int *ans = new int[n];
	for (int i = 0; i < n; i++) ans[i] = i + 1;
	for (int i = 1; i < n; i++)
	{
		int r = RandInt(0, i);
		int tmp = ans[i];
		ans[i] = ans[r];
		ans[r] = tmp;
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << ",";
	}
	cout << 0;
	delete []ans;
}

int main()
{
	int n = 0;
	while (n != -1)
	{
		cin >> n;
		RandomPermutation1(n);
		cout << endl;
		RandomPermutation2(n);
		cout << endl;
		RandomPermutation3(n);
		cout << endl;
	}
	return 0;
}
