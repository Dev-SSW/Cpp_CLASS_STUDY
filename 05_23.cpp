#include <iostream>
using namespace std;
template <typename T>
void myswap(T & a, T& b)
{
	T t = a; a = b; b = t;
}
template<typename T1, typename T2>
T1 power(T1 a,T2 b)
{
	T1 temp = 1;
	for (int i = 0; i < b; i++)
	{
		temp *= a;
	}
	return temp;
}
class Circle {
	int radius;
public:
	Circle(int radius) : radius(radius) {};
	int getRadius() { return radius; }
};
template<typename B1, typename B2>
B1 bigger(B1 a, B2 b)
{
	return a > b ? a : b;
}
template<typename B3>
B3 bigger(B3 a[] , int b)
{
	B3 big = a[0];

	for (int i = 1; i < b; i++)
	{
		if (big < a[i])
		{
			big = a[i];
		}
	}
	return big;
}
int main()
{
	int a = 3, b = 5;
	//cin >> a >> b;
	cout << bigger(a, b) << endl;
	double c = 4.2, d = 3.5;
	//cin >> c >> d;
	cout << bigger(c, d) << endl;

	int arr[5] = { 1,9,34,7,5 };
	cout << bigger(arr, 5) << endl;
	double drr[10] = { 1.9, 1.2, 3.8, 0.4, 0.5 };
	cout << bigger(drr, 10) << endl;


	int i = 3, j = 4;
	cout << power(i, j) << endl;
	double k = 4.0;
	cout << fixed;
	cout.precision(2);
	cout << (double)power(k, j) << endl;

	Circle pizza(5);
	pizza.getRadius();

	int q = 3, w = 4;
	myswap(q, w);                 //void myswap(int &a, int &b)
	cout << q << " " << w << endl;
	double x = 1.2, y = 3.4;
	myswap(x, y);                 //void myspaw(double &a, double &b)
	cout << x << " " << y << endl;
	char c1 = 'a', c2 = 'b';
	myswap(c1, c2);
	cout << c1 << " " << c2 << endl;
	string str1 = "Hi", str2 = "Hello";
	myswap(str1, str2);
	cout << str1 << " " << str2 << endl;
	//Fraction ob1(1, 2), ob2(2, 3);
	return 0;
}
