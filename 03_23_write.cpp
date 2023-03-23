#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	ofstream ofs;
	ofs.open("a.dat",ios::binary);
	int n = rand() % 51 + 100;
	int a;
	for (int i = 0; i < n; i++)
	{
		a = rand() % 1001;
		ofs.write((char*)&a, sizeof(int));
	}
	ofs.close();
	
}