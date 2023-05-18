#include <iostream>
using namespace std;
class SmartArray
{
private:
	int *A;
	int size;
public:
	//Constructors
	SmartArray();
	SmartArray(const int *A, const int &size);

	//Getters, Setters, operators and other functions
	int getSize() const;
	int &operator[] (const int &index) const;
	void append(const int &e);
	friend ostream & operator << (ostream &out, const SmartArray &L);

	//Copy Constructor
	SmartArray(const SmartArray &);
	//Destructor : Declaration
	~SmartArray();
	//Extra function
	int findElement(const int &) const;
	bool remove(const int &);

};

SmartArray::SmartArray()
{
	this->size = 0;
}

SmartArray::SmartArray(const int *A, const int &size)
{
	this->size = size;
	if (this->getSize() > 0)
	{
		this->A = new int[this->getSize()];
		for (int i = 0 ; i < this->getSize() ; i++)
			this->A[i] = A[i];
	}
}
//Copy Constructor
SmartArray::SmartArray(const SmartArray &L)
{
	this->size = L.size;
	if (this->size > 0)
	{
		this->A = new int [this->size];
		for (int i = 0 ; i < L.size ; i++)
			(*this)[i] = L[i]; //this->i = L[i];
	}
}
//Destructor
SmartArray::~SmartArray()
{
	if (this->getSize() > 0)
	{
		delete[] this->A;
		this->size = 0;
	}
}


int SmartArray::getSize() const
{
	return this->size;
}

int &SmartArray::operator[](const int &index) const
{
	if (index < 0 || index >= this->getSize())
	{
		cout << "ERROR! Index out of bounds. Exiting Program..." << endl;
		abort();
	}
	return this->A[index];
}
void SmartArray::append(const int &e)
{
	int *temp = new int[this->getSize() + 1];
	for (int i = 0 ; i < this->getSize() ; i++)
		temp[i] = this->A[i];
	temp[this->getSize()] = e;
	if (this->getSize() > 0)
		delete[] this->A;
	this->A = temp;
	this->size+=1;
}

ostream &operator << (ostream &out, const SmartArray &L)
{
	out << "[";
	for (int i = 0 ; i < L.getSize() - 1 ; i++)
		out << L[i] << ", ";
	if (L.getSize() > 0)
		out << L[L.getSize() - 1];
	out << "]";
	return out;
}

//Extra elements:
int SmartArray::findElement(const int &x) const
{
	for (int i = 0 ; i < this->getSize() ; i++)
		if (this->A[i] == x)
			return i;
	return -1;
}
bool SmartArray::remove(const int &x)
{
	int index = this->findElement(x);
	if (index == -1)
		return false;
	else
	{
		int *temp = new int[this->getSize() - 1];
		for (int i = 0 ; i < index ; i++)
			temp[i] = this->A[i];
		for (int i = index + 1 ; i < this->size ; i++)
			temp[i] = this->A[i];
		cout << this->getSize() - 1 << endl;
		temp[this->getSize() - 2] = this->A[this->getSize() - 1];
		if (this->getSize() - 1 > 0)
		{
			cout << "THIS->A is getting deleted." << endl;
			delete[] this->A;
		}
		this->A = temp;
		this->size -= 1;
		return true;
	}
}



int main()
{
	
	SmartArray L1;
	cout << "Default SmartArray: " << L1 << endl;

	int x[] = {7, 2, 5};
	SmartArray L2(x, 3);
	cout << "Non-Default SmartArray: " << L2 << endl;

	cout << "Printing the SmartArray L2 elements: ";
	for (int i = 0 ; i < L2.getSize() ; i++)
		cout << L2[i] << " ";
	cout << endl;

	//Test Index out of bound case
	//cout << "The element of L1 at index 0 is " << L1[0] << endl;

	//Test modification of element with operator[]
	L2[0] = -5;
	cout << "After modifying L2, it is now " << L2 << endl;

	L1.append(54);
	cout << "After appending one element to it, L1 is now " << L1 << endl;

	SmartArray L3 = L2; //SmartArray	L3(L2) both are the same
	cout << "L3 which is a copy of L2 is " << L3 << endl;

	L3[1] = 33;
	cout << "After modifying an element of L3, now L3 is " << L3 << endl;
	cout << "Interestingly L2 is also modified and is " << L2 << endl;

	
	cout << "After deleting it, L2 is " << L2 << endl;
	cout << "Interestingly L3 is still " << L3 << endl;
	
	cout << endl;
	int num1;
	cout << "Please enter the element you want to remove : " << endl;
	cin >> num1;
	L3.remove(num1);
	cout << "Removing: " << L3 << endl;


	/*SmartArray *x;
	x = new SmartArray();
	for (int i = 0; i < 5; i++)
		x->append(i+6);
	for (int i = 0; i < x->getSize(); i++)
		cout << "Element at index " << i << " is " << (*x)[i] << endl;
	delete x;
	*/
	system ("Pause");
	return 0;
}