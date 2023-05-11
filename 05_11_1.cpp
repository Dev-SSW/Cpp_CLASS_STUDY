#include <iostream>
#include "05_11_coord.h"
int main()
{
	coord ob1(1, 2), ob2(3, 4), ob3;
	ob3 = ob1 + ob2;
	cout << ob3 << endl;
	ob3 = 2 + ob1; //x,y 각각 2씩 증가
	cout << ob3 << endl;
	ob2 = ob1 + 2;
	cout << ob2 << endl;
	//cout << ob;  //operator<< 호출
}
