#include <iostream>
using namespace std;
int main()
{
	//�������� �پ��־ �ǰ� ��� �ȴ�. (�Ű� X)
	int sum(int , int , int ); //�Լ� ���� (Function Prototype)
	double sum(double , double ); //�Լ� �ߺ� (Function Overloading) 
	int sum(int, int);
	//double sum(int, int); //��ȯ �������θ� �����Ǵ� �Լ��� ��� �� �� ����.
	cout << sum(1, 2, 3) << endl;
	cout << sum(1.2, 2.3) << endl;
}
int sum(int a, int b, int c)
{
	return a + b + c;
}
int sum(int a, int b)
{
	return a + b;
}
double sum(double a, double b)
{
	return a + b;
}
//double sum(int a, int b)
//{
//	return a + b;
//}