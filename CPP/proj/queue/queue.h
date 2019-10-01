#ifndef QUEUE_H

#define QUEUE_H

#include "iostream"

enum Status
{
	SUCCESS,
	FAIL
};

struct node
{
	int val;
	node* nxt;
	node* front;
};

class MyQueue
{
	public:
		MyQueue();
		MyQueue(MyQueue& q);
		~MyQueue();

		Status push_front(int x);
		Status push_back(int x);
		int pop_front();
		int pop_back();
		bool empty();
		void clear();
		int size();
	private:
		node* head;
		node* tail;
		int n;
};

#endif
