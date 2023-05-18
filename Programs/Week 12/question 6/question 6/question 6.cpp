#include <iostream>
using namespace std;
bool CheckDistinct(const int* A, const int& size)
{
	if (size == 1)
		return true;
	else
	{
		if (A[size - 1] == A[size - 2])
			return false;
		CheckDistinct (A, size - 1);
	}
}


int main()
{
	int A[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	
	cout << '[';
	for (int i = 0 ; i < 12 ; i++)
		cout << A[i] << ", ";
	cout << ']' << endl;


	cout << CheckDistinct(A, 12) << endl;

	cout << '[';
	for (int i = 0 ; i < 12 ; i++)
		cout << A[i] << ", ";
	cout << ']' << endl;
	system ("Pause");
	return 0;
}