#include <iostream>
#include <cassert>
#include <string>
#include <ctime>
using namespace std;

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
int main()
{
	//srand(time(0));
	cout << "Testing constructors, appending, and output streaming operator" << endl;
	//Declare several SmarterArray objects
	SmarterArray<int> A1; //Default SmarterArray of integers
	double x[3] = {2.4, 1.2, 5.8};
	SmarterArray<double> A2(x, 3); //Non-default SmarterArray of doubles
	SmarterArray<string> A3; //Default SmarterArray of strings

	//Populate the SmarterArray objects
	
	for (int i = 0 ; i < 10 ; i++)
	{
		if (rand() % 2 == 0)
			A1.append(rand() % 5);
		else
		{
			int random = rand() % 5;
			A3.append(random == 0 ? "Paul" :
				(random == 1 ? "Jannet" :
				(random == 2 ? "Kevin" :
				(random == 3 ? "Sara" : "CMPT"))));
		}
	}

	//Print the objects
	cout << "The SmarterArray object A1 is " << A1 << endl;
	cout << "The SmarterArray object A2 is " << A2 << endl;
	cout << "The SmarterArray object A3 is " << A3 << endl;

	//Test getSize, indexing operator, and searching for elements
	cout << "Testing getSize, indexing operator, and searching for elements..." << endl;
	cout << "A1 has " << A1.getSize() << " elements" << endl;
	int index = A2.findElement(-2.1);
	if (index == -1)
		cout << "-2.1 is not found in " << A2 << endl;
	else
		cout << "-2.1 is found in " << A2 << " at index " << index << endl;
	A2[1] = -2.1;
	cout << "A2 is now modified to " << A2 << endl;
	cout << "-2.1 is now found in " << A2 << " at index " << A2.findElement(-2.1) << endl;
	cout << endl;

	//Test copy constructor, assignment operator, and destructor
	cout << "Testing copy constructor, assignment operator, and destructor..." << endl;
	SmarterArray<string> A4(A3);
	A3.~SmarterArray();
	SmarterArray<double> A5;
	A5 = A2;
	A2.~SmarterArray();
	cout << "The SmarterArray object A1 is now " << A1 << endl;
	cout << "The SmarterArray object A2 is now " << A2 << endl;
	cout << "The SmarterArray object A3 is now " << A3 << endl;
	cout << "The SmarterArray object A4 is now " << A4 << endl;
	cout << "The SmarterArray object A5 is now " << A5 << endl;
	cout << endl;

	//Test erase element
	A1.erase(0);
	A1.erase(A1.getSize() - 1);
	cout << "After erasing its first and last elements, A1 is now " << A1 << endl;

	//Insert 4.7 at 3
	A5.insert(3, 4.7);
	cout << "The SmarterArray object A5 is now " << A5 << endl;

	system ("Pause");
	return 0;
}