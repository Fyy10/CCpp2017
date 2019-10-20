#include "iostream"
#include "cstdio"

using namespace std;

struct node
{
	int num;
	node* nxt;
	node* front;
};

class clist		//circle list
{
	node* head;
	node* tail;
	int n;
public:
	clist(int n = 10)
	{
		this->n = n;
		head = tail = NULL;
		if (n)
		{
			node* p = new node;
			p->num = 1;
			p->nxt = NULL;
			p->front = tail;
			head = tail = p;
			int m = n-1;
			while (m)
			{
				node* tmp = new node;
				tmp->num = n - m + 1;
				tmp->nxt = NULL;
				tmp->front = tail;
				tail->nxt = tmp;
				tail = tail->nxt;
				m--;
			}
			tail->nxt = head;
			head->front = tail;
		}
	}
	clist(clist& l)
	{
		n = l.n;
		head = tail = NULL;
		if (n)
		{
			node* p = new node;
			p->num = 1;
			p->nxt = NULL;
			p->front = tail;
			head = tail = p;
			int m = n-1;
			while (m)
			{
				node* tmp = new node;
				tmp->num = n - m + 1;
				tmp->nxt = NULL;
				tmp->front = tail;
				tail->nxt = tmp;
				tail = tail->nxt;
			}
			tail->nxt = head;
			head->front = tail;
		}
	}
	~clist()
	{
		node* p = head;
		while (n)
		{
			node* tmp = p;
			p = p->nxt;
			delete tmp;
			n--;
		}
	}

	void erase(int x)	//erase the x_th element
	{
		int cnt = 1;
		node* p = head;
		if (n == 0) return;
		while (cnt != x)
		{
			cnt++;
			p = p->nxt;
			if (p == head) break;
		}
		if (cnt == x)
		{
			n--;
			if (p == head) head = p->nxt;
			if (p == tail) tail = p->front;
			node* tmp = p->nxt;
			tmp->front = p->front;
			delete p;
			tmp->front->nxt = tmp;
		}
	}

	void display()
	{
		node* p = head;
		while (p)
		{
			if (p == tail) break;
			cout << p->num << ",";
			p = p->nxt;
		}
		cout << p->num;
	}

	int size() {return n;}
};

int main()
{
	int n = 0, k = -1, m = 0;
	cin >> n >> k >> m;
	if (k == 0)
	{
		cout << 0;
		return 0;
	}
	if (k > n || m <= 0 || k < 0 || n <= 0)
	{
		cout << "ERROR";
		return 0;
	}
	clist cir(n);
	int pos = (m + 1) % cir.size();
	if (pos == 0) pos = cir.size();
	while (cir.size() > k)
	{
		cir.erase(pos);
		pos += m;
		pos %= cir.size();
		if (pos == 0) pos = cir.size();
	}
	cir.display();
	return 0;
}
