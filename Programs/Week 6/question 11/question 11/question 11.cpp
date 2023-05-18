#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int n;
	cout << "Please enter number: " << endl;
	cin >> n;
	ofstream fout ("F:/FIC/Cmpt135/Programs/Week 6/question 11/question 11/multiplicationTable.txt");
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
			fout << i*j << "  ";
		fout << endl;
	}
	fout.close();
}