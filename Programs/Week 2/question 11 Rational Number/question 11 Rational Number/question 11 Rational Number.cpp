#include <iostream>
using namespace std;

class RationalNumber
{
private:
	int a, b;
public:
	RationalNumber();
	RationalNumber(int);
	RationalNumber(int newA, int newB);
	// getters
	int getValueA();
	int getValueB();
	//setters
	void setValueA(int);
	void setValueB(int);
	// toDouble
	RationalNumber toDouble();
	// standardize
	RationalNumber standardize();
	//print
	void print();
};
RationalNumber::RationalNumber() : a(0), b(1){}
RationalNumber::RationalNumber(int newA)
{
	a = newA;
	b = 1;
}
RationalNumber::RationalNumber(int newA, int newB)
{
	a = newA;
	b = newB;
}
int RationalNumber::getValueA()
{
	return a;
}
int RationalNumber::getValueB()
{
	return b;
}
void RationalNumber::setValueA(int newA)
{
	a = newA;
}
void RationalNumber::setValueB(int newB)
{
	b = newB;
}
RationalNumber RationalNumber::toDouble()
{
	a = double a;
	b = double b;
}
RationalNumber RationalNumber::standardize()
{
	a = abs(a);
	b = abs(b);
}
void RationalNumber::print()
{
	cout << a << "/ " << b << endl;
}
int main()
{
	RationalNumber a, b(2), c(3, 4);
	a.print();
	b.print();
	c.print();
	//cout << a.getValueA() << endl;
	system ("Pause");
	return 0;
}