#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int amain()
{
	ofstream fobin("x.bin", ios::binary);
	int* a;
	int n;

	srand((unsigned)time(NULL));
	
	n = 5 + rand() % 6;
	
	//fobin.write((char*)&n, sizeof(n));

	a = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 101;
	}
	
	fobin.write((char*)a, n * sizeof(int));
	fobin.close();
	delete[] a;
	return 0;
}