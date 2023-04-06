
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fout("b.bin", ios::binary);
	//int a[10];
	int* a;
	int n;
	fout.read((char*)&n, sizeof(n));
	a = new int[n];
	cout << sizeof(a) << endl; // 40 4byte °¡ 10 °³
	fout.read((char*)a, n* sizeof(a));
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	delete[] a;
	fout.close();
}
