#include "queue.h"

using namespace std;

int main()
{
	MyQueue q;
	/*q.push_back(100);
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
	cout << qa.empty() << " " << q.empty() << endl;*/
	cout << "Please input the operation:" << endl;
	cout << "1: push back" << endl;
	cout << "2: push front" << endl;
	cout << "3: pop front" << endl;
	cout << "4: pop back" << endl;
	int o;
	while (cin >> o)
	{
		switch (o)
		{
			case 1:
				{
					int a;
					cout << "Please input the number you want to push back:";
					cin >> a;
					q.push_back(a);
					cout << "Done!" << endl;
					break;
				}
			case 2:
				{
					int a;
					cout << "Please input the number you want to push front:";
					cin >> a;
					q.push_front(a);
					cout << "Done!" << endl;
					break;
				}
			case 3:
				{
					cout << "pop front:";
					cout << q.pop_front() << endl;
					break;
				}
			case 4:
				{
					cout << "pop back:";
					cout << q.pop_back() << endl;
					break;
				}
			default:;
		}
	}
	return 0;
}
