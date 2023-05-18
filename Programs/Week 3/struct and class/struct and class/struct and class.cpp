#include <iostream>
using namespace std;

struct Point
{
	int a, b;
};

class Point
{
public:
	//Construct;
	int a, b;
	Point();
};
Point::Point()
{
	a = 0;
	b = 0;
}

int main()
{
	Point x;
	
	cout << x.a << "/" << x.b << endl;
	system ("pause");
	return 0;
}