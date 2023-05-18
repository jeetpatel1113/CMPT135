#include <iostream>
using namespace std;

class SmartArray
{
private:
	int *A;
	int size;
public:
	//Constructor
	SmartArray();
	SmartArray(int *, const int&);
	//Copy Constructor
	SmartArray(const SmartArray &);

	//Distructor
	~SmartArray();
	//Getters size
	int getSize() const;

	//int& operator[](const int &);
	int& operator[](const int &) const;

	//Append
	void append(const int &);
	
	//Cout statement
	friend ostream& operator << (ostream&, const SmartArray &);
	
	//= operator
	SmartArray& operator = (const SmartArray &);

	//LAB WORK
	int findElement(const int &) const;
	bool remove(const int &);
	void removeAll(const int &);
	SmartArray operator + (const SmartArray &) const;
	bool operator == (const SmartArray &) const;
	bool operator != (const SmartArray &) const;
	SmartArray& operator ++ ();
	SmartArray& operator -- ();
	SmartArray operator ++ (int DUMMY);
	SmartArray operator -- (int DUMMY);
	SmartArray& operator - ();
	SmartArray operator - (const SmartArray &);
	bool isPrime(const int &) const;

};

int main()
{
	/*
	SmartArray L1, L2;
	for (int i = 0 ; i < 10 ; i++)
	{
		L1.append(rand()%(25 - 10 + 1) + 10);
		L2.append(rand()%(100 - 0 + 1) + 0);
	}
	cout << "The elements in L1 are : " << endl << L1 << endl;
	cout << "The elements in L2 are : " << endl << L2 << endl;
	
	SmartArray L3;
	L3 = L1 + L2;
	cout << "The elements in L3 are : " << endl << L3 << endl;
	SmartArray L4 = L2;
	cout << "The elements in L4 are : " << endl << L4 << endl;
	
	cout << "Pre - Increment L1 = " << ++L1 << endl;
	cout << "Pre - Decrement L2 = " << --L2 << endl;
	L3++;
	cout << "Post - Increment L3 = " << L3 << endl;
	L4--;
	cout << "Post - Decrement L4 = " << L4 << endl;
	cout << "Multiply -1 * L2 = " << -L2 << endl;
	cout << "L3 - L4 = " << L3 - L4 << endl;
	*/

	SmartArray L5;
	int n = rand() % (25 - 10 + 1) + 10;
	for (int i = 0 ; i < n ; i++)
	{
		L5.append(rand()%(25 - 5 + 1) + 5);
	}
	cout << "Elements in L5 are : " << endl << L5 << endl;
	/*
	int min = L5[0];
	int max = L5[0];
	for (int i = 0 ; i < L5.getSize() ; i++)
	{
		if (L5[i] < min)
			min = L5[i];
		if (L5[i] > max)
			max = L5[i];
	}
	cout << "Maximum from L5 is : " << max << endl;
	cout << "Minimum from L5 is : " << min << endl;
	*/
	
	cout << "The prime numbers among L5 are : " << endl;
	for (int i = 0 ; i < L5.getSize() ; i++)
		if (isPrime(static_cast<int>(L5[i])))
			cout << L5[i] << "  ";
	cout << endl;
	system ("Pause");
	return 0;
}

