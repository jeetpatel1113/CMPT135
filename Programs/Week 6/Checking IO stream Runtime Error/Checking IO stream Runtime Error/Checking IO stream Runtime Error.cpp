#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	//Open output file stream
	ofstream fout ("F:/FIC/Cmpt135/Programs/Week 6/Checking IO stream Runtime Error/Checking IO stream Runtime Error.txt");
	if (fout.fail())
		cout << "Output file stream failed. Goodbye" << endl;
	else
	{
		for (int i = 0 ; i < 15 ; i++)
			fout << rand()%20 << " ";
		fout.close();
	}

	
	system ("pause");
	return 0;
}