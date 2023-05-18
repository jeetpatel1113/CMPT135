#include <iostream>
#include <string>
using namespace std;

template<class T1>
T1 maximum(T1 a, T1 b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	int a1, b1;
	double a2, b2;
	string a3, b3;
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	cout << maximum(a1, b1);
	cout << maximum(a2, b2);
	cout << maximum(a3, b3);
	system("Pause");
	return 0;
}