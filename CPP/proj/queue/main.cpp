#include "queue.h"

using namespace std;

int main()
{
	MyQueue q;
	q.push_back(100);
	cout << q.size() << endl;
	q.push_front(200);
	cout << q.size() << endl;
	cout << q.pop_back() << endl;
	cout << q.pop_back() << endl;
	q.push_back(233);
	MyQueue qa(q);
	qa.push_front(332);
	cout << qa.size() << endl;
	while (!qa.empty())
	{
		cout << qa.pop_front() << endl;
	}
	while (!q.empty())
	{
		cout << q.pop_front() << endl;
	}
	qa.push_back(300);
	cout << qa.pop_front() << endl;
	cout << qa.empty() << " " << q.empty() << endl;
	return 0;
}
