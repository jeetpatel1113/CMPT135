#include <iostream>
#include <vector>
using namespace std;
vector<int> operator * (const vector<int> &a, const int x)
{
	vector<int> temp;
	for (int j = 0 ; j < x ; j++)
		for (int i = 0 ; i < a.size() ; i++)
			temp.push_back(a[i]);
	return temp;
}
void swap(vector<int> &a, vector<int> &b)
{
	vector<int> temp = a;
	a = b;
	b = temp;
}
int main()
{
	vector<int> a, b;
	for (int i = 0 ; i < 5 ; i++)
	{
		a.push_back(rand()%20);
		b.push_back(rand()%20);
	}
	for (vector<int>::iterator it = a.begin() ; it < a.end() ; it++)
		cout << *it << "  ";
	cout << endl;
	for (vector<int>::iterator it = b.begin() ; it < b.end() ; it++)
		cout << *it << "  ";
	cout << endl;
	/*
	vector<int> c = a * 0;
	for (vector<int>::iterator it = c.begin() ; it < c.end() ; it++)
		cout << *it << endl;
	*/
	swap(a, b);
	for (vector<int>::iterator it = a.begin() ; it < a.end() ; it++)
		cout << *it << "  ";
	cout << endl;
	for (vector<int>::iterator it = b.begin() ; it < b.end() ; it++)
		cout << *it << "  ";
	cout << endl;
	system("Pause");
	return 0;
}