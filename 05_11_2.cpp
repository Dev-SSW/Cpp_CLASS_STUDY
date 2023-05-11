#include "05_11_coord.h"
coord coord::operator+(int n)   //������ �ߺ� (operator overload)   //ob+2
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
coord operator+(int n, coord ob) //2+ob   �̷� ��쿡 friend ���� (�Լ� �ۿ��� coord�� �����ִٴ� ���� ����� �ʿ�X coord::)
{
	coord temp;
	temp.x = n + ob.x;
	temp.y = n + ob.y;
	return temp;
}
ostream& operator << (ostream& stream, coord ob) //friend ����
{
	stream << ob.x << "," << ob.y;
	return stream;
}