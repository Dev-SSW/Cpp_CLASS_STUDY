#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream ifs("text.txt", ios::binary);
	long n;
	ifs.read((char*)&n, sizeof(n));
	double* a = new double[n];;
	ifs.read((char*)a, n * sizeof(double));
	cout << fixed;
	cout.precision(1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	delete[] a;
	ifs.close();
}
