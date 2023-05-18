#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> a;
	for (int i = 0 ; i < 5 ; i++)
		a.push_back(4*i);

	cout << "The elemenets of the vector are " << endl;
	vector<int>::iterator it;
	for (it = a.begin() ; it < a.end() ; it++)
		cout << *it << endl;

	cout << "The elements of the vector in reverse are" << endl;
	for (vector<int>::reverse_iterator itr = a.rbegin() ; itr < a.rend() ; itr++)
		cout << *itr << endl;

	it = a.begin() + 3;
	*it = -1;

	cout << "The elements of the modified vector are" << endl;
	for (it = a.begin() ; it < a.end() ; it++)
		cout << *it << endl;

	system("pause");
	return 0;
}