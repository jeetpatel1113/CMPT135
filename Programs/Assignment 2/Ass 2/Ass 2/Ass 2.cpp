#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;
class Node
{
	typedef Node* NodePtr;
private:
	int data;
	NodePtr link;
public:
	Node();
	Node(const int &);
	Node(const Node &);
	int getData() const;
	NodePtr getLink() const;
	void setData(const int &);
	void setLink(const NodePtr &);
	friend ostream& operator << (ostream &, const Node &);
};
typedef Node* NodePtr;
Node::Node() : data(0), link(nullptr) {}
Node::Node(const int &d) : data(d), link(nullptr){}
Node::Node(const Node &n) : data(n.data), link(n.link){}
int Node::getData() const { return data; }
NodePtr Node::getLink() const { return link; }
void Node::setData(const int &d) { data = d; }
void Node::setLink(const NodePtr &p) { link = p; }
ostream& operator << (ostream& out, const Node& n)
{
	out << n.data;
	return out;
}
typedef Node* NodePtr;
class LinkedList
{
private:
	NodePtr head;
public:
	LinkedList(); //default constructor: assigns the head pointer member variable a nullptr value
	LinkedList(const LinkedList &); //copy constructor (deep copy)
	~LinkedList(); //destructor (must delete all the nodes from the heap)
	LinkedList& operator= (const LinkedList &); //Assignment operator (deep copy)
	bool isEmpty() const; //return true if the length of the calling object is 0 and false otherwise
	NodePtr getHeadPtr() const; //return the head member variable of the calling object
	int getLength() const; //return the number of nodes in the calling object
	void head_insert(const int &); //as described in the supplementary material
	NodePtr search_node(const int &) const; //as described in the supplementary material
	void insert_after(const NodePtr &, const int &) const; //as described in the supplementary material
	void remove_node(const NodePtr &); //as described in the supplementary material
	void remove_node(const int &); //as described in the supplementary material
	void remove_all(const int &); //as described in the supplementary material
	void tail_insert(const int &); //as described in the supplementary material
	void insert_before(const NodePtr &, const int &); //as described in the supplementary material
	friend ostream& operator << (ostream&, const LinkedList &); //Implemented for you
};
LinkedList::LinkedList()
{
	head = nullptr;
}//default constructor: assigns the head pointer member variable a nullptr value
LinkedList::LinkedList(const LinkedList &L)
{
	head = nullptr;
	NodePtr temp = L.head;
	LinkedList S;
	while (temp != nullptr)
	{
		S.head_insert(temp->getData());
		temp = temp->getLink();
	}
	temp = S.head;
	while (temp != nullptr)
	{
		this->head_insert(temp->getData());
		temp = temp->getLink();
	}
}//copy constructor (deep copy)
LinkedList::~LinkedList()
{
	NodePtr temp;
	while (head != nullptr)
	{
		temp = head;
		head = head->getLink();
		delete temp;
	}
}//destructor (must delete all the nodes from the heap)
LinkedList& LinkedList::operator= (const LinkedList &L)
{
	this->~LinkedList();
	head = nullptr;
	NodePtr temp = L.head;
	LinkedList S;
	while (temp != nullptr)
	{
		S.head_insert(temp->getData());
		temp = temp->getLink();
	}
	temp = S.head;
	while (temp != nullptr)
	{
		this->head_insert(temp->getData());
		temp = temp->getLink();
	}
	return *this;
}//Assignment operator (deep copy)
bool LinkedList::isEmpty() const
{
	if (head == nullptr)
		return true;
	else
		return false;
}//return true if the length of the calling object is 0 and false otherwise
NodePtr LinkedList::getHeadPtr() const
{
	return head;
}//return the head member variable of the calling object
int LinkedList::getLength() const
{
	NodePtr temp = head;
	int size = 0;
	while (temp != nullptr)
	{
		temp = temp->getLink();
		size++;
	}
	return size;
}//return the number of nodes in the calling object
void LinkedList::head_insert(const int &num)
{
	NodePtr	n = new Node(num);
	n->setLink(head);
	head = n;
} //as described in the supplementary material
NodePtr LinkedList::search_node(const int &num) const
{
	NodePtr temp = head;
	while(temp != nullptr)
	{
		if (temp->getData() == num)
			return temp;
		else
			temp = temp->getLink();
	}
	return nullptr;
}//as described in the supplementary material
void LinkedList::insert_after(const NodePtr &n, const int &num) const
{
	if (n == nullptr)
		return;
	else
	{
		NodePtr temp = new Node(num);
		temp->setLink(n->getLink());
		n->setLink(temp);
	}
}//as described in the supplementary material
void LinkedList::remove_node(const NodePtr &n)
{
	if (head == nullptr || n == nullptr)
		return;
	else if (head == n)
	{
		head = head->getLink();
		delete n;
		return;
	}
	else
	{
		NodePtr b = head;
		while (b != nullptr)
		{
			if (b->getLink() == n)
			{
				b->setLink(n->getLink());
				delete n;
				return;
			}
			b = b->getLink();
		}
	}
}//as described in the supplementary material
void LinkedList::remove_node(const int &value)
{
	NodePtr n = search_node(value);
	remove_node(n);
}//as described in the supplementary material
void LinkedList::remove_all(const int &value)
{
	NodePtr n;
	do
	{
		n = search_node(value);
		remove_node(n);
	}while (n != nullptr);
}//as described in the supplementary material
void LinkedList::tail_insert(const int &value)
{
	if (head == nullptr)
		head_insert(value);
	else
	{
		NodePtr b = this->head;
		while(b->getLink() != nullptr)
			b = b->getLink();
		insert_after(b, value);
	}

} //as described in the supplementary material
void LinkedList::insert_before(const NodePtr &n, const int &value)
{
	//If the linked list is empty then insert only if n is nullptr too
	NodePtr head = this->getHeadPtr();
	if (head == nullptr)
	{
		if (n == nullptr)
			head_insert(value);
		else
			cout << "Insertion failed. Bad node argument." << endl;
		return;
	}
	//If n is nullptr then tail_insert
	if (n == nullptr)
	{
		tail_insert(value);
		return;
	}
	//If head is equal to n then head_insert
	if (head == n)
	{
		head_insert(value);
		return;
	}
	//Find the node just before n and insert after it
	NodePtr b = head;
	while (b != nullptr)
	{
		if (b->getLink() == n)
			break;
		b = b->getLink();
	}
	if (b == nullptr)
		cout << "Insertion failed. Bad node argument." << endl;
	else
		insert_after(b, value);

}//as described in the supplementary material
ostream& operator << (ostream &out, const LinkedList &LL)
{
	if (LL.isEmpty())
		out << "EMPTY LINKED LIST";
	else
	{
		NodePtr temp = LL.head;
		while(temp != nullptr)
		{
			out << *temp << " ";
			temp = temp->getLink();
		}
	}
	return out;
}

