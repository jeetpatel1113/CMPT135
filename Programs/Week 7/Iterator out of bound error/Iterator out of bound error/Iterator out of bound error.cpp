#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<bool> a;
	for (int i = 0 ; i < 5 ; i++)
		a.push_back(rand() % 2);
	vector<bool>::iterator it;
	it = a.end();
//	cout << "The last element of the vector is " << *it << endl;
	cout << "The elements of the vector in reverse scam are " << endl;
	for (it = a.end() - 1 ; it > a.begin() ; it--)
		cout << *it << endl;
	system ("PausE");
	return 0;
}