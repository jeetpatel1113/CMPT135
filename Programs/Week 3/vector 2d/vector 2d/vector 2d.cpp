#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Point
{
private:
	int x, y;
public:
	//Constructors
	Point() : x(0), y(0){};
	Point(int &, int &);

	//Getters
	int getX() const;
	int getY() const;
	
	//Setters
	void setX(int &X);
	void setY(int &Y);
};
class Vector2D
{
private:
	Point a, b;
public:
	//Constructors
	Vector2D();
	Vector2D(Point &);

	//Getters
	int getPoint1() const;
	int getPoint2() const;
	
	//Setters
	void setPoint1(int &);
	void setPoint2(int &);

	//length
	int length();

};

int main()
{
	const Vector2D v1;
	Vector2D v2(Point(3, -4));
	cout << "v1 is " << v1 << ", its length is " << v1.length() << endl;
	cout << "v2 is " << v2 << ", its length is " << v2.length() << endl;
	cout << "The end point of v1 is " << v1.getEndPoint() << endl;
	v2.setEndPoint(Point(rand() % 21 - 10, rand() % 11 - 5));
	cout << "The end point of v2 is " << v2.getEndPoint() << endl;
	system("Pause");
	return 0;
}

Point::Point(int &X, int &Y)
{
	x = X;
	y = Y;
}
int Point::getX() const
{
	return x;
}
int Point::getY() const
{
	return y;
}
void Point::setX(int &X)
{
	x = X;
}
void Point::setY(int &Y)
{
	y = Y;
}

Vector2D::Vector2D()
{
	a(0,0);
	b(0,0);
}
Vector2D::Vector2D(Point &p)
{
	a(0,0);
	b(p.getX(),p.getY);
}
Vector2D::length()
{

}