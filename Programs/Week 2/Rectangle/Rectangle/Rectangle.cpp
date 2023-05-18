#include <iostream>
using namespace std;
class Rectangle
{
private:
	float length, width;

public:
	//Default
	Rectangle();

	//Non Default
	Rectangle(float length, float width);

	//Getters
	float getLength();
	float getWidth();

	//Setters
	void setLength(float newWidth);
	void setWidth(float newWidth);

	//Area
	float getArea();

	//Perimeter
	float getPerimeter();

	//print
	void print();
};
Rectangle::Rectangle()
{
	length = 1.0;
	width = 1.0;
}
Rectangle::Rectangle(float x, float y)
{
	length = x;
	width = y;
}
float Rectangle::getLength()
{
	return length;
}
float Rectangle::getWidth()
{
	return width;
}
void Rectangle::setLength(float newLength)
{
	length = newLength;
}
void Rectangle::setWidth(float newWidth)
{
	width = newWidth;
}
float Rectangle::getArea()
{
	return length * width;
}
float Rectangle::getPerimeter()
{
	return length * 2 + width * 2;
}
void Rectangle::print()
{
	cout << "The length of Rectangle is " << length << endl;
	cout << "The width of Rectangle is " << width << endl;
	cout << "The area of Rectangle is " << getArea() << endl;
	cout << "The perimeter of Rectangle is " << getPerimeter() << endl;
}
int main()
{
	Rectangle r1, r2(3, 4), r3(1, 2);
	Rectangle r4 = r2;

	cout << "r1 length = " << r1.getLength() << endl;
	cout << "r2 width = " << r2.getWidth() << endl;
	cout << "r3 area = " << r3.getArea() << endl;
	cout << "r4 perimeter = " << r4.getPerimeter() << endl;

	cout << "Rectangle r1 is ";
	r1.print(); cout << endl;
	cout << "Rectangle r2 is ";
	r2.print(); cout << endl;

	r1.setLength(5);
	r1.setWidth(9);
	cout << "After modifying its length and width, r1 is now ";
	r1.print(); cout << endl;

	system("Pause");
	return 0;
}


