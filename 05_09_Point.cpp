#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <windows.h>
using namespace std;
class Point
{
	int x;
	int y;
	double r;
public:
	Point(int a = 0, int b = 0, int c = 10) : x(a), y(b), r(c) { };
	double dist(Point a)
	{
		int dx = x - a.x;
		int dy = y - a.y;
		double dist = sqrt(dx * dx + dy * dy);
		return dist;
	}
	void show()
	{
		HDC hdc = GetWindowDC(GetForegroundWindow());
		HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
		
		Ellipse(hdc, x, y, x + r, y + r);
	}
	void set(int a, int b, int c) { x = a; y = b; r = c; }
	int getX() { return x; }
	int getY() { return y; }
	double getR() {return r; }
};