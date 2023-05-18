#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
private:
	string accountholder;
	double balance;
public:
	//Constructors
	BankAccount();
	BankAccount(const string&, const double&);
	BankAccount(const BankAccount&);
	//Destructor
	~BankAccount();
	//Assignment operator
	BankAccount& operator = (const BankAccount&);
	//Getters and setters
	string getAccountHolder() const;
	double getBalance() const;
	void setAccountHolder(const string&);
	void setBalance(const double&);
	//Additional member functions
	void readInfo(istream&);
	void printInfo(ostream&) const;
	//Friend Functions
	friend istream& operator >> (istream&, BankAccount&);
	friend ostream& operator << (ostream&, const BankAccount&);
};
class ChequingAccount : public BankAccount
{
private:
	int maxNumTransactions;
public:
	ChequingAccount();
	ChequingAccount(const string &, const double &, const int& trans);
	ChequingAccount(const ChequingAccount &);

	~ChequingAccount();

	ChequingAccount& operator = (const ChequingAccount &);

	int getmaxNumTransactions() const;
	void setmaxNumTransactions(const int &);

	void deposit(const double &);
	void withdraw(const double &);

	void readInfo(istream &);
	void printInfo(ostream &) const;
	//Friend Functions
	friend istream& operator >> (istream&, ChequingAccount&);
	friend ostream& operator << (ostream&, const ChequingAccount&);
};
int main()
{
	ChequingAccount a1, a2("Jeet", 100.0, 10);
	ChequingAccount a3(a2), a4;
	a4 = a2;
	cout << "Enter a Chequing Account : " << endl << endl;
	cin >> a1;
	
	cout << "Chequing Account a1 = " << a1 << endl;
	
	cout << "Chequing Account a2 = " << a2 << endl;
	cout << "Chequing Account a3 = " << a3 << endl;
	cout << "Chequing Account a4 = " << a4 << endl;
	
	a2.deposit(100);
	cout << "CHANGED Chequing Account a2 = " << a2 << endl;
	a1.withdraw(100);
	cout << "CHANGED Chequing Account a1 = " << a1 << endl;
	a1.~ChequingAccount();
	a2.~ChequingAccount();
	a3.~ChequingAccount();
	a4.~ChequingAccount();
	system ("Pause");
	return 0;
}
BankAccount::BankAccount()
{
	cout << "BankAccount default constructor" << endl;
	this->accountholder = "NULL";
	this->balance = 0.0;
}
BankAccount::BankAccount(const string& name, const double& money)
{
	cout << "BankAccount non-default constructor" << endl;
	this->accountholder = name;
	this->balance = money;
}
BankAccount::BankAccount(const BankAccount& ba)
{
	cout << "BankAccount copy constructor" << endl;
	this->setAccountHolder(ba.getAccountHolder());
	this->setBalance(ba.getBalance());
}
BankAccount::~BankAccount()
{
	cout << "Bank account deleted. Thank You..." << endl;
}
BankAccount& BankAccount::operator = (const BankAccount &ba)
{
	cout << "BankAccount Assignment operator" << endl;
	this->setAccountHolder(ba.getAccountHolder());
	this->setBalance(ba.getBalance());
	return *this;
}

string BankAccount::getAccountHolder() const
{
	return this->accountholder;
}
double BankAccount::getBalance() const
{
	return this->balance;
}
void BankAccount::setAccountHolder(const string& name)
{
	this->accountholder = name;
}
void BankAccount::setBalance(const double& money)
{
	this->balance = money;
}

void BankAccount::readInfo(istream& in)
{
	cout << "Please enter your name : " << endl;
	in >> this->accountholder;
	cout << "Please enter the balance under this name : " << endl;
	in >> this->balance;
}
void BankAccount::printInfo(ostream& out) const
{
	out << "The account holder's name : " << this->accountholder << endl;
	out << "The balance in this account is : " << this->balance << endl;
}
istream& operator >> (istream& in, BankAccount& ba)
{
	ba.readInfo(in);
	return in;
}
ostream& operator << (ostream& out, const BankAccount& ba)
{
	ba.printInfo(out);
	return out;
}

ChequingAccount::ChequingAccount() : maxNumTransactions(0)
{
	cout << "Inside Chequing account default constructor" << endl;
	this->setAccountHolder("No name");
	this->setBalance(0.0);
}
ChequingAccount::ChequingAccount(const string & nam, const double & mon, const int& trans) :BankAccount(nam, mon) , maxNumTransactions(trans)
{
	cout << "Inside Chequing Account non-default constructor" << endl;
	//this->setAccountHolder(nam);
	//this->setBalance(mon);
	
	//this->maxNumTransactions = trans;
}
ChequingAccount::ChequingAccount(const ChequingAccount &ca) : BankAccount(ca) , maxNumTransactions(ca.getmaxNumTransactions())
{
	cout << "Inside ChequingAccount copy constructor" << endl;
	//this->setAccountHolder(ca.getAccountHolder());
	//this->setBalance(ca.getBalance());
	//this->maxNumTransactions = ca.maxNumTransactions;
}
ChequingAccount::~ChequingAccount()
{
	cout << "Chequing Account destructed." << endl;
}
ChequingAccount& ChequingAccount::operator = (const ChequingAccount &ca)
{
	cout << "Inside ChequingAccount Assignment operator" << endl;
	//this->setAccountHolder(ca.getAccountHolder());
	//this->setBalance(ca.getBalance());
	this->BankAccount::operator = (ca);
	this->maxNumTransactions = ca.getmaxNumTransactions();
	return *this;
}

int ChequingAccount::getmaxNumTransactions() const
{
	return maxNumTransactions;
}
void ChequingAccount::setmaxNumTransactions(const int &trans)
{
	this->maxNumTransactions = trans;
}

void ChequingAccount::deposit(const double &bal)
{
	if (bal <= 0)
	{
		cout << "Invalid Entry" << endl;
		return;
	}
	if (maxNumTransactions <= 0)
	{
		cout << "You cannot deposit any more money" << endl;
		return;
	}
	this->setBalance(this->getBalance() + bal);
	maxNumTransactions--;
}
void ChequingAccount::withdraw(const double &bal)
{
	if (bal <= 0 || this->getBalance() - bal <= 0)
	{
		cout << "Invalid Entry" << endl;
		return;
	}
	if (maxNumTransactions <= 0)
	{
		cout << "You cannot deposit any more money" << endl;
		return;
	}
	this->setBalance(this->getBalance() - bal);
	maxNumTransactions--;
}

void ChequingAccount::readInfo(istream &in)
{
	this->BankAccount::readInfo(in);
	cout << "Please enter number of maxNumTransactions : " << endl;
	in >> this->maxNumTransactions;
}
void ChequingAccount::printInfo(ostream &out) const
{
	this->BankAccount::printInfo(out);
	cout << "Your maxNumTransactions are : " << this->maxNumTransactions << endl;
}
istream& operator >> (istream& in, ChequingAccount& ca)
{
	ca.readInfo(in);
	return in;
}
ostream& operator << (ostream& out, const ChequingAccount& ca)
{
	ca.printInfo(out);
	return out;
}