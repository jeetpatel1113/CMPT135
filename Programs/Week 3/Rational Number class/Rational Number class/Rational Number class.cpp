#include <iostream>
using namespace std;
class RationalNumber
{
	/*
	This class is designed to represent Rational Number objects.
	A rational number is a number of the form a/b with integers
	a and b such that b is different from 0.
	*/
private:
	int a, b;
	static int count;
public:

	//Constructors
	RationalNumber();
	RationalNumber(const int &, const int &);

	//Static member function
	static int getCount();
	//Getters
	int getNumerator() const;
	int getDenominator() const;

	//Setters
	void setNumerator(const int &num);
	void setDenominator(const int &denom);

	//Additional member functions
	double toDouble() const;
	void standardize(); 
	void reduce(); 
	void print() const;
	bool isEqual(const RationalNumber &r) const;
	bool isNotEqual(const RationalNumber &r) const;
	bool isGreaterThan(const RationalNumber &r) const;
	bool isLessThan(const RationalNumber &r) const;
	bool isGreaterOrEqual(const RationalNumber &r) const;
	bool isLessOrEqual(const RationalNumber &r) const;

	//Binary operator member functions
	RationalNumber operator+(const RationalNumber& r) const;
	RationalNumber operator+(const int& x) const;
	
	RationalNumber operator-(const RationalNumber& r) const;
	RationalNumber operator-(const int& x) const;
	
	//Friend
	friend RationalNumber operator+(const int &x, const RationalNumber &r);

	//Input and Output
	friend istream& operator>>(istream&, RationalNumber&);
	friend ostream& operator<<(ostream&, const RationalNumber&);

	//Negation of rational number
	RationalNumber operator-() const;

	//LAB WORK
	friend RationalNumber operator-(const int &, const RationalNumber &);
	RationalNumber operator*(const RationalNumber &) const;
	RationalNumber operator*(const int &) const;
	friend RationalNumber operator*(const int &, const RationalNumber &);
	RationalNumber operator/(const RationalNumber &) const;
	RationalNumber operator/(const int &) const;
	friend RationalNumber operator/(const int &, const RationalNumber &);
	RationalNumber operator+=(const RationalNumber &);
	RationalNumber operator+=(const int &);
	RationalNumber operator-=(const RationalNumber &);
	RationalNumber operator-=(const int &);
	RationalNumber operator*=(const RationalNumber &);
	RationalNumber operator*=(const int &);
	RationalNumber operator/=(const RationalNumber &);
	RationalNumber operator/=(const int &);





};
int RationalNumber::count = 0;