//Constructors
SmartArray::SmartArray()
{
	this->size = 0;
}
SmartArray::SmartArray(int *A, const int& size)
{
	this->size = size;
	if (size > 0)
	{
		this->A = new int [size];
		for (int i = 0 ; i < size ; i++)
			this->A[i] = A[i];
	}
}
SmartArray::SmartArray(const SmartArray &s)
{
	this->size = s.size;
	if (this->size > 0)
	{
		this->A = new int [this->size];
		for (int i = 0 ; i < this->size ; i++)
			this->A[i] = s.A[i];
	}
}
//Distructor
SmartArray::~SmartArray()
{
	if (this->size > 0)
	{
		delete[] this->A;
		this->size = 0;
	}
}
//Cout
ostream& operator << (ostream& out, const SmartArray &s)
{
	out << '[';
	for (int i = 0 ; i < s.getSize() - 1 ; i++)
		out << s.A[i] << ", ";
	if (s.getSize() > 0)
		out << s.A[s.getSize() - 1];
	out << ']';
	return out;
}
//get Size
int SmartArray::getSize() const
{
	return this->size;
}
//append()
void SmartArray::append(const int &num)
{
	int *temp = new int[this->getSize() + 1];
	for (int i = 0 ; i < size ; i++)
		temp[i] = A[i];
	temp[size] = num;
	if (this->size > 0)
		delete[] this->A;
	
	this->A = temp;
	this->size+=1;
}
//Operator []
int& SmartArray::operator[](const int &index) const
{
	if (index >= size || index < 0)
	{
		cout << "ERROR! Index out of bounds. Exiting Program..." << endl;
		abort();
	}
	return this->A[index];
}
//Operator =
SmartArray& SmartArray::operator = (const SmartArray &L)
{
	if (this == &L)
		return *this;
	this->~SmartArray();
	this->size = L.getSize();
	if (this->size > 0)
	{
		this->A = new int[L.getSize()];
		for (int i = 0 ; i < this->size ; i++)
			this->A[i] = L[i];
	}
	return *this;
}
//LAB WORK
int SmartArray::findElement(const int &x) const
{
	for (int i = 0 ; i < this->getSize() ; i++)
		if (this->A[i] == x)
			return i;
	return -1;
}
bool SmartArray::remove(const int &x)
{
	int index = findElement(x);
	if (index == -1)
		return false;
	SmartArray temp;
	for (int i = 0 ; i < index ; i++)
		temp.append(this->A[i]);
	for (int i = index + 1 ; i < size ; i++)
		temp.append(this->A[i]);
	this->~SmartArray();
	*this = temp;
	return true;
}
void SmartArray::removeAll(const int &x)
{
	int index = findElement(x);
	while (index != -1)
	{
		remove(x);
		index = findElement(x);
	}
}
SmartArray SmartArray::operator+(const SmartArray &L) const
{
	SmartArray temp = *this;
	for (int i = 0 ; i < L.size ; i++)
		temp.append(L[i]);
	return temp;
}
bool SmartArray::operator==(const SmartArray &L) const
{
	if (this->size != L.size)
		return false;
	for (int i = 0 ; i < this->size ; i++)
		if (this->A[i] != L[i])
			return false;
	return true;
}
bool SmartArray::operator!=(const SmartArray &L) const
{
	return !(*this==L);
}
SmartArray& SmartArray::operator ++ ()
{
	for (int i = 0 ; i < size ; i++)
		this->A[i]++;
	return *this;
}
SmartArray& SmartArray::operator -- ()
{
	for (int i = 0 ; i < size ; i++)
		this->A[i]--;
	return *this;
}
SmartArray SmartArray::operator ++ (int DUMMY)
{
	SmartArray temp = *this;
	*this = ++(*this);
	return temp;
}
SmartArray SmartArray::operator -- (int DUMMY)
{
	SmartArray temp = *this;
	*this = -- (*this);
	return temp;
}
SmartArray& SmartArray::operator - ()
{
	for (int i = 0 ; i < size ; i++)
		this->A[i] = -1 * this->A[i];
	return *this;
}
SmartArray SmartArray::operator - (const SmartArray &L)
{
	SmartArray temp;
	for (int i = 0 ; i < this->getSize() ; i++)
		if (L.findElement(this->A[i]) == -1)
			temp.append(A[i]);
	for (int i = 0 ; i < L.getSize() ; i++)
		if (this->findElement(L[i]) == -1)
			temp.append(L[i]);
	return temp;
}


bool SmartArray::isPrime(const int &x) const
{
	for (int i = 2 ; i < x ; i++)
		if (x % i == 0)
			return false;
	return true;
}
bool isPrime(int x)
{
	for (int i = 2 ; i < x ; i++)
		if (x % i == 0)
			return false;
	return true;
}