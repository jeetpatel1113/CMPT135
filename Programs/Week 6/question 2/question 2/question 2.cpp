#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("F:/FIC/Cmpt135/Programs/Week 6/question 2/question 2/RandomNumber.txt");
	if (fin.fail())
		cout << "These are all the numbers" << endl;
	else
	{
		int min, max, num;
		fin >> num;
		min = num;
		max = num;
		while (fin.eof() == false)
		{
			fin >> num;
			if (min > num)
				min = num;
			if (max < num)
				max = num;
		}
		cout << min << " = minimim" << endl << max << " = maximim" << endl;
		fin.close();
	}
	system ("Pause");
	return 0;
}