#include <iostream>
using namespace std;
class MyRectangle
{
private:
	double length, width;
public:
	//Constructors
	MyRectangle();
	MyRectangle(const double &len, const double &wid);
	MyRectangle(const MyRectangle &r);
	//Getters
	double getLength() const;
	double getWidth() const;
	//Setters
	void setLength(const double &len);
	void setWidth(const double &wid);
	//Other member functions
	double getArea() const;
	double getPerimeter() const;
	friend ostream& operator << (ostream &out, const MyRectangle &r);
	friend istream& operator >> (istream &in, MyRectangle &r);
};

class MySquare : public MyRectangle
{
public:
	//Constructors
	MySquare();
	MySquare(const double &side);
	MySquare(const MySquare &s);
	//Getters
	double getSide() const;
	//Setters
	void setLength(const double &len);
	void setWidth(const double &wid);
	void setSide(const double &side);
	//Other member functions
	friend ostream& operator << (ostream &out, const MySquare &s);
	friend istream& operator >> (istream &in, MySquare &s);
};int main()
{
	//Test Constructors, getters and output streaming operator
	MyRectangle r1;
	MyRectangle r2(2, 3);
	MyRectangle r3 = r2;
	cout << "r1: " << r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r3: " << r3 << endl;
	MySquare s1;
	MySquare s2(3);
	MySquare s3 = s2;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	//Test setters
	r2.setLength(5);
	r3.setWidth(6);
	cout << "r2: " << r2 << endl;
	cout << "r3: " << r3 << endl;
	s1.setLength(8);
	s2.setWidth(4);
	s3.setSide(6);
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	//Test input stream operators
	cin >> r1;
	cin >> s1;
	cout << "r1: " << r1 << endl;
	cout << "s1: " << s1 << endl;
	//Test type casting
	MyRectangle r4 = s1;
	cout << "r4: " << r4 << endl;
	cout << "s2 casted to rectangle: " << static_cast<MyRectangle>(s2) << endl;
	system("Pause");
	return 0;
}

//Constructors
MyRectangle::MyRectangle()
{
	this->length = 0;
	this->width = 0;
}
MyRectangle::MyRectangle(const double &len, const double &wid)
{
	this->length = len;
	this->width = wid;
}
MyRectangle::MyRectangle(const MyRectangle &r)
{
	this->length = r.getLength();
	this->width = r.getWidth();
}
//Getters
double MyRectangle::getLength() const
{
	return this->length;
}
double MyRectangle::getWidth() const
{
	return this->width;
}
//Setters
void MyRectangle::setLength(const double &len)
{
	this->length = len;
}
void MyRectangle::setWidth(const double &wid)
{
	this->width = wid;
}
//Other member functions
double MyRectangle::getArea() const
{
	return this->getLength() * this->getWidth();
}
double MyRectangle::getPerimeter() const
{
	return 2 * (this->getLength() + this->getWidth());
}
ostream& operator << (ostream &out, const MyRectangle &r)
{
	out << endl;
	out << "My Rectangle -> " << endl;
	out << "Length : " << r.getLength() << endl;
	out << "Width : " << r.getWidth() << endl;
	out << "Perimeter : " << r.getPerimeter() << endl;
	out << "Area : " << r.getArea() << endl;
	return out;
}
istream& operator >> (istream &in, MyRectangle &r)
{
	double len, wid;
	cout << "Please enter Rectangle's Length : " << endl;
	in >> len;
	r.setLength(len);
	cout << "Please enter Rectangle's Width : " << endl;
	in >> wid;
	r.setWidth(wid);
	return in;
}

//My Square
//Constructors
MySquare::MySquare()
{
	MyRectangle::setLength(0);
	MyRectangle::setWidth(0);
}
MySquare::MySquare(const double &side)
{
	MyRectangle::setLength(side);
	MyRectangle::setWidth(side);
}
MySquare::MySquare(const MySquare &s)
{
	this->setLength(s.getSide());
	this->setWidth(s.getSide());
}
//Getters
double MySquare::getSide() const
{
	return this->MyRectangle::getLength();
}
//Setters
void MySquare::setLength(const double &len)
{
	this->setSide(len);
}
void MySquare::setWidth(const double &wid)
{
	this->setSide(wid);
}
void MySquare::setSide(const double &side)
{
	this->MyRectangle::setLength(side);
	this->MyRectangle::setWidth(side);
}
//Other member functions
ostream& operator << (ostream &out, const MySquare &s)
{
	out << endl;
	out << "My Square -> " << endl;
	out << "Side : " << s.getLength() << endl;
	out << "Perimeter : " << s.getPerimeter() << endl;
	out << "Area : " << s.getArea() << endl;
	return out;
}
istream& operator >> (istream &in, MySquare &s)
{
	double side;
	cout << "Please enter Square's side : " << endl;
	in >> side;
	s.setSide(side);
	return in;
}