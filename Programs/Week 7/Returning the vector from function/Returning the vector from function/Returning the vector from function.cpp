#include <iostream>
#include <vector>
using namespace std;

vector<int> getPopulatedVector(const int n)
{
	vector<int> x;
	for (int i = 0 ; i < n ; i++)
		x.push_back(rand() % 31 - 10);
	return x;
}

void printVector(const vector<int> &x)
{
	for (int i = 0 ; i < x.size() ; i++)
		cout << x[i] << "    ";
	cout << endl;
}

int main()
{
	int n;
	cout << "How many elements would you like to have in the vector? ";
	cin >> n;
	vector<int> a;
	a = getPopulatedVector(n);
	cout << "After the function call, vector a = ";
	printVector(a);
	system("Pause");
	return 0;
}