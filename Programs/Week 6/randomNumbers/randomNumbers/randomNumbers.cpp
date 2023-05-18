#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
	/*
	//Question 1
	srand(time(0));
	ofstream fout("randomNumbers.txt");
	int size = rand() % (100 - 50 + 1) + 50;
	for (int i = 0 ; i < size ; i++)
	{
		fout << rand() % (999 - 0 + 1) + 0 << endl;
	}
	fout.close();
	return 0;
	*/
	
	//Question 2
	ifstream fin("F:/FIC/Cmpt135/Programs/Week 6/randomNumbers/randomNumbers/randomNumbers.txt");
	int num;
	fin >> num;
	int min = num;
	int max = num;
	while (fin.eof() == false)
	{

	}
	fin.close();
}