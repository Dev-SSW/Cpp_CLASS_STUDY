//�й� �̸�
//�й� �̸�
//�й� �̸�
//�̸��� �������� �޾ƾƼ� �������� ���� �� �� �׸� �� ������ �� ���� sum�� ���� ������ ���Ѵ�.
#include <iostream>
#include <string>
using namespace std;
#define MAX = 50;
struct info //����ü
{
	string number;
	string name;
	int score;
	int sum;
	int ranking;
};
void Random_Input_Data(struct info* s, int size)
{
	
}
int main()
{
	srand((unsigned)time(NULL));
	
	int c[5] = { 1,5,4,2,3 }; //������
	int a[5] = { 1,5,4,3,2 }; //�ڽ��� ����
	int calc[5] = { 3,2,1,1,3 }; //�� �׸� �� ����
	int sum = 0;

	void disp_header();
	void disp_body(int a[], int c[]);
	void disp_tail(int a[], int c[], int calc[], int sum);
	

	disp_header();
	disp_body(a,c);
	disp_tail( a, c, calc, sum);

	//���ĵ� ���¶�� �����Ѵ�.
	//������ ����ϴ� �κ��� �ۼ��Ͻÿ�.
}

void disp_header() 
{
	cout << "����" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1;
	}
	cout << endl;
}
void disp_body(int a[], int c[])
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
		cout << c[i] << " ";
	}
	cout << endl;
}

void disp_tail(int a[], int c[], int calc[] , int sum)
{
	cout << "��, �� : ";
	for (int i = 0; i < 5; i++)
	{
		(c[i] == a[i]) ? cout << "O" : cout << "X";
		if (c[i] == a[i])
		{
			sum += calc[i];
		}
		cout << " ";
	}

	cout << endl;
	cout << sum << endl;
}