#include <iostream>
using namespace std;

class Point
{
private:
	float x, y;

public:
	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}
	void setX (float newX)
	{
		x = newX;
	}
	void setY (float newY)
	{
		y = newY;
	}
	void print()
	{
		cout << "(" << x << ", " << y << ")";
	}
};
int main()
{
	
	Point p;

	p.setX(3.5);
	p.setY(2.2);

	cout << "Point p = ";
	p.print();
	cout << endl;

	system("Pause");
	return 0;
}