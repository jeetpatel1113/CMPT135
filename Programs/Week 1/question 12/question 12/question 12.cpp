#include <iostream>
using namespace std;

struct StudentRecord
{
	int size;
	char c;

	void print()
	{
		cout << size << " --> " << c << endl;
	}
};