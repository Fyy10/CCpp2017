#include "iostream"
#include "queue"
#include "map"
#include "utility"
//#define DEBUG

using namespace std;

class node
{
public:
	int x, y;

	node(int xx = 1, int yy = 1)
	{
		x = xx;
		y = yy;
	}

	void display()
	{
		std::cout << '(' << x << ',' << y << ')' << std::endl;
	}
};

queue<node> q;
map<pair<int, int>, bool> vis;

bool inside(int pos, int up)
{
	if (pos >= 1 && pos <= up) return true;
	return false;
}

void addNeighbor(int m, int n, int pox, int poy)
{
	//push all neighboring nodes
	if (inside(pox - 2, m) && inside(poy - 1, n) && !vis[make_pair(pox - 2, poy - 1)])
	{
		q.push(node(pox - 2, poy - 1));	//LUU
		vis[make_pair(pox - 2, poy - 1)] = true;
	}
	if (inside(pox - 1, m) && inside(poy - 2, n) && !vis[make_pair(pox - 1, poy - 2)])
	{
		q.push(node(pox - 1, poy - 2));	//LLU
		vis[make_pair(pox - 1, poy - 2)] = true;
	}
	if (inside(pox + 1, m) && inside(poy - 2, n) && !vis[make_pair(pox + 1, poy - 2)])
	{
		q.push(node(pox + 1, poy - 2));	//LLD
		vis[make_pair(pox + 1, poy - 2)] = true;
	}
	if (inside(pox + 2, m) && inside(poy - 1, n) && !vis[make_pair(pox + 2, poy - 1)])
	{
		q.push(node(pox + 2, poy - 1));	//LDD
		vis[make_pair(pox + 2, poy - 1)] = true;
	}
	if (inside(pox + 2, m) && inside(poy + 1, n) && !vis[make_pair(pox + 2, poy + 1)])
	{
		q.push(node(pox + 2, poy + 1));	//RDD
		vis[make_pair(pox + 2, poy + 1)] = true;
	}
	if (inside(pox + 1, m) && inside(poy + 2, n) && !vis[make_pair(pox + 1, poy + 2)])
	{
		q.push(node(pox + 1, poy + 2));	//RRD
		vis[make_pair(pox + 1, poy + 2)] = true;
	}
	if (inside(pox - 1, m) && inside(poy + 2, n) && !vis[make_pair(pox - 1, poy + 2)])
	{
		q.push(node(pox - 1, poy + 2));	//RRU
		vis[make_pair(pox - 1, poy + 2)] = true;
	}
	if (inside(pox - 2, m) && inside(poy + 1, n) && !vis[make_pair(pox - 2, poy + 1)])
	{
		q.push(node(pox - 2, poy + 1));	//RUU
		vis[make_pair(pox - 2, poy + 1)] = true;
	}
}

void pushEnd()
{
	//let (-1, -1) be the end of a layer
	q.push(node(-1, -1));
}

bool findEnd()
{
	//judge if the front of queue is an ending
	return q.front().x == -1 && q.front().y == -1;
}

int bfs(int m, int n, int a, int b, int x, int y)
{
	if (x == a && y == b) return 0;
	int ans = 0;
	int pox = a, poy = b;
	addNeighbor(m, n, pox, poy);
	pushEnd();
	#ifdef DEBUG
		while (!q.empty())
		{
			q.front().display();
			q.pop();
		}
	#endif // DEBUG
	while(!q.empty())
	{
		if (findEnd())
		{
			q.pop();
			ans++;
			if (q.empty()) break;
			else pushEnd();
		}
		else
		{
			if (q.front().x == x && q.front().y == y)
			{
				ans++;
				break;
			}
			addNeighbor(m, n, q.front().x, q.front().y);
			q.pop();
		}
	}
	if (q.empty()) ans = -1;
	return ans;
}

int main()
{
	int m, n, a, b, t;
	cin >> m >> n >> a >> b >> t;
	while(t--)
	{
		int x, y;
		/*for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				unvis[make_pair(i, j)] = true;
			}
		}*/
		vis.clear();
		while(!q.empty()) q.pop();
		cin >> x >> y;
		cout << bfs(m, n, a, b, x, y) << endl;
	}
	return 0;
}
