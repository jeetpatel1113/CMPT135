#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct student
{
	string fnam, lnam;
	int test1, test2, test3;
	char grade;
};
char calculateGrade(int test1, int test2, int test3)
{
	char grade;
	int total = test1 + test2 + test3;
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
	return grade;
}
int main()
{
	ifstream fin("F:/FIC/Cmpt135/Programs/Week 6/question 6/question 6/ClassList.txt");
	//ofstream fout("F:/FIC/Cmpt135/Programs/Week 6/question 6/question 6/Report.txt");
	if (fin.fail())
		cout << "Input file failed. Bye" << endl;
	else

	{
		string fnam, lnam;
		int test1, test2, test3;
		char grade;
		int size = 0;
		while (!fin.eof())
		{
			fin >> fnam >> lnam >> test1 >> test2 >> test3;
			size++;
		}
		cout << "SIZE CALCULATED" << endl;
		fin.close();
		cout << size << endl;
		ifstream fin("F:/FIC/Cmpt135/Programs/Week 6/question 6/question 6/ClassList.txt");
		if (fin.fail())
		{
			cout << "BYE BYE------ " << endl;
		}
		else
		{
			student *A = new student [size];
			for (int i = 0 ; i < size ; i++)
			{
				fin >> A[i].fnam >> A[i].lnam >> A[i].test1 >> A[i].test2 >> A[i].test3;
				A[i].grade = calculateGrade(test1, test2, test3);
			}
			cout << "FIN READ STUDENTS IN ARRAY" << endl;
			fin.close();
			for (int i = 0 ; i < size ; i++)
			{
				cout <<  A[i].fnam << ' ' << A[i].lnam << '\t' << A[i].test1 << '\t' << A[i].test2 << '\t' << A[i].test3 << '\t' << endl;
			}
			ofstream fout("F:/FIC/Cmpt135/Programs/Week 6/question 6/question 6/ClassList.txt");
			if (fout.fail())
			{
				cout << "BYE BYE------ " << endl;
			}
			else
			{
				for (int i = 0 ; i < size ; i++)
				{
					fout <<  A[i].fnam << ' ' << A[i].lnam << '\t' << A[i].test1 << '\t' << A[i].test2 << '\t' << A[i].test3 << '\t' << A[i].grade << endl;
				}
				cout << "FOUTING CLASS LIST" << endl;
				fout.close();
				delete[] A;
			}
		}
	}
	system("Pause");
	return 0;
}