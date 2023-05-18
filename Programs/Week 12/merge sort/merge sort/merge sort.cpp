#include <iostream>
using namespace std;

void merge(int *A, const int& start_index, const int& middle_index, const int& last_index)
{
	int size = last_index - start_index + 1;
	int *temp = new int[size];
	int i = start_index, j = middle_index + 1, k = 0;
	while (i <= middle_index && j <= last_index)
		if (A[i] < A[j])
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];
	while (i <= middle_index)
		temp[k++] = A[i++];
	while (j <= last_index)
		temp[k++] = A[j++];

	for (int i = start_index, k = 0 ; i <= last_index ; i++, k++)
		A[i] = temp[k];
	delete[] temp;
}

void mergesort (int* A, const int& start_index, const int& last_index)
{
	if (start_index >= last_index)
		return;
	else
	{
		int middle_index = (start_index + last_index) / 2;
		mergesort (A, start_index, middle_index);
		mergesort (A, middle_index + 1, last_index);
		merge (A, start_index, middle_index, last_index);
	}
}


int main()
{
	const int size = 10000;
	int A[size];
	for (int i = 0 ; i < size ; i++)
		A[i] = rand();


	mergesort(A, 0, size - 1);


	system ("Pause");
	return 0;
}