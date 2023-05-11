#include "05_11_coord.h"
coord coord::operator+(int n)   //연산자 중복 (operator overload)   //ob+2
{
	coord temp;
	temp.x = x + n;
	temp.y = y + n;
	return temp;
}
coord coord::operator+(coord ob)   //ob + ob
{
	coord temp;
	temp.x = x + ob.x;
	temp.y = y + ob.y;
	return temp;
}
coord operator+(int n, coord ob) //2+ob   이런 경우에 friend 선언 (함수 밖에서 coord에 속해있다는 것을 명시할 필요X coord::)
{
	coord temp;
	temp.x = n + ob.x;
	temp.y = n + ob.y;
	return temp;
}
ostream& operator << (ostream& stream, coord ob) //friend 선언
{
	stream << ob.x << "," << ob.y;
	return stream;
}