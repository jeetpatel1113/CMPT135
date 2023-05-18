#include <iostream>
#include <fstream>
using namespace std;
void addingReverseArray(ifstream &fin, ofstream &fout)
{
	if (fin.eof())
	{
		fin.close();
		fout.open("F:/FIC/Cmpt135/Programs/Week 6/question 1/question 1/RandomNumber.txt");
	}
	else
	{
		int num;
		fin >> num;
		addingReverseArray(fin, fout);
		fout << num << endl;
	}
}
int main()
{
	ifstream fin("F:/FIC/Cmpt135/Programs/Week 6/question 1/question 1/RandomNumber.txt");
	if (fin.fail())
		cout << "This file didnt open." << endl;
	else
	{
		ofstream fout;
		addingReverseArray(fin, fout);
		fout.close();
	}
	system ("pause");
	return 0;
}