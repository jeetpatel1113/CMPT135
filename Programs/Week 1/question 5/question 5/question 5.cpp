#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct RationalNumber
{
	double numerator;
	double denominator;
};
string toString (const RationalNumber &a)
{
	stringstream ss;
	ss << a.numerator << "/ " << a.denominator;
	string s = ss.str();
	return s;
}
RationalNumber toDouble(RationalNumber &a)
{
	a.numerator = a.numerator * 2;
	a.denominator = a.denominator * 2;
	return a;
}
int main()
{
	RationalNumber num;
	cout << "Please enter numerator and denominator: " << endl;
	cin >> num.numerator >> num.denominator;
	cout << "The number entered are " << toString(num) << endl;
	toDouble(num);
	cout << "After modifying, number becomes " << toString(num) << endl;
	system ("Pause");
	return 0;
}