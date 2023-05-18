#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct StringStat
{
	string s;
	int lower, upper, digit;
};

string toString(StringStat a)
{
	stringstream ss;
	ss << endl << "String: " << a.s << endl << "Lower: " << a.lower << endl << "Upper: " << a.upper << endl << "Digit: " << a.digit << endl;
	string s = ss.str();
	return s;
}
int main()
{
	int size;
	StringStat a;
	cout << "Please enter a word: ";
	cin >> a.s;
	size = a.s.length();
	char *s1 = new char[size];
	a.upper = 0;
	a.lower = 0;
	a.digit = 0;
	for (int i = 0 ; i < size ; i++)
	{
		s1[i] = a.s[i];
		if (a.s[i] > 'A' && a.s[i] < 'Z')
			a.upper++;
		if (a.s[i] > 'a' && a.s[i] < 'z')
			a.lower++;
		if (a.s[i] > '0' && a.s[i] < '9')
			a.digit++;
	}
	cout << "The result is " << toString(a) << endl;

	delete[] s1;
	system ("Pause");
	return 0;
}