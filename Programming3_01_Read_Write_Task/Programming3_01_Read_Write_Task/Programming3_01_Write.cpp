
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
void bubble_sort(double list[], int size)
{
	double temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}
int main()
{
	ofstream of("text.txt",ios::binary);
	srand((unsigned)time(NULL));
	long n = 10000000;
	of.write((char*)&n, sizeof(n));
	double *a = new double[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = ((long)rand()<<15| rand()) % 100001 * 0.1;
	}
	bubble_sort(a, n);
	of.write((char*)a, n*sizeof(double));
	delete[] a;
}
