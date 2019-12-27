#include "165.h"
#include "iostream"

using namespace std;

bool Set::operator <= (const Set& s) const
{
	for (int i = 1; i <= n; i++)
	{
		if (!s.IsElement(pS[i]))
		{
			return false;
		}
	}
	return true;
}

bool Set::operator == (const Set& s) const
{
	return (*this <= s) && (s <= *this);
}

Set& Set::operator += (int e)
{
	if (IsEmpty())
	{
		n = 1;
		pS = new int[n+1];
		pS[1] = e;
	}
	else
	{
		if (IsElement(e)) return *this;
		int *tmp = pS;
		n++;
		pS = new int[n+1];
		for (int i = 1; i < n; i++)
		{
			pS[i] = tmp[i];
		}
		pS[n] = e;
		delete []tmp;
	}
	return *this;
}

Set& Set::operator -= (int e)
{
	if (!IsEmpty())
	{
		for (int i = 1; i <= n; i++)
		{
			if (pS[i] == e)
			{
				for (int j = i+1; j <= n; j++)
				{
					pS[j-1] = pS[j];
				}
				n--;
				break;
			}
		}
	}
	return *this;
}

Set Set::operator | (const Set& s) const
{
	Set ans;
	for (int i = 1; i <= n; i++)
	{
		ans += pS[i];
	}
	for (int i = 1; i <= s.n; i++)
	{
		ans += s.pS[i];
	}
	return ans;
}

Set Set::operator & (const Set& s) const
{
	Set ans;
	for (int i = 1; i <= n; i++)
	{
		if (s.IsElement(pS[i])) ans += pS[i];
	}
	return ans;
}

Set Set::operator - (const Set& s) const
{
	Set ans;
	for (int i = 1; i <= n; i++)
	{
		if (!s.IsElement(pS[i])) ans += pS[i];
	}
	return ans;
}
