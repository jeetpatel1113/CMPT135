#include <iostream>
using namespace std;

struct RationalNumber
{
	int num;
	int den;
};

RationalNumber standardize (RationalNumber &a)
{
	if (a.den<0)
	{
		a.den = a.den * -1;
		a.num = a.num * -1;
	}
	return a;
}

int main()
{
	RationalNumber num;
	cout << "Please enter a 2 numbers: " << endl;
	cin >> num.num >> num.den;
	standardize(num);
	cout << "After modifying, the numbers become: " << num.num << "/ " << num.den << "." << endl;


	system ("Pause");
	return 0;
}