#include <iostream>
using namespace std;
class A
{
public:
	virtual void display() { cout << "A display" << endl; }
};
class B : public A
{
public:
	 virtual void display() { cout << "B display" << endl; }
};
class C : public B
{
public:
	C () { cout << "C constructor" << endl; }
	virtual void display() {cout << "C display" << endl;}
};
void foo(A* p)
{
	p->display();
}
int main() // memory cleanup (deleting) is omitted in the following code
{
	A* ptA = new A;
	B* ptB = new B;
	C* ptC = new C;
	//ptA->display();
	//ptA = ptB;
	//ptA->display();
	//ptA = ptC;
	//foo(ptA);
	//ptA = new C;
	//
	//
	//ptB = dynamic_cast<B*> (ptA) ; // Can you simply do ptB = ptA; ?
	//ptB->display();
	// Any problem with the following code?
	ptA = new A;
	ptB = dynamic_cast<B*> (ptA);
	ptB->display();
	system("Pause");
	return 0;
}