/////////////////////////////////////////////////////////////////////////////

LinkedList computeUnsignedBinary(const int &num, const int &bit_pattern_size)
{
	/*
	This function first asserts that num is a non-negative integer and then computes and stores the unsigned binary representation of num in bit_pattern_size bits in a linked list object in such a way that the head node stores the most significant bit while the tail node stores the least significant bit. The function then returns the linked list object.
	*/

	assert(num >= 0);

	//Put your remaining code here
	LinkedList L;
	int *A = new int [bit_pattern_size];
	int n = abs(num);
	for (int i = 0 ; i < bit_pattern_size ; i++)
	{
		A[i] = n % 2;
		n = n/2;
	}
	for (int i = 0 ; i < bit_pattern_size ; i++)
	{
		L.head_insert(A[i]);
	}
	//rotateArray(A, bit_pattern_length);
	delete[] A;
	return L;
}
LinkedList computeSignAndMagnitudeBinary(const int &num, const int &bit_pattern_size)
{
	/*
	This function computes and stores the sign and magnitude binary representation of num in bit_pattern_size bits in a linked list object in such a way that the head node stores the most significant bit while the tail node stores the least significant bit. The function then returns then linked list object.
	*/

	//Put your code here
	int *A = new int[bit_pattern_size];
	int n = abs(num);
	LinkedList L;
	for (int i = 0 ; i < bit_pattern_size ; i++)
	{
		A[i] = n % 2;
		n = n / 2;
	}
	if (num < 0)
		A[bit_pattern_size - 1] = 1;
	else if (num > 0)
		A[bit_pattern_size - 1] = 0;
	for (int i = 0 ; i < bit_pattern_size ; i++)
		L.head_insert(A[i]);
	delete[] A;
	return L;
}
void flipBits(LinkedList &LL)
{
	/*
	This function flips the bits stored in the nodes of the linked list object parameter LL. Assume the data in each node of the linked list is a bit (0 or 1).
	*/

	//Put your code here
	LinkedList L;
	NodePtr temp = LL.getHeadPtr();
	while (temp != nullptr)
	{
		if (temp->getData() == 0)
			L.head_insert(1);
		else if (temp->getData() == 1)
			L.head_insert(0);
		temp = temp->getLink();
	}
	LL.~LinkedList();
	LL = L;
	return;
}
void reverse(LinkedList &LL)
{
	/*
	This function reverses the linked list object parameter LL. Reversing a linked list means the order of the nodes in the linked list is reversed.
	*/

	//Put your code here
	LinkedList L;
	NodePtr temp = LL.getHeadPtr();
	while (temp != nullptr)
	{
		L.head_insert(temp->getData());
		temp = temp->getLink();
	}
	LL.~LinkedList();
	LL = L;
	return;
}
LinkedList operator + (const LinkedList &LL1, const LinkedList &LL2)
{
	/*
	This function first asserts that the lengths of the linked list object parameters LL1 and LL2 are equal and then adds the bits in LL1 with the bits in LL2 the way we add binary numbers in mathematics. The function stores the sum in a linked list object and then returns the linked list object. Assume the data in each node of the linked lists is a bit (0 or 1).
	*/

	assert(LL1.getLength() == LL2.getLength());

	//Put your remaining code here
	
	int carry = 0;
	int add;
	LinkedList LL3; LinkedList L1 = LL1; LinkedList L2 = LL2;
	reverse(L1);
	reverse(L2);
	NodePtr temp1 = L1.getHeadPtr();
	NodePtr temp2 = L2.getHeadPtr();
	for (int i = 0 ; i < L1.getLength() ; i++)
	{
		if(carry == 0)
			add = temp1->getData() + temp2->getData();
		else
		{
			add = temp1->getData() + temp2->getData() + 1;
			carry = 0;
		}
		if (add > 1)
		{
			add = add - 2;
			carry = 1;
		}
		LL3.head_insert(add);
		temp1 = temp1->getLink();
		temp2 = temp2->getLink();
	}
	L1.~LinkedList();
	L2.~LinkedList();
	return LL3;
}
void addOne(LinkedList &LL)
{
	/*
	This function first asserts that the linked list object parameter LL is not empty and then adds 1 to the bits stored in the nodes of the linked list the way we add binary numbers in mathematics. Assume the data in each node of the linked list is a bit (0 or 1).
	*/
	
	assert(!LL.isEmpty());

	//Put your remaining code here
	LinkedList L;
	reverse(LL);
	int bit, index = 0;
	NodePtr temp = LL.getHeadPtr();
	for (int i = 0 ; i < LL.getLength() ; i++)
	{
		int carry = 0;
		if (temp->getData() == 1)
		{
			bit = 0;
			carry = 1;
		}
		else if (temp->getData() == 0)
		{
			bit = 1;
			carry = 0;
			index ++;
			L.head_insert(bit);
			temp = temp->getLink();
			break;
		}
		L.head_insert(bit);
		temp = temp->getLink();
		index ++;
	}
	for (int i = index ; i < LL.getLength() ; i++)
	{
		L.head_insert(temp->getData());
		temp = temp->getLink();
	}
	LL.~LinkedList();
	LL = L;
	return;
}
LinkedList computeTwosComplementBinary(const int &num, const int &bit_pattern_size)
{
	/*
	This function computes and stores the two's complement binary representation of num in bit_pattern_size bits in a linked list object in such a way that the head node stores the most significant bit while the tail node stores the least significant bit. The function then returns then linked list object.
	*/

	//Put your code here
	LinkedList LL = computeUnsignedBinary(abs(num), bit_pattern_size);
	if (num < 0)
	{
		reverse(LL);
		flipBits(LL);
		addOne(LL);
	}
	return LL;
}
int twosComplementBinaryToDecimal(const LinkedList &LL)
{
	/*
	This function first asserts that the linked list object parameter LL is not empty and then computes and returns the decimal value represented by the bits of the nodes of the linked list assuming two's complement binary representation. Assume the data in each node of the linked list is a bit (0 or 1).
	*/

	assert(!LL.isEmpty());

	//Put your remaining code here
	LinkedList L = LL;
	int n = 0;
	NodePtr temp = L.getHeadPtr();
	if (temp->getData() == 1)
	{
		reverse(L);
		flipBits(L);
		addOne(L);
		reverse(L);
		int i = 0;
		NodePtr temp = L.getHeadPtr();
		while (temp != nullptr)
		{
			if (temp->getData() == 1)
				n += static_cast<int>(pow(2.0,i));
			i++;
			temp = temp->getLink();
		}
		n = n * -1;
	}
	else if (temp->getData() == 0)
	{
		reverse(L);
		int i = 0;
		NodePtr temp = L.getHeadPtr();
		while (temp != nullptr)
		{
			if (temp->getData() == 1)
				n += static_cast<int>(pow(2.0,i));
			i++;
			temp = temp->getLink();
		}
	}
	L.~LinkedList();
	return n;
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

int main()
{
	cout << "This program demonstrates the Linked List Data Structure in C++" << endl;
	cout << "Linked Lists will be used for numeric information representation using" << endl;
	cout << " *** Unsigned Binary Representation" << endl;
	cout << " *** Sign and Magnitude Binary Representation" << endl;
	cout << " *** Two's Complement Binary Representation" << endl << endl;
	cout << "In addition, the program demonstrates" << endl;
	cout << " *** Two's complement binary addition, and" << endl;
	cout << " *** Conversion from two's complement to decimal." << endl << endl;
	do
	{
		int selection = selectComputation();
		if (selection == 1)
		{
			int bit_pattern_size, num;
			cout << endl << "Enter a positive integer for the bit pattern size: ";
			cin >> bit_pattern_size;
			while (bit_pattern_size <= 0)
			{
				cout << "You must enter a positive integer. Enter again please: ";
				cin >> bit_pattern_size;
			}
			cout << "Enter a non-negative integer: ";
			cin >> num;
			while (num < 0)
			{
				cout << "You must enter a non-negative integer. Enter again please: ";
				cin >> num;
			}
			LinkedList LL = computeUnsignedBinary(num, bit_pattern_size);
			cout << "The unsigned binary representation of " << num << " in " << bit_pattern_size << " bit is " << LL << endl;
			cout << endl;
		}
		else if (selection == 2)
		{
			int bit_pattern_size, num;
			cout << endl << "Enter a positive integer for the bit pattern size: ";
			cin >> bit_pattern_size;
			while (bit_pattern_size <= 0)
			{
				cout << "You must enter a positive integer. Enter again please: ";
				cin >> bit_pattern_size;
			}
			cout << "Enter an integer: ";
			cin >> num;
			LinkedList LL = computeSignAndMagnitudeBinary(num, bit_pattern_size);
			cout << "The sign and magnitude binary representation of " << num << " in " << bit_pattern_size << " bit is " << LL << endl;
			cout << endl;
		}
		else if (selection == 3)
		{
			int bit_pattern_size, num1, num2;
			cout << endl << "Enter a positive integer for the bit pattern size: ";
			cin >> bit_pattern_size;
			while (bit_pattern_size <= 0)
			{
				cout << "You must enter a positive integer. Enter again please: ";
				cin >> bit_pattern_size;
			}
			cout << "Enter an integer: ";
			cin >> num1;
			LinkedList LL1 = computeTwosComplementBinary(num1, bit_pattern_size);
			cout << "The two's complement binary representation of " << num1 << " in " << bit_pattern_size << " bit is " << LL1 << endl;
			cout << endl;
			cout << "Enter a second integer: ";
			cin >> num2;
			LinkedList LL2 = computeTwosComplementBinary(num2, bit_pattern_size);
			cout << "The two's complement binary representation of " << num2 << " in " << bit_pattern_size << " bit is " << LL2 << endl;
			cout << endl;
			LinkedList LL3 = LL1 + LL2;
			cout << "The binary sum of " << LL1 << " and " << LL2 << " is " << LL3 << endl;
			int sum = twosComplementBinaryToDecimal(LL3);
			cout << "The integer value of the binary sum is " << sum << endl;
			if (sum == num1 + num2)
				cout << "This is a correct result." << endl;
			else
				cout << "This is not correct result because our bit pattern is too small to store the result." << endl;
				
		}
		else
			break;
		system("Pause");
		cout << endl << endl;
	}while (true);

	system("Pause");
	return 0;
}