#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
	/*
	srand(time(0));
	//Construct a default vector object to store integers
	vector<int> a;
	//Put five integer values in the vector
	cout << "Populating the vector" << endl;
	for (int i = 0; i < 5; i++)
	a.push_back(rand() % 20);
	//Print the elements of the vector
	cout << "Printing the vector elements" << endl;
	for (vector<int>::iterator it = a.begin(); it < a.end(); it++)
	cout << *it << endl;
	system("Pause");
	return 0;
	*/
	srand(time(0));
	//Construct a default vector object to store integers
	vector<int> a;

	//Put five integer values in the vector
	cout << "Populating the vector" << endl;
	for (int i = 0; i < 5; i++)
		a.push_back(rand() % 20);

	//Print the elements of the vector
	cout << "Printing the vector elements" << endl;
	for (vector<int>::iterator it = a.begin(); it < a.end(); it++)
		cout << *it << endl;
	system("Pause");
	return 0;
}