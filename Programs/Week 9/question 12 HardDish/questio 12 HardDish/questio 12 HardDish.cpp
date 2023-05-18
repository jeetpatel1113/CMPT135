#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;
class HardDisk
{
private:
	char* buffer; //Dynamic array to represent hard disk
	int capacity; //The capacity of the hard disk
	int used; //The actual amount of data in the hard disk
protected:
	static int memAllocated;
public:
	HardDisk(); //Default constructor: capacity = 50, used = 0
	HardDisk(int capacityValue); //Non-default constructor: capacity = capacityValue, used = 0
	HardDisk(const HardDisk& hd); //Copy constructor. Deep copy.
	~HardDisk(); //Destructor. Deletes the buffer and sets both capacity and used to 0.
	HardDisk& operator = (const HardDisk& hd); //Assignment operator. Deep copy.
	void write(char e); //writes e to the hard disk. That is it appends e to the buffer. 
	//If buffer is full then print message that the hard disk is full
	//and then return without doing anything
	bool isFull() const; //Returns true if the hard disk is full (capacity == used), false otherwise.
	int getCapacity() const;
	int getUsed() const;
	void cleanup(); //Resets the used member variable to zero (used = 0)
	char& operator[](int index) const; //Asserts index is valid and then returns the element at index
	friend ostream& operator<<(ostream& out, const HardDisk& hd);
	static int getMemAllocated()
	{
		return memAllocated;
	}
};


class HardDiskWithBackup : public HardDisk
{
private:
	char* backupBuffer; //backup hard disk for the hard disk in the base class
	int backupUsed; //the actual amount of data in the backup hard disk
public:
	HardDiskWithBackup(); //Default constructor: Default base class. Derived class (used = 0)
	HardDiskWithBackup(int capacityValue); //Non-default constructor: Non-default base class. Derived class used = 0
		HardDiskWithBackup(const HardDiskWithBackup& hdb); //Copy constructor. Deep copy both base and derived classes
		~HardDiskWithBackup(); //Destructor. Destruct both base and derived classes.
	HardDiskWithBackup& operator = (const HardDiskWithBackup& hdb); //Assignment operator. Deep copy both base and derived classes
		void backup(); //Makes a backup copy of the base class hard disk
	void restore(); //Restores base class hard disk from the derived class backup hard disk
	friend ostream& operator<<(ostream& out, const HardDiskWithBackup& hdb);
};

int main()
{
	//srand(time(0));
	HardDiskWithBackup hdwb1;
	cout << "Hard Disk with backup 1 " << hdwb1 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	hdwb1.~HardDiskWithBackup();
	cout << "Hard Disk with backup 1 " << hdwb1 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	
	HardDiskWithBackup hdwb2(40);
	for (int i = 0; i < 10; i++)
		hdwb2.write(rand()%26+65);
	cout << "Hard Disk with backup 2 " << hdwb2 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	
	HardDiskWithBackup hdwb3(hdwb2);
	cout << "Hard Disk with backup 3 " << hdwb3 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	
	hdwb2.~HardDiskWithBackup();
	cout << "Hard Disk with backup 2 " << hdwb2 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	
	hdwb1 = hdwb3;
	cout << "Hard Disk with backup 1 " << hdwb1 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	hdwb1.backup();
	cout << "Hard Disk with backup 1 " << hdwb1 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	for (int i = 0; i < 5; i++)
		hdwb1.write(rand()%26+65);
	cout << "Hard Disk with backup 1 " << hdwb1 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	
	hdwb2 = hdwb1;
	cout << "Hard Disk with backup 2 " << hdwb2 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	
	hdwb2.cleanup();
	cout << "Hard Disk with backup 2 " << hdwb2 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	
	hdwb2.restore();
	cout << "Hard Disk with backup 2 " << hdwb2 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	
	hdwb1.~HardDiskWithBackup();
	cout << "Hard Disk with backup 1 " << hdwb1 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	
	hdwb2.~HardDiskWithBackup();
	cout << "Hard Disk with backup 2 " << hdwb2 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	
	hdwb3.~HardDiskWithBackup();
	cout << "Hard Disk with backup 3 " << hdwb3 << endl;
	cout << "Memory used so far = " << HardDisk::getMemAllocated() << endl;
	
	system("Pause");
	return 0;
}

