#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<char> &x)
{
	for (int i = 0 ; i < x.size() ; i++)
		cout << x[i] << "	";
	cout << endl;
}

int main()
{
	vector<char> a;
	for (int i = 0 ; i < 5 ; i++)
		a.push_back(97 + i);
	cout << "The elements of the vector are: ";
	printVector(a);
	cout << "The front element of the vector is " << a.front() << endl;
	cout << "The back element of the vector is " << a.back() << endl;

	//Delete the last element
	a.pop_back();

	cout << "The elements of the vector after deleting the last element are: ";
	printVector(a);
	cout << "The front element of the vector is " << a.front() << endl;
	cout << "The back element of the vector is " << a.back() << endl;

	system("Pause");
	return 0;
}