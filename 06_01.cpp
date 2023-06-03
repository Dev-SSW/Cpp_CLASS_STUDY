#include <iostream>
using namespace std;
class base
{
public:
	virtual void f()
	{
		cout << "base" << endl;
	}
	//virtual void f() = 0; //순수 가상 함수
};
class derived : public base
{
public:
	virtual void f() //함수 오버라이딩 (함수 재정의) (virtual : 실행 시에 결정되도록 만듦) virtual 안 적어도 된다.
	{	
		base::f();
		cout << "derived" << endl;
	}

};
int n; // 전역 변수는 값이 없으면 초기화를 시켜준다.
int main()
{
	derived ob1;
	ob1.f();

	
	int n = 3;
	cout << n << " " << ::n << endl;

}