//Construcors
int HardDisk::memAllocated = 0;
HardDisk::HardDisk()
{
	capacity = 50;
	buffer = new char[capacity];
	used = 0;
	memAllocated += capacity;
}
HardDisk::HardDisk(int capacityValue)
{
	capacity = capacityValue;
	buffer = new char[capacity];
	used = 0;
	memAllocated += capacity;
}
HardDisk::HardDisk(const HardDisk& hd)
{
	capacity = hd.getCapacity();
	buffer = new char[capacity];
	used = hd.getUsed();
	for (int i = 0 ; i < capacity ; i++)
		this->buffer[i] = hd.buffer[i];
	memAllocated += capacity;
}
HardDisk::~HardDisk()
{
	if (capacity > 0)
		delete[] buffer;
	memAllocated -= capacity;
	capacity = 0;
	used = 0;
}
HardDisk& HardDisk::operator = (const HardDisk& hd)
{
	this->~HardDisk();
	this->capacity = hd.getCapacity();
	this->used = hd.getUsed();
	this->buffer = new char[capacity];
	for (int i = 0 ; i < this->used ; i++)
		this->buffer[i] = hd.buffer[i];
	memAllocated += this->capacity;
	return *this;
}
void HardDisk::write(char e)
{
	if (this->getUsed() == this->getCapacity())
	{
		cout << "The HardDisk is full." << endl;
		return;
	}
	this->buffer[this->getUsed()] = e;
	this->used++;
	return;
}
bool HardDisk::isFull() const
{
	if (this->getCapacity() == this->getUsed())
		return true;
	return false;
}
int HardDisk::getCapacity() const
{
	return this->capacity;
}
int HardDisk::getUsed() const
{
	return this->used;
}
void HardDisk::cleanup()
{
	delete[] this->buffer;
	this->used = 0;
	this->buffer = new char[getCapacity()];
}
char& HardDisk::operator[](int index) const
{
	return this->buffer[index];
}
ostream& operator << (ostream& out, const HardDisk& hd)
{
	out << endl;
	out << '\t' << "Capacity = " << hd.getCapacity() << endl;
	out << '\t' << "Used = " << hd.getUsed() << endl;
	out << '\t' << "Data = [";
	for (int i = 0 ; i < hd.getUsed() ; i++)
		out << hd.buffer[i];
	out << "]" << endl;
	return out;
}



HardDiskWithBackup::HardDiskWithBackup() : HardDisk() //Default constructor: Default base class. Derived class (used = 0)
{
	this->backupBuffer = new char[HardDisk::getCapacity()];
	this->memAllocated += this->getCapacity();
	backupUsed = 0;
}
HardDiskWithBackup::HardDiskWithBackup(int capacityValue) : HardDisk(capacityValue) //Non-default constructor: Non-default base class. Derived class used = 0
{
	this->backupBuffer = new char[HardDisk::getCapacity()];
	this->backupUsed = 0;
	memAllocated += this->HardDisk::getCapacity();
}
HardDiskWithBackup::HardDiskWithBackup(const HardDiskWithBackup& hdb) : HardDisk(hdb) //Copy constructor. Deep copy both base and derived classes
{
	backupUsed = hdb.backupUsed;
	this->backupBuffer = new char[hdb.getCapacity()];
	for (int i = 0 ; i < this->backupUsed ; i++)
		this->backupBuffer[i] = hdb.backupBuffer[i];
	this->memAllocated += this->getCapacity();
}
HardDiskWithBackup::~HardDiskWithBackup() //Destructor. Destruct both base and derived classes.
{
	
	if (this->getCapacity() > 0)
	{
		delete[] this->backupBuffer;
		backupUsed = 0;
	}
	memAllocated -= this->HardDisk::getCapacity();
	this->HardDisk::~HardDisk();
}

HardDiskWithBackup& HardDiskWithBackup::operator = (const HardDiskWithBackup& hdb) //Assignment operator. Deep copy both base and derived classes
{
	this->~HardDiskWithBackup();
	this->HardDisk::operator = (hdb);
	this->backupUsed = hdb.backupUsed;
	this->backupBuffer = new char[getCapacity()];
	for (int i = 0 ; i < getCapacity() ; i++)
		this->backupBuffer[i] = hdb.backupBuffer[i];
	this->memAllocated += this->HardDisk::getCapacity();
	return *this;
}
void HardDiskWithBackup::backup() //Makes a backup copy of the base class hard disk
{
	this->backupUsed = this->getUsed();
	for(int i = 0 ; i < this->getUsed() ; i++)
		this->backupBuffer[i] = this->HardDisk::operator[](i);
	return;
}
void HardDiskWithBackup::restore() //Restores base class hard disk from the derived class backup hard disk
{
	this->cleanup();
	for(int i = 0 ; i < this->backupUsed ; i++)
		this->write(this->backupBuffer[i]);
	return;
}
ostream& operator<<(ostream& out, const HardDiskWithBackup& hdb)
{
	out << endl;
	out << '\t' << "Capacity = " << hdb.getCapacity() << endl;
	out << '\t' << "Used = " << hdb.getUsed() << endl;
	out << '\t' << "Data = [";
	for (int i = 0 ; i < hdb.getUsed() ; i++)
		out << hdb[i];
	out << "]" << endl;
	out << '\t' << "Backup Capacity = " << hdb.getCapacity() << endl;
	out << '\t' << "Backup Used = " << hdb.backupUsed << endl;
	out << '\t' << "Backup Data = [";
	for (int i = 0 ; i < hdb.backupUsed ; i++)
		out << hdb.backupBuffer[i];
	out << "]" << endl;	
	return out;	
}
