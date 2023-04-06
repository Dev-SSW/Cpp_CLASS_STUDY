//학번 이름
//학번 이름
//학번 이름
//이름과 정답지를 받아아서 정답지와 비교한 후 각 항목 별 점수를 다 더한 sum을 통해 순위를 비교한다.
#include <iostream>
#include <string>
using namespace std;
#define MAX = 50;
struct info //구조체
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
	
	int c[5] = { 1,5,4,2,3 }; //정답지
	int a[5] = { 1,5,4,3,2 }; //자신의 답지
	int calc[5] = { 3,2,1,1,3 }; //각 항목 별 점수
	int sum = 0;

	void disp_header();
	void disp_body(int a[], int c[]);
	void disp_tail(int a[], int c[], int calc[], int sum);
	

	disp_header();
	disp_body(a,c);
	disp_tail( a, c, calc, sum);

	//정렬된 상태라고 가정한다.
	//순위를 계산하는 부분을 작성하시오.
}

void disp_header() 
{
	cout << "국어" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1;
	}
	cout << endl;
}
void disp_body(int a[], int c[])
{
	cout << "답 : ";
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "정답 : ";
	for (int i = 0; i < 5; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
}

void disp_tail(int a[], int c[], int calc[] , int sum)
{
	cout << "정, 오 : ";
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