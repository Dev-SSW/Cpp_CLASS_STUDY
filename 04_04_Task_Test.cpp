#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	
	int a[5] = { 1,5,4,2,3 }; // ������
	int calc[5] = { 3,2,1,1,3 }; // �� �׸� �� ����
	int sum = 0;

	int n[5] = { 0, }; // �л��� ������ �� ����

	for (int i = 0; i < 5; i++)
	{
		n[i] = a[i];
	}
	int s = rand() % 5;
	for (int i = 0; i < s; i++)
	{
		int n1 = rand() % 5;
		int n2 = rand() % 5;
		int temp;
		temp = n[n1];
		n[n1] = n[n2];
		n[n2] = temp;
	}

	void disp_header(int n[]);
	void disp_body(int a[], int n[]);
	void disp_tail(int a[], int n[], int calc[], int sum);


	disp_header(n);
	disp_body(a, n);
	disp_tail(a, n, calc, sum);

}
void disp_header(int n[])
{
	cout << "����" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << n[i] << " ";
	}
	cout << endl;
}
void disp_body(int a[], int n[])
{
	cout << "�� : ";
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "���� : ";
	for (int i = 0; i < 5; i++)
	{
		cout << n[i] << " ";
	}
	cout << endl;
}

void disp_tail(int a[], int n[], int calc[], int sum)
{
	cout << "��, �� : ";
	for (int i = 0; i < 5; i++)
	{
		(n[i] == a[i]) ? cout << "O" : cout << "X";
		if (n[i] == a[i])
		{
			sum += calc[i];
		}
		cout << " ";
	}

	cout << endl;
	cout << sum << endl;
}