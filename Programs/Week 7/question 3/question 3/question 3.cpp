#include <iostream>
#include <vector>
using namespace std;
void pop_front(vector<int>& x)
{
	vector<int> temp;
	for (int i = 0 ; i < x.size() - 1 ; i++)
		temp.push_back(x[i + 1]);
	x = temp;
}
int main()
{
	vector<int> a;
	for (int i = 0 ; i < 5 ; i++)
		a.push_back(rand() %20);
	for (int i = 0 ; i < a.size() ; i++)
		cout << a[i] << endl;
	cout << endl;
	pop_front(a);
	for (int i = 0 ; i < a.size() ; i++)
		cout << a[i] << endl;
	system("Pause");
	return 0;
}