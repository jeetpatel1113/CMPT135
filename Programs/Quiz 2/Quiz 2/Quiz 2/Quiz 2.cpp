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
	SmarterArray(const T *, const int &);
	SmarterArray(const SmarterArray<T> &); //Copy constructor

	//Assignment operator
	SmarterArray<T>& operator = (const SmarterArray<T> &);

	//Destructor
	~SmarterArray(); //perform memory clean up

	//Getters, Setters, operators and other functions
	int getSize() const; //return the number of elements
	T& operator[](const int &) const; //return element at index
	int findElement(const T &) const; //return index of search value
	void append(const T &); //insert at the end
	bool erase(const int &); //erase element at index

	//Friend functions
	template<class T1> //Some compilers require a different template name
	friend ostream& operator << (ostream &, const SmarterArray<T1> &);
};

template <class K, class V>
class Map
{
private:
	SmarterArray<K> A1;    //The keys of the map
	SmarterArray<V> A2;    //The values of the map

public:
	//Constructors
	Map(); //Default constructor
	Map(const Map<K, V> &); //Copy constructor. Deep copy.
	//Assignment operator
	Map<K, V>& operator = (const Map<K, V> &); //Assignment operator. Memory clean up and deep copy.
	//Destructor
	~Map(); //Destructor.
	//Getters, Setters, operators and other functions
	int getSize() const; //Return the size of the map
	int findKey(const K &) const; //Return the index of the first element of the Keys array == the argument. Return -1 if not found.
	int findValue(const V &) const; //Return the index of the first element of the Values array == the argument. Return -1 if not found.
	K getKey(const V &) const; //Assert the argument is found in the Values array and then return the first key with the given value
	V getValue(const K &) const; //Assert the argument is found in the Keys array and then return the first value with the given key
	K getKeyAtIndex(const int &) const; //Assert the index argument and then return the key at the given index
	V getValueAtIndex(const int &) const; //Assert the index argument and then return the value at the given index
	void setKeyAtIndex(const int &, const K &); //Assert the index argument and then set the key at the given index
	void setValueAtIndex(const int &, const V &); //Assert the index argument and then set the value at the given index
	void append(const K &, const V &); //Append the key-value pair to the calling object

	template <class K1, class V1>
	friend ostream& operator << (ostream &, const Map<K1, V1> &); //Output streaming operator
};

//QUIZ QUESTION
SmarterArray<int> getFactors(const int key)
{
	SmarterArray<int> temp;
	for (int i = 1 ; i <= key ; i++)
	{
		if (key % i == 0)
		{
			temp.append(i);
		}
	}
	return temp;
}

int getMaxSizeValuesKey(const Map<int, SmarterArray<int>>& M)
{
	for (int i = 0 ; i < M.getSize() ; i++)
	{
		cout << i << endl;
	}
	return max;
}
int main()
{
	//Let us seed the random number generator to a fixed integer so that we all get the same output in Visual Studio
	srand(time(0));
	
	//Create a SmarterArray and populate it with positive integers
	SmarterArray<int> N;
	const int size = rand() % 10 + 10;
	for (int i = 0; i < size; i++)
		N.append(rand() % 100 + 1);
	cout << "The SmarterArray is " << N << endl;
	
	//Create a mapping from the elements of the SmarterArray to their factors
	Map<int, SmarterArray<int>> M;
	for (int i = 0; i < N.getSize(); i++)
	{
		int key = N[i];
		SmarterArray<int> factors = getFactors(key);
		M.append(key, factors);
	}
	
	cout << "The map created is " << M << endl;
	cout << "The key in the map with maximum number of values is " << getMaxSizeValuesKey(M) << endl;
	system("Pause");
	return 0;
}
/*
Sample Run Output
The SmarterArray is [48, 75, 97, 28, 48, 69, 96, 77, 23, 62]
The map created is
Keys             Values
====             ======
48              [1, 2, 3, 4, 6, 8, 12, 16, 24, 48]
75              [1, 3, 5, 15, 25, 75]
97              [1, 97]
28              [1, 2, 4, 7, 14, 28]
48              [1, 2, 3, 4, 6, 8, 12, 16, 24, 48]
69              [1, 3, 23, 69]
96              [1, 2, 3, 4, 6, 8, 12, 16, 24, 32, 48, 96]
77              [1, 7, 11, 77]
23              [1, 23]
62              [1, 2, 31, 62]

The key in the map with maximum number of values is 96
Press any key to continue . . .
*/

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
template <class K, class V>
Map<K, V>::Map()
{
	//No Code
}
template <class K, class V>
Map<K, V>::Map(const Map<K, V>& M)
{
	A1 = M.A1;
	A2 = M.A2;
}
template <class K, class V>
Map<K, V>& Map<K, V>::operator = (const Map<K, V>& M)
{
	A1 = M.A1;
	A2 = M.A2;
	return *this;
}
template <class K, class V>
Map<K, V>::~Map()
{
	A1.~SmarterArray();
	A2.~SmarterArray();
}
template <class K, class V>
int Map<K, V>::getSize() const
{
	return A1.getSize();
}
template <class K, class V>
int Map<K, V>::findKey(const K& key) const
{
	return A1.findElement(key);
}
template <class K, class V>
int Map<K, V>::findValue(const V& value) const
{
	return A2.findElement(value);
}
template <class K, class V>
K Map<K, V>::getKey(const V& value) const
{
	int index = A2.findElement(value);
	assert(index != -1);
	return A1[index];
}
template <class K, class V>
V Map<K, V>::getValue(const K& key) const
{
	int index = A1.findElement(key);
	assert(index != -1);
	return A2[index];
}
template <class K, class V>
K Map<K, V>::getKeyAtIndex(const int& index) const
{
	assert(index >= 0 && index < A1.getSize());
	return A1[index];
}
template <class K, class V>
V Map<K, V>::getValueAtIndex(const int& index) const
{
	assert(index >= 0 && index < A2.getSize());
	return A2[index];
}
template <class K, class V>
void Map<K, V>::setKeyAtIndex(const int& index, const K& key)
{
	assert(index >= 0 && index < A1.getSize());
	A1[index] = key;
}
template <class K, class V>
void Map<K, V>::setValueAtIndex(const int& index, const V& value)
{
	assert(index >= 0 && index < A2.getSize());
	A2[index] = value;
}
template <class K, class V>
void Map<K, V>::append(const K& key, const V& value)
{
	A1.append(key);
	A2.append(value);
}
template <class K1, class V1>
ostream& operator << (ostream& out, const Map<K1, V1>& m)
{
	if (m.getSize() == 0)
		out << "[Empty Map]" << endl;
	else
	{
		out << endl;
		out << "Keys \t\t Values" << endl;
		out << "==== \t\t ======" << endl;
		for (int i = 0 ; i < m.getSize() ; i++)
			out << m.A1[i] << "\t\t" << m.A2[i] << endl;
	}
	return out;
}
