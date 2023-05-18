#include <iostream>
#include <cassert>
#include <string>
#include <ctime>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SmarterArray
{
private:
	T *A;
	int size;
public:
	//Constructors
	SmarterArray();
	SmarterArray(const T*, const int &);
	SmarterArray(const SmarterArray<T> &); //Copy Constructor

	//Assignment operator
	SmarterArray<T>& operator = (const SmarterArray<T> &);

	//Destructor
	~SmarterArray(); // perform memory clean up

	//Getters, Setters, operator and other functions
	int getSize() const; // return the number of elements
	T& operator[](const int &) const; // return element of search value
	int findElement(const T&) const; // return index of search value
	void append(const T &); //insert at the end
	bool erase(const int &); // erase element at index

	//Friend functions
	template <class T1> //Some compilers require a different template name
	friend ostream& operator << (ostream &, const SmarterArray<T1> &);

	void insert (const int&, const T&);
};
template <class T>
SmarterArray<T>::SmarterArray()
{
	this->size = 0;
}
template <class T>
SmarterArray<T>::SmarterArray(const T *A, const int &size)
{
	assert(size >= 0);
	this->size = size;
	if (this->size > 0)
	{
		this->A = new T[this->size];
		for (int i = 0 ; i < this->size ; i++)
			this->A[i] = A[i];
	}
}
template <class T>
SmarterArray<T>::SmarterArray(const SmarterArray<T> &L)
{
	this->size = L.size;
	if (this->size > 0)
	{
		this->A = new T[this->size];
		for (int i = 0 ; i < this->size ; i++)
			this->A[i] = L[i];
	}
}
template <class T>
SmarterArray<T>& SmarterArray<T>::operator = (const SmarterArray<T> &L)
{
	//Check for self assignment. If so, do nothing.
	if (this == &L)
		return *this;
	//Delete the left hand side object's memory
	this->~SmarterArray();
	//Now copy the right hand side to the left
	this->size = L.size;
	if (this->size > 0)
	{
		this->A = new T[this->size];
		for (int i = 0 ; i < this->size ; i++)
			this->A[i] = L[i];
	}
	return *this;
}
template <class T>
SmarterArray<T>::~SmarterArray()
{
	if (this->size > 0)
	{
		delete[] this->A;
		this->size = 0;
	}
}
template <class T>
int SmarterArray<T>::getSize() const
{
	return this->size;
}
template <class T>
T& SmarterArray<T>::operator[](const int &index) const
{
	assert(index >= 0 && index < this->size);
	return this->A[index];
}
template <class T>
int SmarterArray<T>::findElement(const T &value) const
{
	for (int i = 0 ; i < this->size ; i++)
		if (this->A[i] == value)
			return i;
	return -1;
}
template <class T>
void SmarterArray<T>::append(const T &value)
{
	//First create a temoporary array whose size is this->size + 1
	int new_size = this->size + 1;
	T *temp = new T[new_size];

	//Copy the elements of this->A to temp
	for (int i = 0 ; i < this->size ; i++)
		temp[i] = this->A[i];
	
	//Copy the element to be appended to temp
	temp[this->size] = value;

	//Make the array this->A to point to temp and adjust the size
	this->A = temp;
	this->size = new_size;
}
template <class T>
bool SmarterArray<T>::erase(const int &index)
{
	if (index < 0 || index >= this->size)
		return false;
	else if (this->size == 1) //only one element in the *this object
		this->~SmarterArray();
	else
	{
		//First create a temporary array whose size is this->size - 1
		int new_size = this->size -1;
		T *temp = new T[new_size];
		//Copy the elements of this->A to temp except the element at index
		for (int i = 0 ; i < index ; i++)
			temp[i] = this->A[i];
		for (int i = index + 1 ; i < this->size ; i++)
			temp[i - 1] = this->A[i];
		//Destruct the object
		this->~SmarterArray();
		//Make the array this->A to point to temp and adjust the size
		this->A = temp;
		this->size = new_size;
	}
	return true;
}
template <class T1>
ostream& operator << (ostream &out, const SmarterArray<T1> &L)
{
	out << "[";
	for (int i = 0 ; i < L.size - 1 ; i++)
		out << L[i] << ", ";
	if (L.size > 0)
		out << L[L.size - 1];
	out << "]";
	return out;
}
template <class T>
void SmarterArray<T>::insert (const int& index, const T& x)
{
	assert(index >= 0 && index <= size);
	if(index == size)
		this->append(x);
	SmarterArray<T> temp;
	for (int i = 0 ; i < index ; i++)
		temp.append(this->A[i]);
	temp.append(x);
	for (int i = index + 1 ; i < this->size ; i++)
		temp.append(this->A[i]);
	*this = temp;
	temp.~SmarterArray();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int getBitPatternLength(const int& size)
{
	int bit_pattern_length;
	cout << "Enter the required bit pattern length between 1 and " << size << ": ";
	cin >> bit_pattern_length;
	while (bit_pattern_length < 1 || bit_pattern_length > size)
	{
		cout << "You must enter between 1 and " << size << ". Enter again please: ";
		cin >> bit_pattern_length;
	}
	return bit_pattern_length;
}
template <class T>
void printArray(const SmarterArray<T>& arr, const int bit_pattern_length)
{
	for (int i = 0; i < bit_pattern_length; i++)
		cout << arr[i];
}
int selectComputation()
{
	cout << "Select your computation" << endl;
	cout << "   1. Unsigned Binary Representation Computation" << endl;
	cout << "   2. Sign and Magnitude Representation Computation" << endl;
	cout << "   3. Two's Complement Representation Computation" << endl;
	cout << "   4. Exit Program" << endl;
	int selection;
	cout << "Enter your selection (1, 2, 3, or 4): ";
	cin >> selection;
	while (selection != 1 && selection != 2 && selection != 3 && selection != 4)
	{
		cout << "Please enter a correct choice: ";
		cin >> selection;
	}
	return selection;
}
template <class T>
void rotateArray(SmarterArray<T>& A, const int& size)
{
	//Pre-condition: Takes Array and size
	//Post-condition: reverse it completely.
	for (int i = 0 ; i < size / 2 ; i++)
	{
		for (int j = size - i - 1 ; j >= 0 ; j--)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			break;
		}
	}
	return;
}

