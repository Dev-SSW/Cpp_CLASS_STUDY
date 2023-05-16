#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct node {
	int info;
	node* next;
};

class stack
{
	int info;
	stack* next;
	stack* head;

public:
	stack()
	{
		head = NULL;
	}
	~stack()
	{
		while (head != NULL)
		{
			stack* t = head;
			head = head->next;
			delete[] t;
		}
	}
	void push(int n)
	{
		stack* temp = new stack;
		temp->info = n;
		temp->next = head;
		head = temp;
		cout << "head " << head << " temp " << temp << endl;
	}
	int pop()
	{
		if (head == NULL)
		{
			cout << "stack is empty" << endl;
			return -1;
		}
		int tvalue = head->info;
		head = head->next;
		return tvalue;
	}
};
int main()
{
	/*struct node* ptr = NULL;
	struct node* temp = new struct node;
	temp->info = 3;
	temp->next = ptr;
	ptr = temp;

	temp = new node;
	temp->info = 111;
	temp->next = ptr;
	ptr = temp;

	while (ptr != NULL)
	{
		struct node* t = ptr;
		cout << ptr->info << endl;
		ptr = ptr->next;
		delete t;
	}*/
	stack s;
	/*srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++)
	{
		s.push(rand() % 100);
	}
	for (int i = 0; i < 100; i++)
	{
		s.pop();
	}*/
	s.push(3);
	s.push(2);
	s.push(1);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	
}