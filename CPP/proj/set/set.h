#ifndef SET_H

#define SET_H

#include "iostream"

using namespace std;

enum Status
{
	SUCCESS,
	FAIL
};

const int MAX_SIZE = 100;	//default max size of set

class MySet
{
	public:
		MySet(int ns = MAX_SIZE);
		MySet(MySet& ms);
		~MySet();

		Status insert(int x);
		Status erase(int x);
		Status expand(int a);

		void clear();
		void display() const;

		bool find(int x) const;
		bool empty() {return size == 0;}
		bool full() {return size == n;}

		int now_size() {return size;};
		int max_size() {return n;};

		MySet SetUnion(const MySet& s) const;
		MySet SetCross(const MySet& s) const;
		MySet SetMinus(const MySet& s) const;

		bool operator <= (const MySet& s);
		bool operator == (const MySet& s);

		void operator += (int x);
		void operator -= (int x);

		MySet operator | (const MySet& s) const;
		MySet operator & (const MySet& s) const;
		MySet operator - (const MySet& s) const;
		MySet operator = (const MySet& s);

		friend ostream& operator << (ostream& out, const MySet& s);
	private:
		int* ps;
		int n;
		int size;
};

#endif
