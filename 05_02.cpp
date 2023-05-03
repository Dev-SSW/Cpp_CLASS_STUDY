#include <iostream>
using namespace std;
int main()
{
	//변수명은 붙어있어도 되고 없어도 된다. (신경 X)
	int sum(int , int , int ); //함수 원형 (Function Prototype)
	double sum(double , double ); //함수 중복 (Function Overloading) 
	int sum(int, int);
	//double sum(int, int); //반환 형식으로만 구별되는 함수를 사용 할 수 없다.
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