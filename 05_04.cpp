#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class Point
{
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) { };
	double dist(Point a)
	{
		int dx = x - a.x;
		int dy = y - a.y;
		double dist = sqrt(dx * dx + dy * dy);
		return dist;
	}
	void show() { cout << "x : " << x  << " y : " << y << endl; }
	void set(int a, int b) { x = a; y = b; }
	int getX() { return x; }
	int getY() { return y; }
};
int main()
{
	srand((unsigned)time(NULL));
	Point p[10];
	for (int i = 0;  i < 10; i++)
	{
		p[i].set(rand() % 100, rand() % 100);
	}
	for (int i = 0; i < 10; i++)
	{
		p[i].show();
	}
	double centerx = 0, centery = 0;
	for (int i = 0; i < 10; i++)
	{
		centerx += p[i].getX();
		centery += p[i].getY();
	}
	centerx /= 10;
	centery /= 10;
	Point center;

	center.set(centerx, centery);
	cout << "center의 좌표는 : "; center.show(); cout << endl;
	
	double max = center.dist(p[0]);
	Point pointmax;
	for (int i = 0; i < 10; i++)
	{
		if (max < center.dist(p[i]))
		{
			max = center.dist(p[i]);
			pointmax.set(p[i].getX(), p[i].getY());
		}
	}
	cout << "중심점에서 가장 먼 점의 좌표는 : "; pointmax.show(); cout << endl;


	double min = center.dist(p[0]);
	Point pointmin;
	for (int i = 0; i < 10; i++)
	{
		if (min > center.dist(p[i]))
		{
			min = center.dist(p[i]);
			pointmin.set(p[i].getX(), p[i].getY());
		}
	}
	cout << "중심점에서 가장 가까운 점의 좌표는 : "; pointmin.show(); cout << endl;
}