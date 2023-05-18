#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("F:/FIC/Cmpt135/Programs/Week 6/ClassList/ClassList/ClassList.txt");
	ofstream fout("F:/FIC/Cmpt135/Programs/Week 6/ClassList/ClassList/Report.txt");
	if (fin.fail())
		cout << "Input file not found. Goodbye." << endl;
	else if (fout.fail())
		cout << "Output file not found. Goodbye." << endl;
	else
	{
		string fname, lname;
		int exercise, project, final, total;
		char grade;
		for (int i = 0 ; i < 5 ; i++)
		{
			fin >> fname >> lname >> exercise >> project >> final;
			total = exercise + project + final;
			if (total >= 90)
				grade = 'A';
			else if (total >= 75)
				grade = 'B';
			else if (total >= 65)
				grade = 'C';
			else if (total >= 50)
				grade = 'D';
			else
				grade = 'F';
			fout << fname << " " << lname << "\t" << exercise << '\t' << project << "\t" << final << "\t" << grade << endl;
		}
		//Close the inout/out file streams
		fin.close();
		fout.close();
	}
	system ("Pause");
	return 0;
}