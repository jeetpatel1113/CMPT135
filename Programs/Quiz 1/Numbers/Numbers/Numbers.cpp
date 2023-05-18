#include <iostream>
#include <fstream>
using namespace std;
bool isPrime(int &x)
{
	for (int i = 2 ; i < x ; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	ifstream fin;
	fin.open("Numbers.txt");
	int size = 0;
	int num;
	while (fin.eof() == false)
	{
		fin >> num;
		size ++;
	}
	fin.close();

	int *A = new int [size];
	
	fin.open("Numbers.txt");
	for (int i = 0, first = 0, last = size - 1; i < size ; i++)
	{
		fin >> num;
		if (isPrime(num))
		{
			A[first] = num;
			first++;
		}
		else
		{
			A[last] = num;
			last--;
		}
	}
	fin.close();

	ofstream fout("Numbers.txt");
	for (int i = 0 ; i < size ; i++)
	{
		fout << A[i] << endl;
	}
	fout.close();
	delete[] A;
	return 0;
}