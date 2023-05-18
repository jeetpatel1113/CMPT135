#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int> a)
{
	vector<int>::iterator it;
	int count = 0;
	for (it = a.begin() ; it < a.end() ; it++)
	{
		//cout <<  "|" << *it;
		count+=3;
	}
	for (int i = 0 ; i < count - 1; i++)
		cout << '-';
	cout << endl;
	for (it = a.begin() ; it < a.end() ; it++)
	{
		cout <<  "|" << *it;
	}
	cout << '|';
	cout << endl;
	for (int i = 0 ; i < count - 1; i++)
		cout << '-';
	cout << endl;
}

int main()
{
	vector<int> a;
	for (int i = 0 ; i < 10 ; i++)
		a.push_back(4 * i);
	cout << "The vector is " << endl;
	printVector(a);

	//Delete an element
	int index = 2;
	vector<int>::iterator it = a.begin() + index;
	a.erase(it);
	cout << "After deleting the element at index " << index << ", the vector is " << endl;
	printVector(a);

	//Delete several elements
	int startIndex = 4, lastIndex = 7;
	a.erase(a.begin() + startIndex, a.begin() + lastIndex);
	cout << "After deleting the elements from " << startIndex << " up to " << lastIndex << ", the vector is" << endl;
	printVector(a);

	//insert an element at a specified position
	a.insert(a.begin(), 21);
	cout << "After inserting 21 at the beginning, the vector is" << endl;
	printVector(a);
	a.insert(a.end(), 29);
	cout << "After inserting 29 at the end, the vector is" << endl;
	printVector(a);
	a.insert(a.begin() + 3, 33);
	cout << "After inserting 33 at index 3, the vector is" << endl;
	printVector(a);
	a.insert(a.begin() + 5, 3, 37);
	cout << "After inserting three elements equal to 37 starting from index 5, the vector is" << endl;
	printVector(a);

	system ("Pause");
	return 0;
}