int main()
{
	const RationalNumber r1;
	RationalNumber r2(-5, 6), yonas;
	const RationalNumber *r3 = new RationalNumber();
	const RationalNumber *r4;
	r4 = new RationalNumber(4, -6);
	cout << "r1 = " << r1 << endl << "r2 = " << r2 << endl << "r3 = " << *r3 << endl << "r4 = " << *r4 << endl;
	if (r1.isGreaterOrEqual(*r3))
		cout << "r1 >= r3" << endl;
	else
		cout << "r1 is not >= r3" << endl;

	if (r4->isLessThan(r2))
		cout << "r2 < r4" << endl;
	else
		cout << "r2 is not < r4" << endl;

	//Binary operator
	cout << "r3 + r2 = " << *r4 + r2 << endl;
	cout << "1 - r2 = " << 1 - *r4 << endl;
	cout << "r2 * r4 = " << r2 * *r4 << endl;
	cout << "r2 * 3 = " << r2 * 3 << endl;
	cout << "3 * r2 = " << 3 * r2 << endl;
	cout << "r2 / r4 = " << r2 / *r4 << endl;
	cout << "r2 / 5 = " << r2 / 5 << endl;
	cout << " -r2 = " << -r2 << endl;
	cout << "5 / r2 = " << 5 / r2 << endl;

	r2 += *r4;
	cout << "Modified r2 += r4 = " << r2 << endl;
	r2 -= *r4;
	cout << "Modified r2 -= r4 = " << r2 << endl;
	r2 *= 5;
	cout << "Modified r2 *= 5 = " << r2 << endl;

	/*int a = 2, b = 3, c;
	c = a += 2;
	yonas = r2 += r2;
	cout << "Modified r2 by += " << r2 << endl;
*/
	//Delete objects created on the heap
	delete r3;
	delete r4;

	system("Pause");
	return 0;
	/*
	RationalNumber r1;
	cout << "Please enter a rational number: ";
	cin >> r1;
	cout << "You entered the rational number: " << r1 << endl;

	RationalNumber r2, r3, *r4;
	cout << "Please enter three rational numbers ";
	cin >> r2 >> r3;
	r4 = new RationalNumber();
	cin >> *r4;
	cout << "You entered r2 = " << r2 << ", r3 = " << r3 << ", and r4 = " << *r4 << endl;
	delete r4;
	system ("Pause");
	return 0;
	*/
	/*
	RationalNumber r1(2, 3), r2(1, 2), r3(-2, 3), r4, *r5, r6, r7, *r8, r9;
	//Add r1 and r2 and assign the result to r4
	r4 = r1 + r2;
	//Add r1 and r3 and assign the result to a heap memory pointed to by r5
	r5 = new RationalNumber();
	*r5 = r1 + r3;
	r6 = r1 - r3;
	r7 = r1 + 1;
	r8 = new RationalNumber();
	*r8 = r1 - 1;
	r9 = 5 + r1;

	//Print the rational numbers you have got
	cout << "r1 = "; r1.print(); cout << endl;
	cout << "r2 = "; r2.print(); cout << endl;
	cout << "r3 = "; r3.print(); cout << endl;
	cout << "r4 = "; r4.print(); cout << endl;
	cout << "r5 = "; r5->print(); cout << endl;
	cout << "r6 = "; r6.print(); cout << endl;
	cout << "r7 = "; r7.print(); cout << endl;
	cout << "r8 = "; r8->print(); cout << endl;
	cout << "r9 = "; r9.print(); cout << endl;

	//delet any heap memory
	delete r5;

	system("Pause");
	return 0;
	*/
	/*
	//Test constructors
	const RationalNumber r1, r2(-5, 6);
	const RationalNumber *r3 = new RationalNumber();
	const RationalNumber *r4;
	r4 = new RationalNumber(4, -6);
	*/



	/*
	if (r1.isEqual(*r3))
		cout << "r1 and r3 are equal" << endl;
	else
		cout << "r1 and r3 are not equal" << endl;

	if (r4->isEqual(r2))
		cout << "r2 and r4 are equal" << endl;
	else
		cout << "r2 and r4 are not equal" << endl;

	//Delete objects created on the heap
	delete r3;
	delete r4;

	system("Pause");
	return 0;
	*/
	
	/*
	//Test getters
	cout << "r1 numerator is " << r1.getNumerator() << endl;
	cout << "r3 denominator is " << r3->getDenominator() << endl;

	//Test setters, standardize, reduce and print member functions
	// r2.setDenominator(-10); commented because modification not allowed
	cout << "r2 is now "; r2.print(); cout << endl;
	
	//Print all the objects
	cout << "r1 = "; r1.print(); cout << endl;
	cout << "r2 = "; r2.print(); cout << endl;
	cout << "r3 = "; r3->print(); cout << endl;
	cout << "r4 = "; r4->print(); cout << endl;

	//Test toDouble member function
	cout << "In double format, r4 = " << r4->toDouble() << endl;

	//Delete objects created on the heap
	delete r3;
	delete r4;

	system("Pause");
	return 0;
	*/

	//Construct constant objects
	/*
	const RationalNumber r1(2, 3);
	const RationalNumber *r2;
	r2 = new RationalNumber;

	//Try to modify member variables
	//r2->setNumerator(-1); Commented because modification not allowed

	//Print numerators or dinominators
	cout << "r1 numerator is " << r1.getNumerator() << endl;
	cout << "r2 denominator is " << r2->getDenominator() << endl;

	//Print objects and their value on double data type
	cout << "r1 in double format is " << r1.toDouble() << endl;
	r1.print();

	delete r2;

	system ("Pause");
	return 0;
	*/
	/*
	const char x = 65;
	//int y = x;
	cout << static_cast<int>(x) << endl << endl;
	*/
	system ("Pause");
	return 0;
}



//Constructors
RationalNumber::RationalNumber()
{
	//As a default object, let us construct 0/1 rational number
	a = 0;
	b = 1;
	count++;
}
RationalNumber::RationalNumber(const int &num, const int &denom)
{
	//If the denominator parameter is 0, ignore it and use 1
	a = num;
	b = denom != 0 ? denom : 1;
	//Now that the object is created, standardize and reduce it
	standardize();
	reduce();
	count++;
}

//Getters
int RationalNumber::getNumerator() const
{
	return a;
}
int RationalNumber::getDenominator() const
{
	return b;
}

//Setters
void RationalNumber::setNumerator(const int &num)
{
	this->a = num;
	//a = num;
	//Now that numerator of an existing object is modified,
	//standardize it and reduce it
	standardize();
	reduce();
}
void RationalNumber::setDenominator(const int &den)
{
	/*
	//If the denominator parameter is 0, ignore it and use 1
	b = denom != 0 ? denom : 1;
	//Now that denominator of an existing object is modified,
	//standardize it and reduce it
	*/
	this->a = den;
	standardize();
	reduce();
}

