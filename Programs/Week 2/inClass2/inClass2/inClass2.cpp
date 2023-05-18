#include <iostream>
using namespace std;

class Point
{
private:
	float x, y;
	
public:
	Point();
	Point(float newX, float newY);
	float getX();
	float getY();
	void setX(float newX);
	void setY(float newY);
	void print();
	float getDistance();
};
Point::Point()
{
	x = 0.0;
	y = 0.0;
}
Point::Point(float newX, float newY)
{
	x = newX;
	y = newY;
}

float distanceBetweenPoints(Point p1, Point p2)
{
	float x_diff = p1.getX() - p2.getX();
	float y_diff = p1.getY() - p2.getY();
	return sqrt (x_diff * x_diff + y_diff * y_diff);
}

Point getFurthestPoint(Point *arr, int size)
{
	Point max = arr[0];
	for (int i = 0 ; i < size ; i++)
	{
		if (max.getDistance() < arr[i].getDistance())
			max = arr[i];
	}
	return max;
}
float Point::getDistance()
{
	Point origin;
	Point p;
	p.setX(x);
	p.setY(y);
	float distance = distanceBetweenPoints(p,origin);
	return distance;
}

int main()
{
	/*
	Point p;
	p.setX(3.5);
	//p.setY(2.2);

	cout << "The x-coordinate of point p is " << p.getX() << endl;
	cout << "The y-coordinate of point p is " << p.getY() << endl;

	cout << "Point p = ";
	p.print();
	cout << endl;
	*/
	/*
	Point p = Point(p.getX(), 6.7);


	cout << "The x-coordinate of point p is " << p.getX() << endl;
	cout << "The y-coordinate of point p is " << p.getY() << endl;

	cout << "Point p = ";
	p.print();
	cout << endl;
	*/
	/*
	Point p1(-1, 2), p2(4, -1);
	float distance = distanceBetweenPoints(p1, p2);
	cout << "The distance between p1 " ; p1.print() ; cout << " and p2 " ; p2.print() ; cout << "is " << distance << endl;
	*/
	/*
	Point pointArray[10];

	for (int i = 0 ; i < 10 ; i++)
	{
		cout << "Point P[" << i << "] = ";
		pointArray[i].print();
		cout << endl;
	}
	*/

	int size;
	do
	{
		cout << "Please enter a positive integer for the size of an array: ";
		cin >> size;
	} while (size <= 0);

	Point *arr = new Point[size];

	for (int i = 0 ; i < size ; i++)
		arr[i] = Point(1.0 * rand()/RAND_MAX * 2, 1.0 * rand()/RAND_MAX * 3);

	for (int i = 0 ; i < size ; i++)
	{
		cout << "Element at index " << i << " = ";
		arr[i].print();
		cout << " with distance from origin = " << arr[i].getDistance() << endl;
	}
	
	Point p = getFurthestPoint(arr, size);
	cout << "The element of the array that is farthest from the origin is ";
	p.print();
	cout << endl;
	
	delete[] arr;
	system ("Pause");
	return 0;
}

float Point::getX()
{
	return x;
}
float Point::getY()
{
	return y;
}
void Point::setX(float newX)
{
	x = newX;
}
void Point::setY(float newY)
{
	y = newY;
}
void Point::print()
{
	cout << "(" << getX() << ", " << getY() << ")";
}
