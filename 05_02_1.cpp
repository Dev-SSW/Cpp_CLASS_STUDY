#include <iostream>
using namespace std;
int sum(int, int);
int sum(int);
void star(int n = 5); //�Լ� ���� ���� (default ���� ������ �Ű�����)
void msg(int id , int id2 = 3); //default�� �ڿ� ���� (�տ� �ִ� ��� msg(1)�� ���� ȣ�⿡�� ���� ���� ��ȣ����)
void square(int width = -1, int height = -1);
void fillLine(int n = 25, char ch = '*');

int main()
{
	cout << sum(3, 5) << endl;
	cout << sum(3) << endl;;
	cout << sum(100) << endl;
	cout << sum(5, 3) << endl;
	star();
	star(10);
	square();
	square(5);
	square(7, 1);
	square(3, 0);
	fillLine();
	fillLine(10, '%');
}
void fillLine(int n, char ch)
{
	for (int i = 0; i < n; i++)
	{
		cout << ch;
		if((i+1)%5 == 0)
		{
			cout << " ";
		}
	}
	cout << endl;
}

void square(int width, int height)
{
	if (height == -1)
	{
		height = width;
	}
	cout << "����� ���� : " << width * height << endl;
}

void star(int n)
{
	for( int i = 0;  i< n;  i++)
	{
		cout << "*";
	}
	cout << endl;
}
int sum(int a, int b)
{
	int sum1 = 0;
	if(a > b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	for (int i = a; i <= b; i++)
	{
		sum1 += i;
	}
	return sum1 ;
}
int sum(int a)
{
	int sum1 = 0;
	for (int i = 1; i <= a; i++)
	{
		sum1 += i;
	}
	return sum1;
}