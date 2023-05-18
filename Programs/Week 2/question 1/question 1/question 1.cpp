#include <iostream>
using namespace std;
/*
class Point
{
	float x, y;
	float getX()
	{
	return x;
	}
		float getY()
	{
	return y;
	}
	void setX(float newX)
	{
		x = newX;
	}
	void setY(float newY)
	{
		y = newY;
	}
	void print()
	{
		cout<<"("<< x <<", "<< y <<")";
	}
};
int main()
{
Point p;
p.x = 1;
p.y = 2;
cout<<"Point p is "; p.print(); cout<<endl;
p.setX(3);
p.setY(4);
cout << "Now x coordinate of p is "<< p.getX() <<endl;
cout << "And y coordinate of p is "<< p.getY() <<endl;
system("Pause");
return 0;
}
*/
class A
{
private:
	int v;
public:
	A()
	{
		setValue(0); 
	}
	A(int value) 
	{
		setValue(value);
	}
	int getValue() 
	{ 
		return v;
	}
	void setValue(int v) 
	{
		v = v;
	}
};
int main()
{
	A a1, a2(5);
	cout<< a1.getValue() <<endl;
	cout<< a2.getValue() <<endl;
	a1.setValue(2);
	cout<< a1.getValue() <<endl;
	system("Pause");
	return 0;
}
