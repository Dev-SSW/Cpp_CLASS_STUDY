#include <iostream>
using namespace std;
template <typename T> 
class mystack //last in first out = LIFO
{
	T *a;
	//T a[100];
	int top;
	int size;
public:
	mystack(int n = 100) { a = new T[n]; size = n; top = -1; }
	~mystack() { delete[] a; }
	void push(T rhs)
	{
		if (top == size)
		{
			size *= 2;
			T* temp = new T[size];
			
			for (int i = 0; i < size; i++)
			{
				temp[i] = a[i];
			}
			a = nullptr;
			std::swap(a,temp);
			delete[] temp;
		}
		a[++top] = rhs;
	}
	T pop();
};
template < typename T>
T mystack<T>:: pop()
{
	if (top == -1)
	{
		cerr << "stack is empty" << endl;
		exit(0);
	}
	else
	{
		T temp = a[top--];
		return temp;
	}
}
class Point
{
	int x, y;
public:
	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
	void show() { cout << "(" << x << "," << y << ")" << endl; }
};
int main()
{
	mystack<int> is;
	Point a(3,4), b;

	//is.push(Point(1,2));
	//is.push(a);
	/*
	for (int i = 0; i < 2; i++)
	{
		b = is.pop();
		b.show();
	}
	*/

	/*
	for (int i = 0; i < 200; i++)
	{
		is.push(i);
	}
	for (int i = 0; i < 200; i++)
	{
		cout << is.pop() << endl;
	}*/

	//is.push(1.1);
	//is.push(2.2);
	//cout << is.pop() << endl;
	//cout << is.pop() << endl;
	//mystack<string> ss;
	//ss.push("abc");
	//ss.push("def");
	//cout << ss.pop() << endl;
	//cout << ss.pop() << endl;
	//int i = 0;
	//cout << i << " " << ++i << endl;   //cout이 스택을 사용한답니다 허허
}