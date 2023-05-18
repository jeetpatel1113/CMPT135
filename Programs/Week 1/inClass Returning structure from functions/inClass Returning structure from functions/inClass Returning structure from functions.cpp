#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

struct Point
{
	double x;
	double y;
};

Point getPoint()
{
	Point p;
	cout << "Enter the x coordinate of the Point: ";
	cin >> p.x;
	cout << "Enter the y coordinate of the Point: ";
	cin >> p.y;
	return p;
}

void printPoint(Point p)
{
	cout << "(" << p.x << ", " << p.y << ")" << endl;
}

double distanceFromOrigin(Point &pAlias)
{
	double d = sqrt (pAlias.x * pAlias.x + pAlias.y * pAlias.y);
	return d;
}

int main()
{
	Point p1;
	p1 = getPoint();
	cout << "The Point object you created is: ";
	printPoint(p1);

	double distance = distanceFromOrigin(p1);
	cout << "The distance of the Point object from the origin is " << distance << endl;

	system("Pause");
	return 0;
}