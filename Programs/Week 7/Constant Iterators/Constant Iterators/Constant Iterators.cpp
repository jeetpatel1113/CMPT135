#include <iostream>
#include <vector>
using namespace std;

void printVectorForwardReverse(const vector<double> &x)
{
	cout << "The elements of the vector in a forward order are" << endl;
	for (vector<double>::const_iterator it = x.begin() ; it < x.end() ; it++)
		cout << *it << "  ";
	cout << endl;
	cout << "The elements of the vector in a reverse order are" << endl;
	for (vector<double>::const_reverse_iterator itr = x.rbegin() ; itr < x.rend() ; itr++)
		cout << *itr << "  ";
	cout << endl;
}

int main()
{
	vector<double> v;
	for (int i = 0 ; i < 5 ; i++)
		v.push_back(1.0 * rand()/RAND_MAX * 2 - 1);
	printVectorForwardReverse(v);
	system("Pause");
	return 0;
}