#include <iostream>
using namespace std;
class base
{
public:
	virtual void f()
	{
		cout << "base" << endl;
	}
	//virtual void f() = 0; //���� ���� �Լ�
};
class derived : public base
{
public:
	virtual void f() //�Լ� �������̵� (�Լ� ������) (virtual : ���� �ÿ� �����ǵ��� ����) virtual �� ��� �ȴ�.
	{	
		base::f();
		cout << "derived" << endl;
	}

};
int n; // ���� ������ ���� ������ �ʱ�ȭ�� �����ش�.
int main()
{
	derived ob1;
	ob1.f();

	
	int n = 3;
	cout << n << " " << ::n << endl;

}