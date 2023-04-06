#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void bubble_sort(int a[], int size)
{
	int temp;
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + i]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	int list[1000];
	for (int i = 0; i < 1000; i++)
	{
		list[i] = rand() % 1000;
	}
	bubble_sort(list, 1000);
	/*
	for (int i = 0; i < 1000 - 1; i++) {
		for (int j = 0; j < 1000 - i - 1; j++) {
			if (list[j] > list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}

	*/
	ofstream ofs;
	ofs.open("Test.txt");
	for (int i = 0; i < 1000; i++)
	{
		ofs << list[i] << " ";
	}
	ofs << endl;
	ofs.close();
	/*
		ifstream ifs;
		ifs.open("Test.txt");
		int a[1000];
		for (int i = 0; i < 1000; i++)
		{
			ifs >> a[i];
		}
		for (int i = 0; i < 1000; i++)
		{
			cout << a[i] << " ";
		}
		ifs.close();
		*/
}