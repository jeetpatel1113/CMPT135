#include <iostream>
using namespace std;

class A
{
private:
	int v;
public:
	A()
	{
		setValue(0);
	}
	A(const int &v)
	{
		setValue(v);
	}
	int getValue() const
	{
		return v;
	}
	void setValue(const int &vi)
	{
		v = vi;
	}
	A subtract (const A &a) const
	{
		return A(getValue() - a.getValue());
	}
};

int main()
{
	A a1, a2(8), a3(2);
	cout << a1.getValue() << ", " << a2.getValue() << ", " << a3.getValue() << endl;
	cout << a1.subtract(a2).getValue() << endl;
	cout << a3.subtract(a2).getValue() << endl;
	system ("Pause");
	return 0;
}