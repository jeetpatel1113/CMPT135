#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
	double x;
	double y;
};
int main()
{
	/*
	Point p;
	cout << "Enter the x coordinate of the Point object: ";
	cin >> p.x;
	cout << "Enter the y coordinate of the Point object: ";
	cin >> p.y;
	cout << "The Point object you created is: P(" << p.x << ", " << p.y << ")" << endl;
	double distance = sqrt(p.x*p.x + p.y*p.y);
	cout << "The distance of the Point object from the origin is " << distance << endl;
	*/
	/*
	Point p1;
	Point &p1Alias = p1;

	cout << "Enter the x coordinate of the Point object: ";
	cin >> p1.x;
	cout << "Enter the y coordinate of the Point object: ";
	cin >> p1.y;
	cout << "The Point object you created is: P(" << p1Alias.x << ", " << p1Alias.y << ")" << endl;
	double distance = sqrt(p1Alias.x*p1.x + p1.y*p1Alias.y);
	cout << "The distance of the Point object from the origin is " << distance << endl;
	*/
	/*
	Point p1;
	Point &p1Alias = p1;
	Point *p1Ptr = &p1;

	cout << "Enter the x coordinate of the Point object: ";
	cin >> (*p1Ptr).x;
	cout << "Enter the y coordinate of the Point object: ";
	cin >> p1Ptr->y;
	cout << "The Point object you created is: P(" << p1Alias.x << ", " << p1Alias.y << ")" << endl;
	double distance = sqrt(p1.x*p1.x + p1.y*p1.y);
	cout << "The distance of the Point object from the origin is " << distance << endl;
	*/
	/*
	Point p1, p2;
	p1.x = 1;
	p1.y = 2;

	p2 = p1;

	cout << "Point p1 is (" << p2.x << ", " << p2.y << ")" << endl;
	cout << "Point p1 is still (" << p1.x << ", " << p1.y << ")" << endl;

	system ("Pause");
	return 0;
	*/

	system ("Pause");
	return 0;
}