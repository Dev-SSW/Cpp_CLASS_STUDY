
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream fout("b.bin", ios::binary);
	//int a[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int* a;
	int n;
	srand((unsigned)time(NULL));
	n = 20; // +rand() % 6;

	fout.write((char*)&n, sizeof(n));

	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 101;
	}
	cout << n*sizeof(int) << endl; // sizeof(a) = 8 (동적 기억 장소여서 곱하기를 해줘야함)
	fout.write((char*)a, n*sizeof(int));
	
	delete[] a;
	fout.close();
}

//a 는 배열의 시작을 나타냄, 그렇기에 &를 붙일 필요가 없다.
	/*
	int a;
	char ch ;
	double d;
	*/
	//fout >> a >> ch >> d;
	/*
	fout.write((char *)&a, sizeof(int));
	fout.write((char*)&ch, sizeof(ch));
	fout.write((char*)&d, sizeof(d));
	
	
	fout.read((char*)&a, sizeof(int));
	fout.read((char*)&ch, sizeof(ch));
	fout.read((char*)&d, sizeof(d));
	
	fout << a << " " << ch << " " << d << " " << endl;
	cout << a << " " << ch << " " << d << " " << endl;
	*/