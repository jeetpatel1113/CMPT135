#include <iostream>
using namespace std;
int f1(int x) 
{
	if (x > 0)
		return x + f1(x-1);
	else
		return 1;
}int f2(int x) 
{
	if (x < 12)
		return x + f2(x*2);
	else
		return x;
}int f3(int x) 
{
	if (x > 2)
		return x * f3(x-2);
	else
		return 1;
}
int f4(int x) 
{
	if (x > 0)
		return x + f4(x/3);
	else
		return 0;
}
int f5(int x) 
{
	if (x > 0)
		return x * f5(x-1);
	else
		return 0;
}
void f6(int x) 
{
	if (x > 0)
	{
		cout<< x <<" ";
		f6(x-1);
	}
}void f7(int x) 
{
	if (x > 0)
	{
		f7(x-1);
		cout<< x <<" ";
	}
}void f8(int x) 
{
	if (x > 0)
	{
		cout<< x <<" ";
		f8(x-1);
		cout<< x <<" ";
	}
}
void f9(int x) 
{
	if (x > 0)
	{
		f9(x-1);
		cout<< x <<" ";
		f9(x-1);
	}
}
int main()
{
	/*cout << "Question 1 : " << f1(3) << endl;
	cout << "Question 2 : " << f2(1) << endl;
	cout << "Question 3 : " << f3(7) << endl;
	cout << "Question 4 : " << f4(100) << endl;
	cout << "Question 5 : " << f5(3) << endl;*/
	cout << "Question 6 : " << endl; f6(3); cout << endl;
	cout << "Question 7 : " << endl; f7(3); cout << endl;
	cout << "Question 8 : " << endl; f8(3); cout << endl;
	cout << "Question 9 : " << endl; f9(3); cout << endl;
	system ("Pause");
	return 0;
}