#include "queue.h"
#include "cassert"

using namespace std;

MyQueue::MyQueue()
{
	head = NULL;
	tail = NULL;
	n = 0;
}

MyQueue::MyQueue(MyQueue& q)
{
	node* pn;
	pn = q.head;
	/*if (pn == NULL)
	{
		head = tail = NULL;
	}
	else
	{
		head = new node;
		tail = head;
		head->front = NULL;
	}*/
	head = tail = NULL;
	n = 0;
	while (pn != NULL)
	{
		node* tmp = new node;
		tmp->val = pn->val;
		tmp->front = tail;
		tmp->nxt = NULL;
		if (n == 0)
		{
			head = tail = tmp;
		}
		else
		{
			tail->nxt = tmp;
			tail = tmp;
		}
		pn = pn->nxt;
		n++;
	}
	assert(n == q.n);
}

MyQueue::~MyQueue()
{
	node* pn = head;
	while (pn != NULL)
	{
		node* tmp = pn->nxt;
		delete pn;
		pn = tmp;
	}
}

Status MyQueue::push_front(int x)
{
	node* phead = new node;
	phead->val = x;
	phead->nxt = head;
	if (empty())
	{
		head = tail = phead;
		head->front = NULL;
	}
	else
	{
		head->front = phead;
		head = phead;
	}
	n++;
	return SUCCESS;
}

Status MyQueue::push_back(int x)
{
	node* ptail = new node;
	ptail->val = x;
	ptail->nxt = NULL;
	ptail->front = tail;
	if (empty())
	{
		head = tail = ptail;
	}
	else
	{
		tail->nxt = ptail;
		tail = ptail;
	}
	n++;
	return SUCCESS;
}

int MyQueue::pop_front()
{
	assert(!empty());
	int ans = head->val;
	node* tmp = head;
	head = head->nxt;
	if (head != NULL)
	{
		head->front = NULL;
	}
	else
	{
		tail = NULL;
	}
	n--;
	delete tmp;
	return ans;
}

int MyQueue::pop_back()
{
	assert(!empty());
	int ans = tail->val;
	node* tmp = tail;
	tail = tail->front;
	if (tail != NULL)
	{
		tail->nxt = NULL;
	}
	else
	{
		head = NULL;
	}
	n--;
	delete tmp;
	return ans;
}

bool MyQueue::empty()
{
	return n == 0;
}

void MyQueue::clear()
{
	node* pn = head;
	while (pn != NULL)
	{
		node* tmp = pn;
		pn = pn->nxt;
		delete tmp;
	}
	head = tail = NULL;
	n = 0;
}

int MyQueue::size()
{
	return n;
}
