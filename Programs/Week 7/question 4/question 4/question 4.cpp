#include <iostream>
#include <vector>
using namespace std;
vector<double> operator+(vector<double> a, vector<double> b)
{
	vector<double> temp;
	for (vector<double>::iterator it = a.begin() ; it < a.end() ; it++)
		temp.push_back(*it);
	for (vector<double>::iterator it = b.begin() ; it < b.end() ; it++)
		temp.push_back(*it);
	return temp;
}
int main()
{
	vector<double> a, b;
	for (int i = 0 ; i < 5 ; i++)
	{
		a.push_back(rand()%20);
		b.push_back(rand()%20);
	}
	for (vector<double>::iterator it = a.begin() ; it < a.end() ; it++)
		cout << *it << endl;
	cout << endl;
	for (vector<double>::iterator it = b.begin() ; it < b.end() ; it++)
		cout << *it << endl;
	cout << endl;
	vector<double> c = a + b;
	for (vector<double>::iterator it = c.begin() ; it < c.end() ; it++)
		cout << *it << endl;
	system("Pause");
	return 0;
}