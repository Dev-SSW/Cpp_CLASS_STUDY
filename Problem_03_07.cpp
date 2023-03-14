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
	cout << "검색값을 입력하시오";
	cin >> a;

	for (int i = 0; i < 10001; i++) {
		if (number[i] == a) {
			cout << i<< "번째에" << a << "값이 있습니다.";
			break;
		}
		if (i == 10000) 
		{
			cout << "자료없음" << endl;
		}
	}
	
	

	sort(list.begin(), list.end());

	cout << "새로운 검색값을 입력하시오";
	cin >> b;

	for (int i = 0; i < 10001; i++) {
		if (list[i] == b) {
			cout << i << "번째에" << b << "값이 있습니다.";
			break;
		}
		if (i == 10000)
		{
			cout << "자료없음" << endl;
		}
	}
	
}