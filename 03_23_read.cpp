#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream ifs("a.dat",ios::in|ios::binary);
	ofstream odd("odd.txt");
	ofstream even("even.txt");
	int n;
	int size;

	ifs.seekg(0, ios::end);
	size = ifs.tellg()/sizeof(int);
	ifs.seekg(0, ios::beg);
	cout << size << endl;
	
	for (int i = 0; i < size; i++)
	{
		ifs.read((char*)&n, sizeof(int));
		cout << n << " ";

		if (n % 2) {
			odd << n<< endl;
		}
		else {
			even<< n << endl;
		}
		
	}
	even.close();
	odd.close();
	ifs.close();
	
}