#include <iostream>
using namespace std;
//��ü������ : �� ������ ����� ����Ʈ����� �����ϴ� ���
//public, protected, private, default ����
//���� protected�� Ŭ���������� ����� ���������� Ŭ������ ����� ȣ�� �� �� ����.
class base
{
	int x, y;
public:
	base(int a = 0, int b = 0) : x(a), y(b) {}
	void set(int a, int b) { x = a; y = b; }
	void show() { cout << x << " " << y; }
};
class derived : public base //child class (���)
{
	int z;
public: 
	derived(int a = 0, int b = 0, int c = 0) : base(a, b) {  z = c; }
	void setz(int c) { z = c; }
	void showall() { show(); cout << " " << z << endl; }
	
};
int main()
{
	derived ob(5,5,5), ob1(7);
	//ob.set(3, 4);
	//ob.setz(5);
	//ob.show();
	//cout << "\n";
	ob.showall();
	ob1.showall();
	return 0;
}