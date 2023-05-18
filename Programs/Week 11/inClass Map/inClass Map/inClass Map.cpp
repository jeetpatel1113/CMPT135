#include <iostream>
#include <string>
#include <cassert>
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

template <class K, class V>
class Map
{
private:
	SmarterArray<K> A1; //The keys of the map
	SmarterArray<V> A2; //The values of the map

public:
	//Constructor
	Map(); //Default constructor
	Map(const Map<K, V>&); //Copy constructor
	//Assignment operator
	Map<K, V>& operator = (const Map<K, V>&); //Assignment operator

	//Destructor
	~Map();
	//Getters, Setters, operators and other functions
	int getSize() const;
	int findKey(const K&) const;
	int findValue(const V&) const;
	K getKey(const V&) const;
	V getValue(const K&) const;
	K getKeyAtIndex(const int&) const;
	V getValueAtIndex(const int&) const;
	void setKeyAtIndex(const int&, const K&);
	void setValueAtIndex(const int&, const V&);
	void append(const K&, const V&);

	template <class K1, class V1>
	friend ostream& operator << (ostream&, const Map<K1, V1>&);

	//Inserting map
	void insert (const int& index, const Map<K, V>& M);
};
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
template <class K, class V>
void Map<K, V>::insert (const int& index, const Map<K, V>& M)
{
	assert(index >= 0 && index <= this->getSize());
	Map<K, V> temp;
	for (int i = 0 ; i < index ; i++)
		temp.append(this->A1[i], this->A2[i]);
	temp.append(M.A1[0], M.A2[0]);
	for (int i = index ; i < this->getSize() ; i++)
		temp.append(this->A1[i], this->A2[i]);
	this->~Map();
	*this = temp;
	temp.~Map();
}

int main()
{
	//Test default constructor
	Map<string, double> m1;
	cout << "m1 is " << m1 << endl;

	//Test append and getSize member functions 
	const int size = 5;
	string city[size] = {"Burnaby", "Surrey", "New West", "Delta", "Coquitlam"};
	double distance[size] = {10.8, 20.5, 15.4, 21.8, 18.1};
	for (int i = 0 ; i < size ; i++)
		m1.append(city[i], distance[i]);
	cout << "Now m1 is " << m1 << endl;
	cout << "m1 has " << m1.getSize() << " key-value pair elements in it." << endl;

	//Test copy constructor
	Map<string, double> m2(m1);
	cout << "m2 is " << m2 << endl;

	//Test destructor
	m1.~Map();
	cout << "Now m1 is " << m1 << endl;
	cout << "m2 is still " << m2 << endl;

	//Test assignment operator
	m1 = m2;
	cout << "Now m1 is " << m1 << endl;
	m2.~Map();
	cout << "m2 is destructed. m2 is now " << m2 << endl;

	//Test findKey, findValue, getKey, getValue, getKeyAtIndex, and getValueAtIndex member functions
	cout << "The city Delta is found in the keys array at index " << m1.findKey("Delta") << endl;
	cout << "A city whose distance from Vancouver is 18.1 is found at index " << m1.findValue(18.1) << endl;
	cout << "A city whose distance from Vancouver is 18.1 is " << m1.getKey(18.1) << endl;
	cout << "The distance of New West from Vancouer is " << m1.getValue("New West") << endl;
	cout << "The city at index 2 of the Keys array is " << m1.getKeyAtIndex(2) << endl;
	cout << "The distance at index 4 in the Values array at index " << m1.getValueAtIndex(4) << endl;

	//Test the setKeyAtIndex and setValueAtIndex member functions
	m1.setKeyAtIndex(0, "North Vancouver");
	cout << "The city at index 0 of the Keys array is " << m1.getKeyAtIndex(0) << endl;
	m1.setValueAtIndex(0, 17.7);
	cout << "The distance at index 0 in the Values array at index " << m1.getValueAtIndex(0) << endl;
	cout << "At last m1 is " << m1 << endl;

	Map<string, double> m3;
	m3.append("Toronto", 110.06);
	//Insert
	m1.insert(3, m3);
	cout << "m1 after inserting Toronto in the list, m1 become " << m1 << endl;

	system("Pause");
	return 0;
}