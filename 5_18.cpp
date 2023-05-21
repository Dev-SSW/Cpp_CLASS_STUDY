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
		cout << "오버플로우 발생" << endl;
		return 0;
	}
	else
	{
		return true;
	}
}
int Reduction(int a, int b) //분수를 약분하기 위해 최대공약수를 구하는 함수
{
	int temp = 0;
	while (b)
	{
		// 최대공약수 구하기 (유클리드 호제법) A % B의 최대공약수 값 R은 B%R의 최대공약수와 같다. 이 성질을 이용한 알고리즘이다.
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
class Fraction  //분수 클래스
{
	int numerator, denominator;
public:
	Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {};

	friend ostream& operator << (ostream& out, Fraction rhs) //cout 재정의
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

	Fraction operator+(Fraction rhs)  //분수와 분수 더하기
	{
		Fraction temp;
		temp.denominator = denominator * rhs.denominator;
		temp.numerator = (numerator * rhs.denominator) + (rhs.numerator * denominator);
		return temp;
	}
	Fraction operator+(int rhs)  //분수에 정수를 더하기
	{
		Fraction temp;
		temp.denominator = denominator;
		temp.numerator = numerator + (denominator * rhs);
		return temp;
	}
	friend Fraction operator+(int rhs, Fraction lhs)  // 정수에 분수를 더하기
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

	Fraction operator+(double rhs) // 분수에 실수를 더하기
	{
		// rhs = 0.2 라면 . 이후의 글자 개수 * 10을 통해 2/10으로 만들어준다.
		//string length = to_string(rhs);
		//char * str = NULL;
		//char * token = strtok_s((char*)length.c_str(), ".", &str);
		//int n = (int)strlen(str);  //소수점 이하 문자열 길이가 나온다
		//int mo = pow(10, n);
		//Fraction temp;
		//temp.denominator = mo;
		//temp.numerator = rhs * mo;
		//temp = temp + *this;
		//return temp;

		//-------------------------------------------------------------------------------------------------
		//10씩 계속 곱하다가 rhs 의 int 값과 같아 졌을 때 stop
		//0.2라면 n = 0      2 라면 n= 2
		//3.14라면 n은 3    31.4 라면 n은 31     314라면 n은 314
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
	ob3 = ob1 + 0.2;                            //(실수를 분수로 바꾼다 convert)
	cout << "ob3 = ob1 + 0.2 = " << ob3 << endl;
	ob3 = ob1 + 3.14;
	cout << "ob3 = ob1 + 3.14 = " << ob3 << endl;
	ob3 = 0.3;                                  //이라면 ob에 3 / 10이 들어가도록 만든다.
	cout << "ob3 = 0.3 = " << ob3 << endl;
	cout << "(double)Fraction(1, 2) = " << (double)Fraction(1, 2) << endl; //일 때 0.5가 나올 수 있도록 만든다.


}