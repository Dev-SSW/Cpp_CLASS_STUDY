#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define MAX 1000
using namespace std;
struct info
{
	string number = "";
	string name = "";
	int subject1 = 0;
	int subject2 = 0;
	int sum = 0;
	int rank = 0;
};
void insert_arr(struct info arr[] ,int size)
{
	for (int i = 0; i < size ; i++) {
		arr[i].number = i;
		arr[i].name = i;
		arr[i].subject1 = rand() % 100;
		arr[i].subject2 = rand() % 100;
		arr[i].sum += arr[i].subject1;
		arr[i].sum += arr[i].subject2;
	}
}

void ranking_sort(struct info arr[],int size)
{
	arr[0].rank = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			if (arr[i].sum < arr[j].sum) {
				arr[i].rank++;
			}
		}
	}
}

bool find_arr(struct info arr[], int low, int high, int target)
{
	if (low > high)	return false;
	int mid = (low + high) / 2;

	if (arr[mid].rank == target)	return true;

	// 찾는 수가 더 작다면, 검사 범위를 더 작게 잡아야 한다.
	if (arr[mid].rank > target)
		return find_arr(arr, low, mid - 1, target);

	// 찾는 수가 더 크가면, 검사 범위를 더 크게 잡아야 한다.
	else
		return find_arr(arr, mid + 1, high, target);
}

void quick_sort(struct info* arr, int start, int end)
{
	if (start >= end) {
		return;
	}
	int pivot = start;
	int i = pivot + 1;
	int j = end;
	struct info temp;
	while (i <= j) {
		while (i <= end && arr[i].rank <= arr[pivot].rank) {
			i++;
		}
		while (j > start && arr[j].rank >= arr[pivot].rank) {
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
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}
int main()
{
	clock_t start;
	start = clock();

	struct info * arr;
	arr = new struct info[MAX];

	insert_arr(arr,MAX);
	ranking_sort(arr,MAX);
	find_arr(arr,0,MAX,400);
	quick_sort(arr, 0, MAX);

	clock_t end;
	end = clock();

	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

	delete[] arr;
}


