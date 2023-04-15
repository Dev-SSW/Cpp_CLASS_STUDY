#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct s
{
	int sum = 0;
	int rank = 0;
};
void quick_sort(struct s * arr , int start , int end)
{
	if (start >= end)
	{
		return;
	}
	int pivot = start;
	int i = pivot + 1;
	int j = end;
	struct s temp;
	while (i <= j)
	{
		while (i <= end && arr[i].sum <= arr[pivot].sum) 
		{
			i++;
		}
		while (j > start && arr[j].sum >= arr[pivot].sum) 
		{
			j--;
		}
		if (i > j) {
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		quick_sort(arr, start, j - 1);
		quick_sort(arr, j + 1, end);
	}

}
//bool cmp(const s& s1 , const s& s2)
//{
//	return s1.sum > s2.sum;
//}
int main()
{
	struct s arr[100];
	for (int i = 0; i < 100; i++) {
		arr[i].sum = rand() % 501;
	}
	//sort(arr, arr+100, cmp);
	quick_sort(arr, 0, 99);
	arr[0].rank = 1;
	for (int i = 1; i < 100; i++) {
		arr[i].rank = arr[i-1].rank + 1;
	}
	for (int i = 0; i < 100; i++) {
		cout << arr[i].sum << " " << arr[i].rank << endl;
	}
	return 0;
}