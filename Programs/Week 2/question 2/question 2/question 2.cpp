#include <iostream>
using namespace std;

class Number
{
private:
	int value;
public:
	Number();
	Number(int);
	int getValue();
	void setValue(int);
};

Number::Number()
{
	value = 0;
}
Number:: Number(int newValue)
{
	value = newValue;
}
// setValue not defined
void Number::setValue(int a)
{
	value = a;
}
int Number::getValue()
{
	return value; // systax error
}
int main()
{
	Number n1, n2;
	n2.setValue(5);
	n1.setValue(1);
	cout << "n1 is " << n1.getValue() << " and n2 is " << n2.getValue() << endl;
	cout << n2.getValue() / n1.getValue() << endl; // devide by 0 cannot happen
	if (n2.getValue() > n1.getValue())
		cout << "n2 has larger value than n1. " << endl;
	else 
		cout << "n1 has larger value than n2." << endl;
	system("Pause");
	return 0;
}