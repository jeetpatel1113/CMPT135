#include <iostream>
using namespace std;
bool CheckEven (const int *A, const int& size)
{
	if (size == 1)
	{
		if (A[size] % 2 == 0)
			return true;
	}
	else if (size != 1)
	{
		if (A[size - 1] % 2 != 0)
			return false;
		CheckEven (A, size - 1);
	}
}


int main()
{
	int A[12] = {2,2,2,2,2,2,2,2,2,2,2,2};
	
	cout << '[';
	for (int i = 0 ; i < 12 ; i++)
		cout << A[i] << ", ";
	cout << ']' << endl;


	cout << CheckEven(A, 12) << endl;

	cout << '[';
	for (int i = 0 ; i < 12 ; i++)
		cout << A[i] << ", ";
	cout << ']' << endl;
	system ("Pause");
	return 0;
}