#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

int main() 
{
	int temp;
	clock_t START, END;
	srand((unsigned)time(NULL));

	long list[1000] = { 0, };
	for (int i = 0; i < 1000; i++) {
		list[i] = rand() % 1000;
	}

	//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� ���� ����
	
	START = clock();
	system_clock::time_point start = system_clock::now();
	
	for (int i = 0; i < 1000-1; i++) {
		for (int j = 0; j < 1000 -i -1; j++) {
			if (list[j] > list[j+1]) {
				temp = list[j];
				list[j] = list[j+1];
				list[j + 1] = temp;
			}
		}
	}
	
	END = clock();
	system_clock::time_point end = system_clock::now();



	duration<double> Defaults = end - start;
	nanoseconds nano = end - start;
	microseconds micro = duration_cast<microseconds>(end - start);

	cout << "���������ϴµ� �ɸ� �ð��� " << (double)(END - START) / CLOCKS_PER_SEC << " " << endl;
	cout << "����Ʈ " << Defaults.count() << endl;
	cout << "����и������� " << nano.count() << endl;
	cout << "����ũ�μ����� " << micro.count() << endl;
	for (int i = 0; i < 1000; i++) {
		cout << list[i] << " ";
	}
}