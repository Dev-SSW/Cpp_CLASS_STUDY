#include <iostream>
using namespace std;
int Reduction(int a, int b)
{
	int temp = 0;
	while (b)
	{
		// 2 / 10
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
class Fraction
{
	int numerator, denominator;
public:	
	Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {};
	
	friend ostream& operator << (ostream & out, Fraction rhs) 
	{
		int temp = Reduction(rhs.numerator, rhs.denominator);
		rhs.denominator /= temp;
		rhs.numerator /= temp;

		out << rhs.numerator;
		if (rhs.denominator != 1) {
			cout << "/" << rhs.denominator;
		}
		return out;
	}
	
	Fraction operator+(Fraction rhs)
	{
		Fraction temp;
		temp.denominator = denominator * rhs.denominator;
		temp.numerator = (numerator * rhs.denominator) + (rhs.numerator * denominator);
		return temp;
	}
	Fraction operator-(Fraction rhs)
	{
		Fraction temp;
		temp.denominator = denominator * rhs.denominator;
		temp.numerator = (numerator * rhs.denominator) - (rhs.numerator * denominator);
		return temp;
	}
	Fraction operator*(Fraction rhs)
	{
		Fraction temp;
		temp.denominator = denominator * rhs.denominator;
		temp.numerator = numerator * rhs.numerator;
		return temp;
	}
	Fraction operator/(Fraction rhs) 
	{
		Fraction temp;
		temp.denominator = denominator * rhs.numerator;
		temp.numerator = numerator * rhs.denominator;
		return temp;
	}
	operator double() const
	{
		return (double)numerator / denominator;
	}
};
int main()
{
	Fraction ob(1, 2) , ob1(1, 2);
	cout << Fraction(2,10) << endl;
	
	/*
	���� : 
	���ڰ� �ʹ� Ŀ�� �����÷ο찡 �߻��� ������ ���� �� ���� ����� �����غ��ƶ�.
	ob3 = ob1 + ob2;
	ob3 = ob1 + 2;
	ob3 = 2 + ob1;
	ob3 = ob1 + 0.2;  (�Ǽ��� �м��� �ٲ۴� convert)
	ob3 = ob1 + 3.14
	ob = 0.3 �̶�� ob�� 3/10�� ������ �����.
	cout << (double) Fraction(1,2) << endl; �� �� 0.5�� ���� �� �ֵ��� �����.
	*/
	
}