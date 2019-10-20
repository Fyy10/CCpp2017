#ifndef ARRAY_H
#define ARRAY_H

#include "iostream"

using namespace std;

const int MAX_SIZE = 100;

template <class T> class Array
{
	int n;
	T* p;

public:
	Array(int n = MAX_SIZE);
	Array(Array<T>&);
	~Array();
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

#endif
