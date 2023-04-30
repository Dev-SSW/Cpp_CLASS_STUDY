#include <iostream>
using namespace std;
class samp {
	int x;
	int* a;
public:
	samp(int n = 1) {
		x = n; a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = i;
		}
	}
	samp(samp& ob) : x(ob.x) //deep copy 복사 생성자
	{ 
		a = new int[x];
		for (int i = 0; i < x; i++) {
			a[i] = ob.a[i];
		}
	}
	~samp()
	{
		delete[] a;
	}
	void show() {
		for (int i = 0; i < x; i++)
		{
			cout << a[i] << endl;
		}
	}
};

int main()
{
	samp ob(5);
	samp ob1(ob);
	ob.show();
	ob1.show();
}