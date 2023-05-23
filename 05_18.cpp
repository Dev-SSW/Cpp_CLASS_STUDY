#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define EPSILON 0.00001
#define DoubleMax 1.7*pow(10,308)
bool double_compare(double a, double b)
{
	return abs(a - b) < EPSILON;
}
bool over_check(double a, double b)
{
	if (a > DoubleMax - b)
	{
		cout << "�����÷ο� �߻�" << endl;
		return 0;
	}
	else
	{
		return true;
	}
}
int Reduction(int a, int b) //�м��� ����ϱ� ���� �ִ������� ���ϴ� �Լ�
{
	int temp = 0;
	while (b)
	{
		// �ִ����� ���ϱ� (��Ŭ���� ȣ����) A % B�� �ִ����� �� R�� B%R�� �ִ������� ����. �� ������ �̿��� �˰����̴�.
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
class Fraction  //�м� Ŭ����
{
	int numerator, denominator;
public:
	Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {};

	friend ostream& operator << (ostream& out, Fraction rhs) //cout ������
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

	Fraction operator+(Fraction rhs)  //�м��� �м� ���ϱ�
	{
		Fraction temp;
		temp.denominator = denominator * rhs.denominator;
		temp.numerator = (numerator * rhs.denominator) + (rhs.numerator * denominator);
		return temp;
	}
	Fraction operator+(int rhs)  //�м��� ������ ���ϱ�
	{
		Fraction temp;
		temp.denominator = denominator;
		temp.numerator = numerator + (denominator * rhs);
		return temp;
	}
	friend Fraction operator+(int rhs, Fraction lhs)  // ������ �м��� ���ϱ�
	{
		Fraction temp;
		temp.denominator = lhs.denominator;
		temp.numerator = lhs.numerator + (lhs.denominator * rhs);
		return temp;
	}

	Fraction operator=(double rhs) 
	{
		// ob3 = 0.3;
		int count = 0;
		double tmp = rhs;
		while (true)  
		{
			int n = rhs;
			if (double_compare(n, rhs))
			{

				break;
			}
			else
			{
				rhs *= pow(10, count + 1);
				count++;
			}
		}
		int mo = pow(10, count);

		Fraction temp;
		temp.denominator = mo;
		temp.numerator = tmp * mo;
		*this = temp;
		return *this;
	}

	Fraction operator+(double rhs) // �м��� �Ǽ��� ���ϱ�
	{
		// rhs = 0.2 ��� . ������ ���� ���� * 10�� ���� 2/10���� ������ش�.
		//string length = to_string(rhs);
		//char * str = NULL;
		//char * token = strtok_s((char*)length.c_str(), ".", &str);
		//int n = (int)strlen(str);  //�Ҽ��� ���� ���ڿ� ���̰� ���´�
		//int mo = pow(10, n);
		//Fraction temp;
		//temp.denominator = mo;
		//temp.numerator = rhs * mo;
		//temp = temp + *this;
		//return temp;

		//-------------------------------------------------------------------------------------------------
		//10�� ��� ���ϴٰ� rhs �� int ���� ���� ���� �� stop
		//0.2��� n = 0      2 ��� n= 2
		//3.14��� n�� 3    31.4 ��� n�� 31     314��� n�� 314
		int count = 0;
		double tmp = rhs;
		while (true)  
		{
			int n = rhs;
			if (double_compare(n, rhs))
			{
				break;
			}
			else
			{
				rhs *= pow(10, count+1);
				count++;
			}
		}
		int mo = pow(10,count);
		Fraction temp;
		temp.denominator = mo;
		temp.numerator = tmp * mo;
		temp = temp + *this;
		return temp;
	}

	Fraction operator-(Fraction rhs)
	{
		Fraction temp;
		temp.denominator = denominator * rhs.denominator;
		temp.numerator = (numerator * rhs.denominator) - (rhs.numerator * denominator);
		return temp;
	}
	Fraction operator-(int rhs)
	{
		Fraction temp;
		temp.denominator = denominator;
		temp.numerator = numerator - (denominator * rhs);
		return temp;
	}
	friend Fraction operator-(int rhs, Fraction lhs)
	{
		Fraction temp;
		temp.denominator = lhs.denominator;
		temp.numerator = lhs.numerator - (lhs.denominator * rhs);
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
	Fraction ob1(1, 2), ob2(1, 2) , ob3;
	ob3 = ob1 + ob2;
	cout << "ob3 = ob1 + ob2 = " << ob3 << endl;
	ob3 = ob1 + 2;
	cout << "ob3 = ob1 + 2 = " << ob3 << endl;
	ob3 = 2 + ob1;
	cout << "ob3 = 2 + ob1 = " << ob3 << endl;
	ob3 = ob1 + 0.2;                            //(�Ǽ��� �м��� �ٲ۴� convert)
	cout << "ob3 = ob1 + 0.2 = " << ob3 << endl;
	ob3 = ob1 + 3.14;
	cout << "ob3 = ob1 + 3.14 = " << ob3 << endl;
	ob3 = 0.3;                                  //�̶�� ob�� 3 / 10�� ������ �����.
	cout << "ob3 = 0.3 = " << ob3 << endl;
	cout << "(double)Fraction(1, 2) = " << (double)Fraction(1, 2) << endl; //�� �� 0.5�� ���� �� �ֵ��� �����.


}