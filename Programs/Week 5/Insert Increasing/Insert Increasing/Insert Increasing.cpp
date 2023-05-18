#include <iostream>
#include <vector>
using namespace std;
void printVector(const vector<int> &x)
{
	for (int i = 0; i < x.size(); i++)
		cout << x[i] << " ";
	cout << endl;
}
void insertIncreasing(vector<int> &a, const int x)
{
	int i = 0;
	while (i < a.size())
	{
		if (a[i] < x)
			i++;
		else
			break;
	}
	a.insert(a.begin() + i, x);
}
void insertGrouped(vector<int> &a, const int x)
{
	int i = 0;
	while (i < a.size())
	{
		if (abs(a[i] % 2) != abs(x % 2))
			i++;
		else
			break;
	}
	a.insert(a.begin() + i, x);
}
void insertGroupedIncreasing(vector<int> &a, const int x)
{
	int i = 0;
	while (i < a.size())
	{
		if (abs(a[i] % 2) != abs(x % 2))
			i++;
		else
			break;
	}
	while (i < a.size())
	{
		if (abs(a[i] % 2) != abs(x % 2))
			break;
		else if (a[i] >= x)
			break;
		else
			i++;
	}
	a.insert(a.begin() + i, x);
}
void reOrderElements(vector<int> &a)
{
	vector<int> x;
	for (int i = 0 ; i < a.size() ; i ++)
		insertGroupedIncreasing(x, a[i]);
	a = x;
}


int main()
{
	vector<int> a(10);
	for (int i = 0; i < 10; i++)
	{
		int num = rand() % 11 - 5;
		a[i] = num;
	}
	printVector(a);
	reOrderElements(a);
	printVector(a);


	system("Pause");
	return 0;
}