#include <iostream>
using namespace std;

struct Point 
{
	double x;
	double y;
};

void readPoint(Point *pPtr)
{
	cout << "Enter the x coordinate of the Point: ";
	cin >> pPtr->x;
	cout << "Enter the y coordinate of the Point: ";
	cin >> pPtr->y;
}

void printPoint(Point p)
{
	cout << "The Point object you created is P(" << p.x << ", " << p.y << ")" << endl;
}

double distanceFromOrigin(Point &pAlias)
{
	double d = sqrt(pAlias.x*pAlias.x + pAlias.y * pAlias.y);
	return d;
}

int main()
{
	Point p1;
	readPoint(&p1);
	printPoint(p1);
	double distance = distanceFromOrigin(p1);
	cout << "The disrance of the Point from the origin is " << distance << endl;

	system ("Pause");
	return 0;
}