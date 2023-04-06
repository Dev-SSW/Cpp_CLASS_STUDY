#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define MAX 30
using namespace std;
struct info //����ü
{
	string number;
	string name;
	int mid;
	int fin;
	int sum;
	double avg;
	int ranking;
};

void print(int);
void print_data(struct info s[], int size); // function prototype �Լ� ���� ����

void print(int n)
{
	cout << n << endl;
}
void input_data(struct info* s, int size)
{
	string numbers = "22";
	string names = "���̻�����ĥ�ȱ���";
	int a = 1;
	for (int i = 0; i < size; i++) {
		s[i].number = "";
		s[i].name = "";
		s[i].mid = 0;
		s[i].fin = 0;
		s[i].ranking = 1;
	}
	for (int i = 0; i < size; i++) {

		if (a < 10) {
			s[i].number = numbers + "0" + to_string(a);
		}
		else {
			s[i].number = numbers + to_string(a);
		}
		a++;
		for (int i = 0; i < size; i++) {     //�ѱ��� 2����Ʈ�� �� �����̴�
			s[i].name = names.substr(rand() % 10 * 2, 2) +
				names.substr(rand() % 10 * 2, 2) +
				names.substr(rand() % 10 * 2, 2);
		}
		s[i].mid = rand() % 101;
		s[i].fin = rand() % 101;
	}

	for (int i = 0; i < size; i++) {
		s[i].sum = s[i].mid + s[i].fin;
		s[i].avg = (double) s[i].sum / 2;

	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			if (s[i].avg < s[j].avg)
				s[i].ranking++;
		}
	}
}

void print_data(struct info s[], int size)        // *s �Ǵ� s[]
{
	
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << s[i].number << " " << setw(3) << s[i].name << " " <<
			setw(3) << s[i].mid << " " << setw(3) << s[i].fin << " "
			<< setw(3) << s[i].sum << " " << setw(4) << s[i].avg << " " << setw(3) << s[i].ranking << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	cout << setw(4) << "�й� " << setw(3) << "�̸�  " << setw(3) << " �߰�" << setw(3) << "�⸻" 
		<< setw(3) << "�հ�" << setw(3) << "���" << setw(3) << " ���� " << endl;
	struct info s[MAX] = {
		{ "2201","���̻�",10,20 } ,
		{ "2202","���̻�",20,70 } ,
		{ "2203","���̻�",30,80 } ,
		{ "2204","���̻�",50,100 } ,
		{ "2205","���̻�",60,90 }
	};
	input_data(s, MAX);
	print_data(s, MAX);
	return 0;
}