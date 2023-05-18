#include <iostream>
#include <vector>
using namespace std;

void populateVector1(vector<int> x, const int n)
{
	for (int i = 0 ; i < n ; i++)
		x.push_back(rand() % 31 - 10);
}
void populateVector2(vector<int> *x, const int n)
{
	for (int i = 0 ; i < n ; i++)
		x->push_back(rand() % 31 - 10);
}
void populateVector3(vector<int> &x, const int n)
{
	for (int i = 0 ; i < n ; i++)
		x.push_back(rand() % 31 - 10);
}
void printVector(const vector<int> &x)
{
	for (int i = 0 ; i < x.size() ; i++)
		cout << x[i] << "	";
	cout << endl;
}

int main()
{
	vector<int> a, b, c;
	int n;
	cout << "How many elements would you like to have in the vector? ";
	cin >> n;
	populateVector1(a, n);
	populateVector2(&b, n);
	populateVector3(c, n);
	cout << "After the function calls, ..." << endl;
	cout << "Vector a = "; printVector(a);
	cout << "vector b = "; printVector(b);
	cout << "Vector c = "; printVector(c);

	system("Pause");
	return 0;
}