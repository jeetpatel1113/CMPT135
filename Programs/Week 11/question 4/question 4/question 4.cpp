#include <iostream>
using namespace std;
template<class T>
T binarysearch(const T* A, const int& size, const T &n)
{
	int findex = 0, lindex = size - 1;
	while (findex <= lindex)
	{
		int midindex = (findex + lindex) / 2;
		if (A[midindex] == n)
			return midindex;
		else if (A[midindex] > n)
			lindex = midindex - 1;
		else
			findex = midindex + 1;
	}
	return -1;
}
int main()
{
	int A[5] = {1, 2, 3, 4, 5};
	double B[5] = {1.22, 2.40, 5.32, 6.49, 9.3};
	char C[5] = {'a', 'b', 'c', 'd', 'e'};
	cout << binarysearch(A, 5, 4);
	cout << binarysearch(B, 5, 2.4);
	cout << binarysearch(C, 5, 'e');
	system("Pause");
	return 0;
}