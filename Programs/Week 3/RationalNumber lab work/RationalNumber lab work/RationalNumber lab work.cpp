#include <iostream>
#include <ctime>
using namespace std;

class RationalNumber
{
private:
	int a, b;
public:
	//Constructors
	RationalNumber();
	RationalNumber(const int &, const int &);

	//Getters
	int getNumerator() const;
	int getDenominator() const;

	//Setters
	void setNumerator(const int &);
	void setDenominator(const int &);


	//Additional members functions
	void standardize();
	void reduce();

	//print
	void print() const;

	//LAB WORK
	bool isNotEqual(const RationalNumber &) const;
	bool isGreaterThan(const RationalNumber &) const;
	bool isLessThan(const RationalNumber &) const;
	bool isGreaterOrEqual(const RationalNumber &) const;
	bool isLessOrEqual(const RationalNumber &) const;
	void assignRationalNumber();

};

int main()
{
	srand(time(0));
	int size;
	cout << "Please enter the number of RationalNumbers you want to enter: ";
	cin >> size;
	RationalNumber *r = new RationalNumber[size];
	for (int i = 0 ; i < size ; i++)
		r[i].assignRationalNumber();
	RationalNumber min, max;
	min = r[0];
	max = r[0];
	for (int i = 0 ; i < size ; i++)
	{
		if (min.isGreaterThan(r[i]))
			min = r[i];
		if (max.isLessThan(r[i]))
			max = r[i];
	}
	for (int i = 0 ; i < size ; i++)
	{
		r[i].print();
		cout << endl;
	}
	cout << "The minimum rational number is: "; min.print(); cout << endl;
	cout << "The maximum rational number is: "; max.print(); cout << endl;
	if (max.getNumerator() < 0)
		cout << "No minimum or maximum positive elements." << endl;

	/*
	if (r1.isNotEqual(r2))
	{
		r1.print() ; cout << " is not equal to " ; r2.print(); cout << " ." << endl;
	}
	if (r1.isGreaterOrEqual(r2))
	{
		r1.print() ; cout << " is greater than or equal to " ; r2.print(); cout << " ." << endl;
	}
	if (r1.isGreaterThan(r2))
	{
		r1.print() ; cout << " is greater than " ; r2.print(); cout << " ." << endl;
	}
	if (r1.isLessOrEqual(r2))
	{
		r1.print() ; cout << " is less than or equal to " ; r2.print(); cout << " ." << endl;
	}
	if (r1.isLessThan(r2))
	{
		r1.print() ; cout << " is less than " ; r2.print(); cout << " ." << endl;
	}
	*/

	delete[] r;
	system ("Pause");
	return 0;
}



//Constructors
RationalNumber::RationalNumber()
{
	a = 0;
	b = 1;
}
RationalNumber::RationalNumber(const int &num, const int &dec)
{
	a = num;
	b = dec;
	standardize();
	reduce();
}

//Getters
int RationalNumber::getDenominator() const
{
	return b;
}
int RationalNumber::getNumerator() const
{
	return a;
}

//Setters
void RationalNumber::setDenominator(const int &x)
{
	b = x;
	standardize();
	reduce();
}
void RationalNumber::setNumerator(const int &y)
{
	a = y;
	standardize();
	reduce();
}

//standardize
void RationalNumber::standardize()
{
	if (b < 0)
	{
		a *= -1; 
		b *= -1;
	}
}
void RationalNumber::reduce()
{
	if (a == 0)
	{
		b = 1;
		return;
	}
	else
	{
		//Remeber that the denominator is NEVER zero by design
		//Therefore here both numerator and denominator are non-zero.
		int m = abs(a);
		int n = abs(b);
		int gcd = m < n ? m : n;
		while (gcd > 0)
		{
			if (m % gcd == 0 && n % gcd == 0)
				break;
			gcd--;
		}
		a /= gcd;
		b /= gcd;
	}
}
//print
void RationalNumber::print() const
{
	cout << a << "/" << b;
}

//LAB WORK
bool RationalNumber::isNotEqual(const RationalNumber &r) const
{
	if (this->a * r.b != this->b * r.a)
		return true;
	return false;
}
bool RationalNumber::isGreaterThan(const RationalNumber &r) const
{
	if (this->a * r.b > this->b * r.a)
		return true;
	return false;
}
bool RationalNumber::isLessThan(const RationalNumber &r) const
{
	if (this->a * r.b < this->b * r.a)
		return true;
	return false;
}
bool RationalNumber::isGreaterOrEqual(const RationalNumber &r) const
{
	if (this->a * r.b >= this->b * r.a)
		return true;
	return false;
}
bool RationalNumber::isLessOrEqual(const RationalNumber &r) const
{
	if (this->a * r.b <= this->b * r.a)
		return true;
	return false;
}

//Assignment random rationalnumbers
void RationalNumber::assignRationalNumber()
{
	int num = rand() % (5 - -5 + 1) + -5;
	int den;
	do
	{
		den = rand() % (5 - -5 + 1) + -5;
	}while (den==0);
	
	this->setNumerator(num);
	this->setDenominator(den);
}