#include <iostream>
using namespace std;

struct Point
{
	double x;
	double y;
};

void printPoint(Point p)
{
	cout << "(" << p.x << ", " << p.y << ")";
}
void foo(Point &a, Point *b, Point c)
{
	a = *b;
	*b = c;
	c = a;
	b = &a;
}

int main()
{
	Point p1, p2, p3;
	p1.x = 1;
	p1.y = 2;
	p2.x = 3;
	p2.y = 4;
	p3.x = 5;
	p3.y = 6;
	foo(p1, &p2, p3);
	cout << "Point p1 is ";
	printPoint(p1);
	cout << endl;
	cout << "Point p2 is ";
	printPoint(p2);
	cout << endl;
	cout << "Point p3 is ";
	printPoint(p3);
	cout << endl;
	system("Pause");
	return 0;
}