#include <iostream>
using namespace std;
template <class T1>
T1 absValue(T1 a)
{
	if (a < 0)
		return -1*a;
	else
		return a;
}
int main()
{
	int a;
	cin >> a;
	double b;
	cin >> b;
	cout << absValue(a) << endl << absValue(b) << endl;
	system ("Pause");
	return 0;
}