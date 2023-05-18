#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
	
	srand(time(0));
	int x = rand() % 100;
	int y = rand() % 100;
	cout<<"The value of x is "<< x <<" and that of y is "<< y <<endl;
	/*
	if (x % 2 == 0 && y % 2 == 0)
		cout<<"Both even."<<endl;
	else if (x % 2 == 0 && y % 2 != 0)
		cout<<"x is even but y is odd."<<endl;
	else if (x % 2 != 0 && y % 2 == 0)
		cout<<"x is odd but y is even."<<endl;
	else
		cout<<"Both odd."<<endl;
	*/
	int p = x % 2;
	int q = y % 2;
	switch(p)
	{
	case 0:
		cout << "X is even" << endl;
		break;
	case 1:
		cout << "X is odd" << endl;
		break;
	default:
		cout << "X is non negative number" << endl;
		break;
	}
	switch(q)
	{
	case 0:
		cout << "Y is even" << endl;
		break;
	case 1:
		cout << "Y is odd" << endl;
		break;
	default:
		cout << "Y is non negative number" << endl;
		break;
	}
	system("Pause");
	return 0;
}