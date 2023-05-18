#include <iostream>
using namespace std;

class A
{
public:
		A()
		{
			cout << "Constructing A object" << endl;
		}
		~A()
		{
			cout << "Destructing A object" << endl;
		}
};
class B : public A
{
public:
		B()
		{
			cout << "Constructing B object" << endl;
		}
		~B()
		{
			cout << "Destructing B object" << endl;
		}
};
class C : public B
{
public:
		C() : B()
		{
			cout << "Constructing C object" << endl;
		}
		~C()
		{
			cout << "Destructing C object" << endl;
		}
};
int main()
{
A* a;
a = new C();
delete a;
system("Pause");
return 0;
}