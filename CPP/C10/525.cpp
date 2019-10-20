#include <iostream>
using namespace std;

template<class T> class node
{
	T val;
	node<T>* nxt;
	node<T>* front;
public:
	node()
	{
		nxt = front = NULL;
	}
	node(node<T>& n)
	{
		val = n.val;
		nxt = n.nxt;
		front = n.front;
	}
	~node() {}

	void append(node<T>* p)
	{
		nxt = p;
		p->front = this;
	}
	void set_value(T v) {val = v;}
	T get_value() {return val;}
	node<T>* get_prev() {return front;}
	node<T>* get_next() {return nxt;}
};

void test1()
{
	node<int> *ptr;
	node<int> node1,node2,node3;
	node1.set_value(1);
	node2.set_value(2);
	node3.set_value(3);
	node1.append(&node2);
	node2.append(&node3);

	for(ptr=&node1 ; ; ptr=ptr->get_next())
	{
		cout << ptr->get_value() << " ";
		if(ptr->get_next()==NULL) break;
	}
}

void test2()
{
	node<float> *ptr;
	node<float> node1,node2,node3;
	node1.set_value(1.1);
	node2.set_value(2.2);
	node3.set_value(3.3);
	node1.append(&node2);
	node2.append(&node3);

	for(ptr=&node1 ; ; ptr=ptr->get_next())
	{
		cout << ptr->get_value() << " ";
		if(ptr->get_next()==NULL) break;
	}
}

void test3()
{
	node<char> *ptr;
	node<char> node1,node2,node3;
	node1.set_value('a');
	node2.set_value('b');
	node3.set_value('c');
	node1.append(&node2);
	node2.append(&node3);

	for(ptr=&node1 ; ; ptr=ptr->get_next())
	{
		cout << ptr->get_value() << " ";
		if(ptr->get_next()==NULL) break;
	}
}

int main( )
{
	int type;
	cin >> type;
	
	switch(type)
	{
		case 1:
		test1();
		break;
		
		case 2:
		test2();
		break;

		case 3:
		test3();
		break;
	}
    return 0;
}
