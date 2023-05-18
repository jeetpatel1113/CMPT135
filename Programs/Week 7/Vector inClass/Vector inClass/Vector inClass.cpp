#include <iostream>
#include <string>
#include <vector>
using namespace std;
void createline()
{
	for (int i = 0 ; i < 100 ; i++)
		cout << "-";
	cout << endl;
}
int main()
{
	//Printing elements of A1, A2, A3, A4
	
	vector<int> A1;
	vector<float> A2(5);
	vector<string> A3(3, "FIC");
	vector<int> A4(A1);
	cout << A1.size() << ", " << A2.size() << ", " << A3.size() << ", and " << A4.size() << endl;

	cout << "Elements of vector A1" << endl;
	for (int i = 0 ; i < A1.size() ; i++)
		cout << A1[i] << endl;
	cout << endl << endl;

	cout << "Elements of vector A2" << endl;
	for (int i = 0 ; i < A2.size() ; i++)
		cout << A2[i] << endl;
	cout << endl << endl;

	cout << "Elements of vector A3" << endl;
	for (int i = 0 ; i < A3.size() ; i++)
		cout << A3[i] << endl;
	cout << endl << endl;

	cout << "Elements of vector A4" << endl;
	for (int i = 0 ; i < A4.size() ; i++)
		cout << A4[i] << endl;
	cout << endl << endl;
	
	createline();
	/*
	//Push Element
	vector<int> a;
	//push_back five integers to the vector
	for (int i = 0 ; i < 5 ; i++)
		a.push_back(2 * i + 1);
	//print the vector
	for (int i = 0 ; i < a.size() ; i++)
		cout << a[i] << "	";
	*/
	createline();
	/*
	vector<double> *b;
	b = new vector<double>;
	for (int i = 0 ; i < 5 ; i++)
		b->push_back(1.0 * rand()/RAND_MAX * 10 - 5);
	cout << "The vector has " << b->size() << " elements." << endl;
	for (int i = 0 ; i < b->size() ; i++)
		cout << (*b)[i] << endl;
	delete b;
	cout << "After deleting the size of the vector is " << b->size() << endl;
	*/
	/*
	vector<double> c;
	for (int i = 0 ; i < 5 ; i++)
		c.push_back(1.0 * rand()/RAND_MAX * 10 - 5);
	vector<double> &d = c;
	cout << "The vector has " << d.size() << " elements." << endl;
	cout << "The elements are" << endl;
	for (int i = 0 ; i < c.size() ; i++)
		cout << c[i] << endl;
	cout << "Using the reference variable, the elements are" << endl;
	for (int i = 0 ; i < d.size() ; i++)
		cout << d[i] << endl;
	cout << endl;
	*/


	system("Pause");
	return 0;
}