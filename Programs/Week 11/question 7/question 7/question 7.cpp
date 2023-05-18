#include <iostream>
using namespace std;
template<class A>
int countElements(const A *x, const A &b, const int &size)
{
	int count = 0;
	for (int i = 0 ; i < size ; i++)
		if (x[i] == b)
			count++;
	return count;
}

int main()
{
	int A[] = {2, 4, 2, 2, 6, 6, 9, 4, 4, 2, 4}; // 11
	double B[] = {2.0, 1.9, 1.1, 1.1, 1.9, 2.2, 2.0, 1.1, 1.9}; // 9
	char C[] = {'a', 'f', 'a', 'g', 'a', 'a', 'b', 'j'}; // 8
	cout << countElements(A, 2, 11) << endl;
	cout << countElements(B, 1.1, 9) << endl;
	cout << countElements(C, 'a', 8) << endl;
	system("Pause");
	return 0;
}