//Additional member functions
double RationalNumber::toDouble() const 
{
	return static_cast<double>(a)/b;
}
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
void RationalNumber::print() const
{
	cout << a << "/" << b;
}

bool RationalNumber::isEqual(const RationalNumber &r) const
{
	/*
	int x = r.a;	//We could also do int x = r.getNumerator();
	int y = r.getDenominator(); //We could also do int y = r.b;
	//Now we will compare if a/b is equal to x/y
	*/
	if (this->a* r.b == this->b* r.a)
		// Compare the *this object with the r object
		return true;
	else
		return false;
}

//Binary operator member functions
RationalNumber RationalNumber::operator+(const RationalNumber &r) const
{
	int a1 = this->a;
	int b1 = this->b;
	int a2 = r.a;
	int b2 = r.b;
	//Now we would like to add (a1/b1) + (a2/b2) which is equal to (a1b2 + a2b1)/b1b2
	RationalNumber answer(a1*b2 + a2*b1, b1*b2);
	return answer;
}
RationalNumber RationalNumber::operator-(const RationalNumber &r) const
{
	int a1 = this->a;
	int b1 = this->b;
	int a2 = r.a;
	int b2 = r.b;

	RationalNumber answer(a1*b2 - a2*b1, b1*b2);
	return answer;
}
RationalNumber RationalNumber::operator+(const int &x) const
{
	RationalNumber temp(x, 1);
	return *this + temp;
}
RationalNumber RationalNumber::operator-(const int &x) const
{
	RationalNumber temp(x, 1);
	return *this - temp;
}
RationalNumber operator+(const int &x, const RationalNumber &r)
{
	RationalNumber temp(x, 1);
	return temp + r;
}


//Input and Output
istream& operator>>(istream& in, RationalNumber& r)
{
	cout << endl;
	cout << "\t Enter a numerator: ";
	in >> r.a;
	cout << "\t Enter a denominator: ";
	in >> r.b;
	while (r.b == 0)
	{
		cout << "\t Denominator can't be zero. Please enter a non-zero denominator";
		in >> r.b;
	}
	r.standardize();
	r.reduce();
	return in;
}
ostream& operator<<(ostream& out, const RationalNumber& r)
{
	out << r.a << "/" << r.b;
	return out;
}

//Negation of rational number
RationalNumber RationalNumber::operator-() const
{
	return -1 * *this;
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

RationalNumber operator-(const int& x, const RationalNumber &r)
{
	RationalNumber temp(-1 * r.a, r.b);
	return temp + x;
}
RationalNumber RationalNumber::operator*(const RationalNumber &r) const
{
	int a1 = this->a;
	int b1 = this->b;
	int a2 = r.a;
	int b2 = r.b;
	RationalNumber answer(a1*a2, b1*b2);
	return answer;
}
RationalNumber RationalNumber::operator*(const int &x) const
{
	RationalNumber temp(x, 1);
	return temp * *this;
}
RationalNumber operator*(const int& x, const RationalNumber &r)
{
	RationalNumber temp(x, 1);
	return temp * r;
}
RationalNumber RationalNumber::operator/(const RationalNumber &r) const
{
	RationalNumber temp(r.b, r.a);
	return *this*temp;
}
RationalNumber RationalNumber::operator/(const int &x) const
{
	RationalNumber temp(1, x);
	return *this * temp;
}
RationalNumber operator/(const int &x, const RationalNumber &r)
{
	RationalNumber temp(x, 1);
	return temp / r;
}
RationalNumber RationalNumber::operator+=(const RationalNumber &r)
{
	*this = *this + r;
	return *this;
}
RationalNumber RationalNumber::operator+=(const int &x)
{
	*this = *this + x;
	return *this;
}
RationalNumber RationalNumber::operator-=(const RationalNumber &r)
{
	*this = *this - r;
	return *this;
}
RationalNumber RationalNumber::operator-=(const int &x)
{
	*this = *this - x;
	return *this;
}
RationalNumber RationalNumber::operator*=(const RationalNumber &r)
{
	*this = *this * r;
	return r;
}
RationalNumber RationalNumber::operator*=(const int &x)
{
	*this = *this * x;
	return *this;
}
RationalNumber RationalNumber::operator/=(const RationalNumber &r)
{
	*this = *this * r;
	return *this;
}
RationalNumber RationalNumber::operator/=(const int &x)
{
	*this = *this * x;
	return *this;
}





