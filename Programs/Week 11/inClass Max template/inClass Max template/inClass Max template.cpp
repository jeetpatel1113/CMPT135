#include <iostream>
#include <string>
#include <ctime>
using namespace std;

template <typename T>
T getMaxValue(const T *A, const int size)
{
	T m = A[0];
	for (int i = 1 ; i < size ; i++)
		if (A[i] > m)
			m = A[i];
	return m;
}

int main()
{
	//Construct several arrays of diffeernt datatypes
	const int size = 10;
	int *A1 = new int[size];
	double *A2 = new double[size];
	string *A3 = new string[size];

	srand(time(0));

	for (int i = 0 ; i < size ; i++)
	{
		A1[i] = rand() % 21 + 5;
		A2[i] = ((1.0 * rand()) / RAND_MAX) * 15.0 + 5.0;
		int random = rand() % 5;
		A3[i] = (random == 0 ? "Paul" : 
			(random == 1 ? "Jannet" : 
			(random == 2 ? "Kevin" : 
			(random == 3 ? "Sara" : "CMPT"))));
	}

	//Print the arrays
	cout << "Here are the arrays created..." << endl << endl;
	cout << "Array A1\tArray A2\tArray A3" << endl;
	cout << "========\t========\t========" << endl;
	for (int i = 0 ; i < size ; i++)
		cout << A1[i] << "\t\t" << A2[i] << "\t\t" << A3[i] << endl;
	cout << endl;

	int m1 = getMaxValue(A1, size);
	double m2 = getMaxValue(A2, size);
	string m3 = getMaxValue(A3, size);

	cout << "Maximum element of A1 = " << m1 << endl;
	cout << "Maximum element of A2 = " << m2 << endl;
	cout << "Maximum element of A3 = " << m3 << endl;

	system ("Pause");
	return 0;
}