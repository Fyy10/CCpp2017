#include "set.h"
#include "iostream"
#include "cassert"
#include "algorithm"

using namespace std;

MySet::MySet(int ns)
{
	ps = new int[ns];
	n = ns;
	size = 0;
}

MySet::MySet(MySet& ms)
{
	size = ms.size;
	n = ms.n;
	ps = new int[n];
	for (int i = 0; i < size; i++)
	{
		ps[i] = ms.ps[i];
	}
}

MySet::~MySet()
{
	if (ps != NULL)
	{
		delete []ps;
	}
}

bool MySet::find(int x) const
{
	for (int i = 0; i < size; i++)
	{
		if (ps[i] == x)
		{
			return true;
		}
	}
	return false;
}

Status MySet::insert(int x)
{
	if (full())
	{
		expand(n);
	}
	if (!find(x))
	{
		ps[size++] = x;
	}
	return SUCCESS;
}

Status MySet::erase(int x)
{
	if (empty())
	{
		return FAIL;
	}
	int i;
	for (i = 0; i < size; i++)
	{
		if (ps[i] == x)
		{
			break;
		}
	}
	for (int j = i + 1; j < size; j++)
	{
		ps[j-1] = ps[j];
	}
	size--;
	return SUCCESS;
}

Status MySet::expand(int a)
{
	n += a;
	int* tmp = new int[n];
	if (tmp == NULL)
	{
		return FAIL;
	}
	for (int i = 0; i < size; i++)
	{
		tmp[i] = ps[i];
	}
	delete []ps;
	ps = tmp;
	return SUCCESS;
}

void MySet::clear()
{
	size = 0;
}

void MySet::display() const
{
	cout << "{";
	for (int i = 0; i < size-1; i++)
	{
		cout << ps[i] << ",";
	}
	if (size != 0)
	{
		cout << ps[size-1];
	}
	cout << "}";
}

//MySet MySet::SetUnion(const MySet& s) const
MySet MySet::operator | (const MySet& s) const
{
	MySet ans(n + s.n);
	for (int i = 0; i < size; i++)
	{
		ans.insert(ps[i]);
	}
	for (int i = 0; i < s.size; i++)
	{
		ans.insert(s.ps[i]);
	}
	return ans;
}

//MySet MySet::SetCross(const MySet& s) const
MySet MySet::operator & (const MySet& s) const
{
	MySet ans(max(n, s.n));
	for (int i = 0; i < size; i++)
	{
		if (s.find(ps[i]))
		{
			ans.insert(ps[i]);
		}
	}
	return ans;
}

//MySet MySet::SetMinus(const MySet& s) const
MySet MySet::operator - (const MySet& s) const
{
	MySet ans(n);
	for (int i = 0; i < size; i++)
	{
		if (!s.find(ps[i]))
		{
			ans.insert(ps[i]);
		}
	}
	return ans;
}

bool MySet::operator <= (const MySet& s)
{
	for (int i = 0; i < size; i++)
	{
		if (!s.find(ps[i]))
		{
			return false;
		}
	}
	return true;
}

bool MySet::operator == (const MySet& s)
{
	if (size != s.size) return false;
	for (int i = 0; i < size; i++)
	{
		if (!s.find(ps[i])) return false;
	}
	for (int i = 0; i < s.size; i++)
	{
		if (!find(s.ps[i])) return false;
	}
	return true;
}

void MySet::operator += (int x)
{
	insert(x);
}

void MySet::operator -= (int x)
{
	erase(x);
}

/*MySet MySet::operator | (const MySet& s) const
{
	return SetUnion(s);
}

MySet MySet::operator & (const MySet& s) const
{
	return SetCross(s);
}

MySet MySet::operator - (const MySet& s) const
{
	return SetMinus(s);
}*/

MySet MySet::operator = (const MySet& s)
{
	MySet ans;
	n = ans.n = s.n;
	size = ans.size = s.size;
	ps = new int[n];
	ans.ps = new int[ans.n];
	for (int i = 0; i < size; i++)
	{
		ps[i] = ans.ps[i] = s.ps[i];
	}
	return ans;
}

ostream& operator << (ostream& out, const MySet& s)
{
	cout << "{";
	for (int i = 0; i < s.size-1; i++)
	{
		cout << s.ps[i] << ",";
	}
	if (s.size != 0)
	{
		cout << s.ps[s.size-1];
	}
	cout << "}";
	return out;
}
