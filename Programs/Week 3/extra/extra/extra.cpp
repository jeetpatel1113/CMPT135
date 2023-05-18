#include <iostream>
#include <cstring>
using namespace std;
int foo(int x)
{
	int y;
	y = x;
	return y;
}
int main()
{
	/*
	int size;
	cout << "Please enter positive number of numbers: " << endl;
	cin >> size;
	int min, max, temp, count = 0;
	for (int i = 0 ; i < size ; i++)
	{
		cout << "Please enter number: ";
		cin >> temp;
		if (temp % 2 == 0 && temp >= 0)
		{
			if (count == 0)
			{
				min = temp;
				max = temp;
				count++;
			}
			if (temp <= min && count != 0)
			{
				min = temp;
				count++;
			}
			if (temp >= max && count != 0)
			{
				max = temp;
				count++;
			}
		}
	}
	if (count == 0)
		cout << "No minimum No maximum" << endl;
	else
		cout << "The minimum in these numbers is : " << min << endl << "The maximum in these numbers is : " << max << endl;
	system ("Pause");
	return 0;
	*/
	/*
	int x = 3;
	int y(x);
	int z = x;
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
	int b = foo(y);
	cout << b << endl;
	*/
	string x = "abcdef";
	string y = "abcdef";
	if (x < y)
		cout << '<' << endl;

	system ("Pause");
	return 0;
}