#include <iostream>
#include <fstream>
using namespace std;
void editing(ifstream &fin, ofstream &fout)
{
	if (fin.eof())
	{
		fin.close();
		fout.open("F:/FIC/Cmpt135/Programs/Week 6/question 5/question 5/Numbers.txt");
	}
	else
	{
		int num;
		fin >> num;
		editing(fin, fout);
		fout << num << endl;
	}
}
int main()
{
	ifstream fin("F:/FIC/Cmpt135/Programs/Week 6/question 5/question 5/Numbers.txt");
	if (fin.fail())
		cout << "Input file failed. Bye" << endl;
	else
	{
		ofstream fout;
		editing(fin, fout);
		fout.close();
	}
}