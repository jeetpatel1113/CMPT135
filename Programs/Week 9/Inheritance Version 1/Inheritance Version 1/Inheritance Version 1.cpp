#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
	string firstName, lastName;
protected:
	double salary;
public:
	//Constructors
	Employee();
	Employee(const string&, const string&, const double&);
	Employee(const Employee&);
	//Destructor
	~Employee();
	//Assignment operator
	Employee& operator=(const Employee&);
	//Getters
	string getFirstName() const;
	string getLastName() const;
	double getSalary() const;
	//Setters
	void setFirstName(const string&);
	void setLastName(const string&);
	void setSalary(const double&);
	//Additional member functions
	void readInfo(istream&);
	void printInfo(ostream&) const;
	//Friend functions
	friend istream& operator>>(istream&, Employee&);
	friend ostream& operator<<(ostream&, const Employee&);
};

Employee::Employee() : firstName("N/A"), lastName("N/A"), salary(0.00)
{
	cout << "Inside employee default constructor"<< endl;
}
Employee::Employee(const string& f, const string& l, const double& s) : firstName(f), lastName(l), salary(s)
{
	cout << "Inside employee non-default constructor"<< endl;
}
Employee::Employee(const Employee& e) : firstName(e.firstName), lastName(e.lastName), salary(e.salary)
{	
	cout << "Inside employee copy constructor"<< endl;
}
Employee::~Employee()
{
	cout << "Employee object destructed" << endl;
}
Employee& Employee::operator=(const Employee& e)
{
	firstName = e.firstName;
	lastName = e.lastName;
	salary = e.salary;
	return *this;
}
string Employee::getFirstName() const
{
	return firstName;
}
string Employee::getLastName() const
{
	return lastName;
}
double Employee::getSalary() const
{
	return salary;
}
void Employee::setFirstName(const string& f)
{
	firstName = f;
}
void Employee::setLastName(const string& l)
{
	lastName = l;
}
void Employee::setSalary(const double& s)
{
	salary = s;
}
void Employee::readInfo(istream& in)
{
	cout << endl;
	cout << "\tEnter first name: ";
	in >> firstName;
	cout << "\tEnter last name: ";
	in >> lastName;
	cout << "\tEnter salary: ";
	in >> salary;
}
void Employee::printInfo(ostream& out) const
{
	out << endl;
	out << "\tFull Name = " << firstName << " " << lastName << endl;
	out << "\tSalary = " << salary << endl;
}
istream& operator>>(istream& in, Employee& e)
{
	e.readInfo(in);
	return in;
}
ostream& operator<<(ostream& out, const Employee& e)
{
	e.printInfo(out);
	return out;
}


class Manager : public Employee
{
private:
	int num; //number of subordinates
public:
	//Constructors
	Manager();
	Manager(const string&, const string&, const double&, const int&);
	Manager(const Manager&);
	//Destructor
	~Manager();
	//Assignment operator
	Manager& operator=(const Manager&);
	//Getters
	int getSubordinates() const;
	//Setters
	void setSubordinates(const int&);
	//Additional member functions
	void readInfo(istream&);
	void printInfo(ostream&) const;
	//Friend functions
	friend istream& operator>>(istream& in, Manager& m);
	friend ostream& operator<<(ostream& out, const Manager& m);
};
Manager::Manager() : Employee(), num(0)
{
	
	cout << "Inside manager default constructor" << endl;
	/*
	this->setFirstName("N/A");
	this->setLastName("N/A");
	this->salary = 0.00;
	*/
}
Manager::Manager(const string& f, const string& l, const double& s, const int& n) : Employee(f, l, s), num(n)
{
	cout << "Inside manager non-default constructor" << endl;
	/*
	this->setFirstName(f);
	this->setLastName(l);
	this->salary = s;
	*/
}
Manager::Manager(const Manager& m) : Employee(m), num(m.num)
{
	cout << "Inside manager copy constructor" << endl;
	/*
	this->setFirstName(m.getFirstName());
	this->setLastName(m.getLastName());
	this->salary = m.salary;
	*/
}
Manager::~Manager()
{
	cout << "Manager object destructed" << endl;
}
Manager& Manager::operator=(const Manager& m)
{
	/*
	this->setFirstName(m.getFirstName());
	this->setLastName(m.getLastName());
	this->salary = m.salary;
	*/
	this->Employee::operator=(m);
	num = m.num;
	return *this;
}
int Manager::getSubordinates() const
{
	return num;
}
void Manager::setSubordinates(const int& n)
{
	num = n;
}
void Manager::readInfo(istream& in)
{
	/*
	cout << endl;
	string temp;
	cout << "\tEnter first name: ";
	in >> temp;
	this->setFirstName(temp);
	cout << "\tEnter last name: ";
	in >> temp;
	this->setLastName(temp);
	cout << "\tEnter salary: ";
	in >> this->salary;
	*/
	this->Employee::readInfo(in);
	cout << "\tEnter number of subordinates: ";
	in >> this->num;
}
void Manager::printInfo(ostream& out) const
{
	/*
	out << endl;
	out << "\tFull Name = " << this->getFirstName() << " " << this->getLastName() << endl;
	out << "\tSalary = " << this->salary << endl;
	*/
	this->Employee::printInfo(out);
	out << "\tNumber of subordinates = " << this->num << endl;
}
istream& operator>>(istream& in, Manager& m)
{
	m.readInfo(in);
	return in;
}
ostream& operator<<(ostream& out, const Manager& m)
{
	m.printInfo(out);
	return out;
}

int main()
{
	/*
	Manager m1, m2("Sam", "Smith", 2800.00, 5);
	Manager m3(m2), m4;
	m4 = m2;
	cout << "Enter a manager ";
	cin >> m1;
	cout << "Manager 1 " << m1 << endl;
	cout << "Manager 2 " << m2 << endl;
	cout << "Manager 3 " << m3 << endl;
	cout << "Manager 4 " << m4 << endl;

	m1.~Manager();
	m2.~Manager();
	m3.~Manager();
	m4.~Manager();
	*/

	/*
	//TO SHOW STATIC_CAST USE TEMP AND COPY CONSTRUCTOR
	Employee e1;
	Manager m1("Sam", "Smith", 2800.00, 5);
	e1 = static_cast<Employee> (m1);
	Employee e2(static_cast<Employee>(m1));
	m1.printInfo(cout);
	static_cast<Employee>(m1).printInfo(cout);
	e2.printInfo(cout);
	cout << static_cast<Employee>(m1) << endl;
	*/

	Employee E[10];
	cout << "Populating the array" << endl;
	for (int i = 0 ; i < 10 ; i++)
	{
		if (i % 2 == 0)
			E[i] = Employee();
		else
			E[i] = Manager();
	}
	cout << "Printing the elements of the array" << endl;
	for (int i = 0 ; i < 10 ; i++)
		cout << E[i] << endl;

	system("Pause");
	return 0;
}



