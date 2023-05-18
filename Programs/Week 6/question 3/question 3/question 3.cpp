#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("F:/FIC/Cmpt135/Programs/Week 6/question 1/question 1/RandomNumber.txt");
	if (fin.fail())
		cout << "This file is not opening." << endl;
	else
	{
		int size = 0, num;
		while (!fin.eof())
		{
			fin >> num;
			size++;
		}
		fin.close();
		int *A = new int[size];
		fin.open("F:/FIC/Cmpt135/Programs/Week 6/question 1/question 1/RandomNumber.txt");
		for (int i = size - 1 ; i >= 0 ; i--)
		{
			fin >> A[i];
		}
		fin.close();
		for (int i = 0 ; i < size ; i++)
			cout << A[i] << endl;
		delete[] A;
	}
	system("Pause");
	return 0;
}