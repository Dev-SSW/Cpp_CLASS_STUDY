#include <iostream>
using namespace std;
//객체지향기법 : 실 세계의 모습을 소프트웨어로 구현하는 기법
//public, protected, private, default 공부
//예로 protected는 클래스끼리는 허용이 가능하지만 클래스를 벗어나면 호출 할 수 없다.
class base
{
	int x, y;
public:
	base(int a = 0, int b = 0) : x(a), y(b) {}
	void set(int a, int b) { x = a; y = b; }
	void show() { cout << x << " " << y; }
};
class derived : public base //child class (상속)
{
	int z;
public: 
	derived(int a = 0, int b = 0, int c = 0) : base(a, b) {  z = c; }
	void setz(int c) { z = c; }
	void showall() { show(); cout << " " << z << endl; }
	
};
int main()
{
	derived ob(5,5,5), ob1(7);
	//ob.set(3, 4);
	//ob.setz(5);
	//ob.show();
	//cout << "\n";
	ob.showall();
	ob1.showall();
	return 0;
}