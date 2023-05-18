#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct RationalNumber
{
	int num;
	int dec;
};

string toString(const RationalNumber &p)
{
	stringstream ss;
	ss << p.num << "/" << p.dec << endl;
	string s = ss.str();
	return s;
}

RationalNumber reduce(RationalNumber num)
{
	for (int i = 2 ; i < num.num ; i++)
	{
		if (num.num % i == 0 && num.dec % i == 0)
		{
			num.num = num.num / i;
			num.dec = num.dec / i;
			i--;
		}
	}
	return num;
}
int main()
{
	RationalNumber n;
	cout << "Please enter 2 numbers: " << endl;
	cin >> n.num >> n.dec;
	RationalNumber z = reduce(n);
	cout << "Once reduced, the numbers are " << toString(z) << endl;
	system ("Pause");
	return 0;
}