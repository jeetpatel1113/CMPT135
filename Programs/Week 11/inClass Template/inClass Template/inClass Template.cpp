#include <iostream>
#include <string>
#include <ctime>
using namespace std;
template <class T>
int sequentialSearch(const T* A, const int size, const T& searchValue)
{
	for (int i = 0 ; i < size ; i++)
	{
		if (A[i] == searchValue)
			return i;
		else
			continue;
	}
	return -1;
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

	//Perform some searches using sequential search algorithm
	int s1 = rand() % 21 + 5;
	double s2 = A2[rand() % size];
	string s3 = "Sara";
	
	int ans1 = sequentialSearch(A1, size, s1);
	int ans2 = sequentialSearch(A2, size, s2);
	int ans3 = sequentialSearch(A3, size, s3);

	//Display search results
	if (ans1 == -1)
		cout << s1 << " is not found in the array A1" << endl;
	else
		cout << s1 << " is found in the array A1 at index" << ans1 << endl;
	
	if (ans2 == -1)
		cout << s2 << " is not found in the array A2" << endl;
	else
		cout << s2 << " is found in the array A2 at index" << ans2 << endl;
	
	if (ans3 == -1)
		cout << s3 << " is not found in the array A3" << endl;
	else
		cout << s1 << " is found in the array A3 at index" << ans3 << endl;

	system ("Pause");
	return 0;
	
}