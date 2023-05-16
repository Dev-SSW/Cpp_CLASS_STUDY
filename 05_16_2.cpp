#include <iostream>
using namespace std;
struct node {
	int info;
	node* next;
};
class ex
{
	int a[100];
	int p;
public:
	ex() { p = 0; }
	void insert(int n)
	{
		for (int i = 0; i < p; i++)
		{
			if (a[i] == n)
			{
				cout << "err";
				return;
			}
			a[p++] = n;
		}
	} 
};
int main()
{
	int a[100];
	int p = 0;
	int n;
	cin >> n;
	a[p++] = n;
}