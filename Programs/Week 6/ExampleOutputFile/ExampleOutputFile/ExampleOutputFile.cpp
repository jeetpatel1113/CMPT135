#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	/*
	ofstream fout("ExampleOutputFile.txt");			
	fout << "Hello there... this is line 1" << endl;
	for (int k = 0 ; k < 7 ; k++)
	{
		fout << k << "\t" << pow(k, 2.0) << "\t" << sqrt(1.0*k) << endl;
	}
	fout << "Goodbye." << endl;
	fout.close();
	*/
	ofstream fout ("ExampleOutputFile.txt", ios::app);
	fout << "This is appended at the end of the file." << endl;
	fout << "Goodbye again." << endl;
	fout.close();



	system("Pause");
	return 0;
}