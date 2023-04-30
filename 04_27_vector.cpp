#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v; //template
	for (int i = 0; i < 11; i++)
	{
		v.push_back(i);
	}
	cout << v.capacity() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}