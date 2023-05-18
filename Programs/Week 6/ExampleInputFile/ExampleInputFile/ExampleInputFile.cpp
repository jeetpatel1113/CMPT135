#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("ExampleInputFile.txt");
	int x, m;
	fin >> m;
	for (int i = 0 ; i < 4 ; i++)
	{
		fin >> x;
		if (x < m)
			m = x;
	}
	fin.close();
	cout << "The minimum number in the file is " << m << endl;

	system ("pause");
	return 0;
}