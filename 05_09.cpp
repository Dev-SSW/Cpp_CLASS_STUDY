#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Point.cpp"
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	Point p[100];
	for (int i = 0; i < 100; i++)
	{
		p[i].set(50 + rand() % 801, 50 + rand() % 601, rand() % 31 + 5);
	}
	HDC hdc = GetWindowDC(GetForegroundWindow());
	Rectangle(hdc, 10, 30, 1000, 800);
	for (int k = 0; k < 10; k++)
	{
		system("cls"); //clear screen
		for (int i = 0; i < 100;i++)
		{
			p[i].set(p[i].getX() + 5, p[i].getY(),p[i].getR());
		}
		double centerx = 0, centery = 0;
		Point center[100];
		for (int i = 0; i < 100; i++)
		{
			centerx += p[i].getX();
			centery += p[i].getY();
			centerx /= 10;
			centery /= 10;
			center[i].set(centerx, centery, p[i].getR());
		}
		for (int i = 0; i < 100; i++)
		{
		
			p[i].show();
		}
		Sleep(1000);
		HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
		int x = 700; int y = 400; int r = 20;
		Ellipse(hdc, x, y, x + r, y + r);

		
	}
	
	
	//LineTo(hdc, 1000, 800);
}