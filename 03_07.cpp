#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;
vector<int> list;

int main()
{
	srand((unsigned)time(NULL));
	int number[10001] = { 0, };
	for (int i = 0; i < 10001; i++)
	{
		number[i] = rand();

		list.push_back(number[i]);

		cout << number[i] << '\n' << endl;
	}

	int a, b;
	cout << "�˻����� �Է��Ͻÿ�";
	cin >> a;

	for (int i = 0; i < 10001; i++) {
		if (number[i] == a) {
			cout << i<< "��°��" << a << "���� �ֽ��ϴ�.";
			break;
		}
		if (i == 10000) 
		{
			cout << "�ڷ����" << endl;
		}
	}
	
	

	sort(list.begin(), list.end());

	cout << "���ο� �˻����� �Է��Ͻÿ�";
	cin >> b;

	for (int i = 0; i < 10001; i++) {
		if (list[i] == b) {
			cout << i << "��°��" << b << "���� �ֽ��ϴ�.";
			break;
		}
		if (i == 10000)
		{
			cout << "�ڷ����" << endl;
		}
	}
	
}