#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class coord
{
	int x, y;
public:
	//coord() { x = y = 0; }
	//coord(int a = 0, int b = 0) :x(a), y(b) {}
	coord(int a, int b);
	double dist(coord ob2); //멤버함수
	void show();
	void set(int a, int b) {
		x = a; y = b;
	}
	friend coord findCenterPoint(coord ob[]);
};
//-------------------------------------------------------
coord findCenterPoint(coord arr[])
{
	int sumx = 0, sumy = 0;
	for (int i = 0; i < 100; i++)
	{
		sumx += arr[i].x;
		sumy += arr[i].y;
	}
	return coord(sumx / 100, sumy / 100);
}
inline coord::coord(int a = 0, int b = 0) :x(a), y(b) {}
inline double coord::dist(coord ob)
{
	int dx = x - ob.x;
	int dy = y - ob.y;
	return sqrt(dx * dx + dy * dy);
}
void coord::show()
{
	cout << "(" << x << "," << y << ")" << endl;
}
inline void swap(coord &a, coord &b)  //inline 속도 향상
{
	coord tmp = a;
	a = b;
	b = tmp;
}
//-------------------------------------------------------

void quick_sort(int arr[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;
	while (i > j)
	{
		while (arr[i] <= arr[pivot] && i <= end)
		{
			i++;
		}
		while (arr[j] >= arr[pivot] && j >=start)
		{
			j--;
		}
		if (i > j) 
		{
			temp = arr[pivot];
			arr[pivot] = arr[j];
			arr[j] = arr[pivot];
		}
		else
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}
int &findMax(const int arr[])  //변하지않도록
{
	int max = arr[0];  //주소값
	for (int i = 1; i < 5; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
int main()
{
	coord ob1(3, 4), ob2(2, 3);
	swap(ob1, ob2);
	ob1.show();
	int* a = new int[5] {1, 5, 3, 2, 4};
	int r = findMax(a);
	cout << r << endl;
	cout << "두 좌표의 거리는" << ob1.dist(ob2) << endl;

	coord ob[100];
	for (int i = 0; i < 100; i++) {
		ob[i].set(rand() % 500, rand() % 500);
	}
	coord avg;
	avg = findCenterPoint(ob);
	avg.show();
}