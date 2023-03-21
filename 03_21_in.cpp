#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fbin("x.bin", ios::in|ios::out|ios::binary);
	int* a;
	//int n;
	//fbin.read((char*)&n, sizeof(int));
	
	fbin.seekg(0, ios::end);
	int size = fbin.tellg();
	fbin.seekg(0, ios::beg); // begin에서부터 0번째를 찾아라 라는 뜻 2*sizeof(int) , 즉 8을 넣으면 세번째 , 3이 나온다
	
	cout << size << endl;
	cout << endl;
	a = new int[size/sizeof(int)];
	fbin.read((char*)a, size);

	fbin.close();
	
	for (int i = 0; i < size/sizeof(int); i++)
	{
		cout << a[i] << endl;
	}
	delete[] a;
	return 0;
}