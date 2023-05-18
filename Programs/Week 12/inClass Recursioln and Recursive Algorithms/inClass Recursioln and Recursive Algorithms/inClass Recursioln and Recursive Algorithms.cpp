#include <iostream>
#include <cmath>
using namespace std;
void print_vertical(unsigned int n)
{
	if (n == 0)
	{
		cout << n << endl;
		return;
	}
	else
	{
		int m = log10(static_cast<double>(n));
		int p = pow(10.0, m);
		while (p > 0)
		{
			int digit = n / p;
			cout << digit << endl;
			n = n % p;
			p = p / 10;
		}
	}
}

int main()
{
	unsigned int n;
	cout << "Enter a non-negative integer : ";
	cin >> n;
	print_vertical(n);
	system("Pause");
	return 0;
}