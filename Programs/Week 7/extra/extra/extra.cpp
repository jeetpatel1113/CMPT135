#include<iostream>
using namespace std;

int main()
{
	int n = 299;
	char ch = n;
	int newn = ch;
	cout << " n = " << n << endl;
	cout << " ch = " << ch << endl;
	cout << " newn = " << newn << endl;
	for (int i = 0 ; i < 8 ; i++)
	{
		cout << newn % 2;
		newn/=2;
	}
	cout << endl;
	system ("pause");
	return 0;
}