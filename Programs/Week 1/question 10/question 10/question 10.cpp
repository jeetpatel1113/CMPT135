#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct StudentRecord
{
	string name;
	float test, midterm, final; // test (20%), midterm(30%), and final (50%)
	char letterGrade;
};
char calculateGrade(float n)
{
	if (n >= 0 && n < 50)
		return 'F';
	else if (n >= 50 && n < 60)
		return 'D';
	else if (n >= 60 && n < 75)
		return 'C';
	else if (n >= 75 && n < 90)
		return 'B';
	else if (n >= 90 && n <= 100)
		return 'A';
}
string printScore(StudentRecord s)
{
	stringstream ss;
	ss << "Name: " << s.name << endl << "Score of your test: " << s.test << endl << "Score of your midterm: " << s.midterm << endl << "Score of your final: " << s.final << endl << endl << "Your final GRADE: " << s.letterGrade << endl;
	string st = ss.str();
	return st;
}
StudentRecord calculateStudentRecord()
{
	
	StudentRecord s;
	cout << "Please enter name: " << endl;
	cin >> s.name;
	cout << "Please enter the test result out of 20: " << endl;
	cin >> s.test;
	cout << "Please enter the midterm result out of 30: " << endl;
	cin >> s.midterm;
	cout << "Please enter the final result out of 50: " << endl;
	cin >> s.final;
	float numberGrade = s.test + s.midterm + s.final;
	s.letterGrade = calculateGrade(numberGrade);
	return s;
}
void viewRecord(StudentRecord *c, int size, char g)
{
	for (int i = 0 ; i < size ; i++)
		if (c[i].letterGrade == g)
			cout << printScore(c[i]) << endl;
}
StudentRecord searchName(StudentRecord *c, int size, string nam)
{
	for (int i = 0 ; i < size ; i++)
	{
		if (c[i].name == nam)
			return c[i];
	}
	StudentRecord s;
	s.name = "Not Found";
	s.test = -1;
	s.midterm = -1;
	s.final = -1;
	s.letterGrade = 'N';
	return s;
}
StudentRecord getTopStudentRecord(StudentRecord *a, int size)
{
	float max = a[0].final + a[0].test + a[0].midterm;
	StudentRecord s = a[0];
	for (int i = 1 ; i < size ; i++)
	{
		if ((a[i].final + a[i].test + a[i].midterm) > max)
		{
			s = a[i];
			max = a[i].final + a[i].test + a[i].midterm;
		}
	}
	return s;
}
/*
void printStudentRecordsSorted(StudentRecord *a, int size)
{
	cout << viewRecord(a, size, 'A') << endl;
	cout << viewRecord(a, size, 'B') << endl;
	cout << viewRecord(a, size, 'C') << endl;
	cout << viewRecord(a, size, 'D') << endl;
	cout << viewRecord(a, size, 'F') << endl;
}
*/
int main()
{
	
	int num;
	cout << "Please enter number of students: ";
	cin >> num;
	StudentRecord *clss = new StudentRecord[num];
	for (int i = 0 ; i < num ; i++)
		clss[i] = calculateStudentRecord();
	
	string nam;
	cout << "Please enter the name of the person you want to search: " << endl;
	cin >> nam;
	StudentRecord s = searchName(clss, num, nam);
	cout << printScore(s) << endl;
	delete[] clss;
	system ("Pause");
	return 0;
}