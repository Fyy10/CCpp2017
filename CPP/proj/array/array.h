#ifndef ARRAY_H
#define ARRAY_H

#include "iostream"
#include "cassert"

using namespace std;

const int MAX_SIZE = 100;

template <class T> class Array;

template <class T>
ostream& operator<<(ostream&, Array<T>&);

template <class T>
class Array
{
	int n;
	T* p;

public:
	Array(int n = MAX_SIZE);
	Array(Array<T>&);
	~Array();

	T& operator[](int);
	friend ostream& operator<< <T>(ostream& out, Array<T>& arr);
};

template <class T>
Array<T>::Array(int n)
{
	this->n = n;
	p = new T[n];
}

template <class T>
Array<T>::Array(Array<T>& a)
{
	n = a.n;
	p = new T[n];
	for (int i = 0; i < n; i++)
	{
		p[n] = a.p[n];
	}
}

template <class T>
Array<T>::~Array()
{
	delete []p;
}

template <class T>
T& Array<T>::operator[](int x)
{
	assert(x < n);
	return p[x];
}

template <class T>
ostream& operator<<(ostream& out, Array<T>& arr)
{
	for (int i = 0; i < arr.n-1; i++) out << arr[i] << " ";
	out << arr[arr.n-1];
	return out;
}

#endif
