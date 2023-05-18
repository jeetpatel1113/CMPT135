#include <iostream>
using namespace std;
int countInteger (const int* A, const int& size, const int& num, int& count)
{
	if (size == 1)
		if (A[size] == num)
			return ++count;
		else
			return count;
	else
	{
		if (A[size - 1] == num)
			count++;
		countInteger (A, size - 1, num, count);
		//return count;
	}
}


int main()
{
	int A[12] = {1,1,1,1,2,2,3,4,5,6,7,6};
	
	cout << '[';
	for (int i = 0 ; i < 12 ; i++)
		cout << A[i] << ", ";
	cout << ']' << endl;

	int num = 0;
	cout << countInteger (A, 12, 1, num) << endl;

	cout << '[';
	for (int i = 0 ; i < 12 ; i++)
		cout << A[i] << ", ";
	cout << ']' << endl;
	system ("Pause");
	return 0;
}