#pragma once
#include <iostream>
using namespace std;
class coord {
	int x, y;
public:
	coord(int a = 0, int b = 0) : x(a), y(b) {};
	//void show() { cout << x << " " << y << endl; }
	coord operator+(int n);   //연산자 중복 (operator overload)   //ob+2
	coord operator+(coord ob);   //ob + ob
	friend coord operator+(int n, coord ob); //2+ob   이런 경우에 friend 선언
	friend ostream& operator << (ostream& stream, coord ob); //friend 선언
};