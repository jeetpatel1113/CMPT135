#include <iostream>
#include <string>
using namespace std;
class Fruit
{
private:
	int weightInGrams;
	string color;
	static int counter;
public:
	Fruit():weightInGrams(0), color("")
	{
		cout << "Inside default constructor." << endl;
		counter++;
	}
	Fruit(const int &w, const string &c):weightInGrams(w), color(c)
	{
		cout << "Inside non-default constructor." << endl;
		counter++;
	}
	Fruit(const Fruit &f):weightInGrams(f.getWeight()), color(f.getColor())
	{
		cout << "Inside copy constructor." << endl;
		counter++;
	}
	~Fruit()
	{
		cout << "Inside destructor." << endl;
		counter--;
	}
	Fruit& operator = (const Fruit &f)
	{
		cout << "Inside assignment operator." << endl;
		setWeight(f.getWeight());
		color = f.getColor();
		return *this;
	}
	int getWeight() const
	{
		return weightInGrams;
	}
	string getColor() const
	{
		return color;
	}
	void setWeight(const int &w)
	{
		weightInGrams = w;
	}
	void setColor(const string &c)
	{
		color = c;
	}
	static int getCounter()
	{
		return Fruit::counter;
	}
};
int Fruit::counter = 0;
const Fruit& foo1(const Fruit f1, const Fruit &f2, const Fruit *f3)
{
	cout << "In foo1, starting with " << Fruit::getCounter() << " fruits." << endl;
	Fruit f = f1;
	if (f2.getWeight() > f.getWeight())
		f = f2;
	if (f3->getWeight() > f.getWeight())
		f = *f3;
	cout << "In foo1, finishing with " << Fruit::getCounter() << " fruits." << endl;
	return f2;
}
Fruit foo2(const Fruit f1, const Fruit &f2, const Fruit *f3)
{
	cout << "In foo2, starting with " << Fruit::getCounter() << " fruits." << endl;
	Fruit f = f1;
	if (f2.getWeight() > f.getWeight())
		f = f2;
	if (f3->getWeight() > f.getWeight())
		f = *f3;
	cout << "In foo2, finishing with " << Fruit::getCounter() << " fruits." << endl;
	return f;
}
int main()
{
	Fruit f1;
	f1.setWeight(5);
	f1.setColor("Green");
	Fruit f2(10, "Yellow");
	Fruit f3 = f2;
	cout << "In main before foo1, there are " << Fruit::getCounter() <<" fruits." << endl;
	Fruit f4 = foo1(f1, f2, &f3);
	cout << "In main after foo1, there are " << Fruit::getCounter() << " fruits." << endl;
	cout << "In main before foo2, there are " << Fruit::getCounter() << " fruits." << endl;
	Fruit f5 = foo2(f1, f2, &f3);
	cout << "In main after foo2, there are " << Fruit::getCounter() << " fruits." << endl;
	system("Pause");
	return 0;
}/*inside default constructorinside non default constructorinside copy constructorIn main before fool, there are 3 fruitsIn foo1, starting with 4 fruits.In foo1, finishing with 5 fruits.In main after foo1, there are 4 fruits.In main before foo2, there are 4 fruits.In foo2, starting with 5 fruits.In foo2, finishing with 6 fruits.In main after foo2, there are 5 fruits.f1w 5c greenf2w 10c Yellowf3w 10c Yellowf4w 10c Yellowf5w c fw 5c greencount4*/