void flipBinary(int A[], const int size)
{
	for (int i=0 ; i<size ; i++)
	{
		if (A[i]==0)
			A[i]=1;
		else if (A[i]==1)
			A[i]=0;
	}
	rotateArray(A,size);
	for (int i=0 ; i<size ; i++)
	{
		int carry=0;
		if (A[i]==1)
		{
			A[i]=0;
			carry=1;
		}
		else if (A[i]==0)
		{
			A[i]=1;
			carry=0;
			break;
		}
		if (carry==1)
			continue;
	}
	rotateArray(A, size);
	return;
}
// functions to write
void computeUnsignedBinary(int A[], const int bit_pattern_length, const int num)
{
	int n=abs(num);
	for (int i=0 ; i<bit_pattern_length ; i++)
	{
		A[i]=n%2;
		n=n/2;
	}
	rotateArray(A, bit_pattern_length);
	return;
}
void computeSignAndMagnitudeBinary(int A[], const int bit_pattern_length, const int num)
{
	int n=abs(num);
	for (int i=0 ; i<bit_pattern_length ; i++)
	{
		A[i]=n%2;
		n=n/2;
	}
	if (num<0)
		A[bit_pattern_length-1]=1;
	else if (num>0)
		A[bit_pattern_length-1]=0;
	rotateArray(A, bit_pattern_length);
	return;
}
void computeTwosComplementBinary(int A1[], const int bit_pattern_length, const int num1)
{
	/*
	char c=static_cast<char>(num1);
	int n=static_cast<int>(c);
	*/
	computeUnsignedBinary(A1, bit_pattern_length, num1);
	if (num1<0)
	{
		flipBinary(A1, bit_pattern_length);
	}
	return;
}
void binaryAddition( int A1[], int A2[], const int bit_pattern_length, int A3[])
{
	rotateArray(A1, bit_pattern_length);
	rotateArray(A2, bit_pattern_length);
	int carry=0;
	for (int i=0 ; i<bit_pattern_length ; i++)
	{
		if(carry==0)
			A3[i]= A1[i]+A2[i];
		else
		{
			A3[i]= A1[i]+A2[i]+1;
			carry=0;
		}
		if (A3[i]>1)
		{
			A3[i]=A3[i]-2;
			carry=1;
		}
	}
	rotateArray(A3, bit_pattern_length);
	rotateArray(A1, bit_pattern_length);
	rotateArray(A2, bit_pattern_length);
	return;
}
int twosComplementBinaryToDecimal(int A3[], const int bit_pattern_length)
{
	int n=0;
	if (A3[0]==1)
	{
		flipBinary(A3, bit_pattern_length);
		rotateArray(A3, bit_pattern_length);
		for (int i=0 ; i<bit_pattern_length ; i++)
			if (A3[i]==1)
				n+=static_cast<int>(pow(2.0,i));
		n=n*-1;
	}
	else if (A3[0]==0)
	{
		rotateArray(A3, bit_pattern_length);
		for (int i=0 ; i<bit_pattern_length ; i++)
			if (A3[i]==1)
				n+=static_cast<int>(pow(2.0,i));
	}
	return n;
}


