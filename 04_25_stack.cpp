#include <iostream>
#include <string>
using namespace std;
class MyStack {
	int top;
	int* item;
public:
	MyStack(int a = 10) {
		item = new int[a];
		top = -1;
	}
	~MyStack()
	{
		delete[] item;
	}
	void push( int n ) 
	{
		++top;
		item[top] = n;
	}
	int pop() 
	{
		if (top == -1)
		{
			cout << "Stack is empty";
			exit(1);
		}
		return item[top--];
	}

};
int main()
{
	MyStack s(10); //default : 10°³
	for (int i = 0; i < 3; i++)
	{
		s.push(i);
	}
	for (int i = 0; i < 3; i++)
	{
		s.pop();
	}
}