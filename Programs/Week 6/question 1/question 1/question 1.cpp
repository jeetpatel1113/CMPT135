#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fout("RandomNumber.txt");
	int num = rand() % (100 - 50 + 1) + 50;
	for (int i = 0 ; i < num ; i++)
		fout << rand() % (999 - 0 + 1) + 0 << endl;
	fout.close();
}