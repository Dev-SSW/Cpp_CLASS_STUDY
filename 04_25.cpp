#include <iostream>
#include <string>
using namespace std;
//typedef struct info {
//	int num;
//	string name;
//}Info;
class Info //비공개를 원칙
{
	int num;
	int *value;
public: //공개
	//생성자함수(constructor function)
	explicit Info(int x , int y);
	~Info() {}; //소멸자
	void show();

	/*void push_back(int a, int b);
	void set(int a , int b);
	void GetValue(int& a, int& b);*/
};
inline Info::Info(int x = -1, int y = -1)// : num(x), value(y)
{
	num = x;
	value = new int[y];
	for (int i = 0; i < y; i++)
	{
		value[i] = 0;
	}
}
inline void Info::show() 
{
	for (int i = 0; i < num; i++)
	{
		cout << value[i] << " ";
	}
	//cout << num << " " << value << endl;
}
//inline void Info::set(int a, int b) { num = a; value = b; }
//inline void Info::push_back(int a, int b) { num = a; value = b; }
//inline void Info::GetValue(int& a, int& b) { a = num; b = value; }
int main()
{
	//Info* s = new Info[10];
	Info ob(3, 5);
//	ob1.set(1, 3);
	ob.show();
//	int x, y;
//	ob.GetValue(x, y);
//	cout << x << "," << y << endl;
}