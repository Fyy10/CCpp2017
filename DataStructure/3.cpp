#include "iostream"
#include "string"
#include "queue"
//#define DEBUG

using namespace std;

queue<char> roots;

class node
{
public:
	node *l, *r;
	char c;

	node()
	{
		l = r = NULL;
		c = '\0';
	}
	~node()
	{
		delete l;
		delete r;
	}
};

class BiTree
{
	node* root;

	void pfirst(node* p)
	{
		if (p == NULL || p->c == '\0') return;
		cout << p->c;
		pfirst(p->l);
		pfirst(p->r);
	}
	void pmiddle(node* p)
	{
		if (p == NULL || p->c == '\0') return;
		pmiddle(p->l);
		cout << p->c;
		pmiddle(p->r);
	}
	void plast(node* p)
	{
		if (p == NULL || p->c == '\0') return;
		plast(p->l);
		plast(p->r);
		cout << p->c;
	}

	void build(string s2, node* &p)	//s2: middle order
	{
		if (s2.length() == 0) return;
		p = new node;
		p->c = roots.front();
		roots.pop();
		#ifdef DEBUG
			cout << s2.length() << endl;
		#endif // DEBUG
		if (s2.length() == 1) return;
		p->l = new node;
		p->r = new node;
		unsigned int i;
		for (i = 0; i < s2.length(); i++)
		{
			if (s2[i] == p->c) break;
		}
		build(s2.substr(0, i), p->l);
		build(s2.substr(i + 1, s2.length() - i - 1), p->r);
	}

public:
	BiTree(string s2)
	{
		root = NULL;
		build(s2, this->root);
	}
	~BiTree()
	{
		delete root;
	}

	void print_first()
	{
		pfirst(this->root);
	}
	void print_middle()
	{
		pmiddle(this->root);
	}
	void print_last()
	{
		plast(this->root);
	}
};

bool judgeOK(string s1, string s2)		//judge if the input is valid
{
	int table[26];
	for(int i = 0; i < 26; i++) table[i] = 0;
	if (s1.length() != s2.length()) return false;
	for (unsigned i = 0; i < s1.length(); i++)
	{
		table[s1[i] - 'a']++;
		table[s2[i] - 'a']--;
	}
	for (unsigned i = 0; i < s1.length(); i++)
	{
		if (table[i] > 1 || table[i] < 0) return false;
	}
	return true;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (!judgeOK(s1, s2))
	{
		cout << "error";
		return 0;
	}
	for (unsigned int i = 0; i < s1.length(); i++) roots.push(s1[i]);
	BiTree BT(s2);
	#ifdef DEBUG
		BT.print_first();
		BT.print_middle();
	#endif // DEBUG
	BT.print_last();
    return 0;
}
