#include <iostream>
using namespace std;
int findMinimum (const int* A, const int& size)
{
	if (size == 1)
		return A[size];
	else
	{
		if (A[size - 1] < findMinimum(A, size - 1))
			return A[size - 1];
	}
}


int main()
{
	int A[12] = {1,1,1,1,2,2,3,4,5,6,7, 6};
	
	cout << '[';
	for (int i = 0 ; i < 12 ; i++)
		cout << A[i] << ", ";
	cout << ']' << endl;


	cout << findMinimum (A, 12) << endl;

	cout << '[';
	for (int i = 0 ; i < 12 ; i++)
		cout << A[i] << ", ";
	cout << ']' << endl;
	system ("Pause");
	return 0;
}