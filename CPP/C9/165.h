#include "iostream"

using namespace std;

class Set
{
	private:
		int n;
		int *pS;
	public:
		Set() {n = 0; pS = NULL;}
		Set(Set& S)
		{
			n = S.n;
			if (n != 0)
			{
				pS = new int[n+1];
				for (int i = 1; i <=n; i++) pS[i] = S.pS[i];
			}
		}
		~Set()
		{
			if (pS)
			{
				delete []pS;
				pS = NULL;
				n = 0;
			}
		}

		void ShowElement() const
		{
			cout << "{";
			for (int i = 1; i < n; i++)
				cout << pS[i] << ",";
			if (IsEmpty())
				cout << "}" << endl;
			else
				cout << pS[n] << "}" << endl;
		}
		bool IsEmpty() const {return n == 0;}
		int size() {return n;}
		bool IsElement(int e) const
		{
			for (int i = 1; i <=n; i++)
				if (pS[i] == e)
					return true;
			return false;
		}

		bool operator <= (const Set& s) const;
		bool operator == (const Set& s) const;
		Set& operator += (int e);
		Set& operator -= (int e);

		Set operator | (const Set& s) const;
		Set operator & (const Set& s) const;
		Set operator - (const Set& s) const;
};
