#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class SmarterArray
{
private:
	T *A;
	int size;

public:
	//Constructors
	SmarterArray(); //Implemented for you
	SmarterArray(const SmarterArray<T>&); //Copy constructor: Deep copy of the argument

	//Assignment operator
	SmarterArray<T>& operator = (const SmarterArray<T>&); //Assignment operator. Memory clean up and deep copy of the argument

	//Destructor
	~SmarterArray(); //Destructor. Memory clean up

	//Getters, Setters, operators and other functions
	int getSize() const; //Return the size of the calling object
	T& operator[](const int&) const; //Assert index is valid and then return the element at the given index
	int find(const T&) const; //Return the index of the element that is == to the argument. Return -1 if not found.
	void append(const T&); //Append the argument to the calling object.
	bool remove(const int&); //If the index argument is a valid index, then remove the element at the index argument
							//from the calling object and return true. Otherwise return false. 
							//You don't need to assert the index argument.
	bool operator == (const SmarterArray<T>&) const; //return true if sizes are equal and elements at same indexes are ==
	
	template <class TF>
	friend ostream& operator << (ostream&, const SmarterArray<TF>&); //Implemented for you
};
template <class T>
SmarterArray<T>::SmarterArray()
{
	this->A = nullptr;
	this->size = 0;
}
template <class T>
SmarterArray<T>::SmarterArray(const SmarterArray<T>& L)
{
	this->size = L.size;
	this->A = new T [size];
	for (int i = 0 ; i < size ; i++)
		this->A[i] = L.A[i];
}
template <class T>
SmarterArray<T>& SmarterArray<T>::operator = (const SmarterArray<T>& L)
{
	this->~SmarterArray();
	this->size = L.size;
	this->A = new T [size];
	for (int i = 0 ; i < size ; i++)
		this->A[i] = L.A[i];
	return *this;
}
template <class T>
SmarterArray<T>::~SmarterArray()
{
	if (this->size == 0)
		return;
	delete[] this->A;
	this->size = 0;
}
template <class T>
int SmarterArray<T>::getSize() const
{
	return this->size;
}
template <class T>
T& SmarterArray<T>::operator[] (const int& index) const
{
	return this->A[index];
}
template <class T>
int SmarterArray<T>::find (const T& element) const
{
	for (int i = 0 ; i < this->size ; i++)
		if (this->A[i] == element)
			return i;
	return -1;
}
template <class T>
void SmarterArray<T>::append (const T& A)
{
	T* temp = new T [this->size + 1];
	for (int i = 0 ; i < this->size ; i++)
		temp[i] = this->operator[](i);
	temp[this->size] = A;
	delete[] this->A;
	this->A = temp;
	this->size++;
}
template <class T>
bool SmarterArray<T>::remove (const int& index)
{
	if (index < 0 || index > this->getSize())
		return false;
	else if (this->size == 1)
		this->~SmarterArray();
	SmarterArray<T> temp;
	for (int i = 0 ; i < index ; i++)
		temp.append(this->operator[](i));
	for (int i = index + 1 ; i < this->size ; i++)
		temp.append(this->operator[](i));
	this->~SmarterArray();
	*this = temp;
	return true;
}
template <class T>
bool SmarterArray<T>::operator == (const SmarterArray<T>& L) const
{
	if (this->size != L.getSize())
		return false;
	for (int i = 0 ; i < this->size ; i++)
		if (this->A[i] == L.A[i])
			return true;
	return false;
}
template <class TF>
ostream& operator << (ostream& out, const SmarterArray<TF>& L)
{
	if (L.getSize() == 0)
		out << "[Empty List]";
	else
	{
		for (int i = 0; i < L.getSize()-1; i++)
			out << L[i] << endl;
		out << L[L.getSize()-1] << endl;
	}
	return out;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class K, class V>
class Map
{
private:
	SmarterArray<K> A1;	//The keys of the map
	SmarterArray<V> A2;	//The values of the map
	
public:
	//Constructors
	Map(); //Implemented for you
	Map(const Map<K, V>&); //Copy constructor. Deep copy.

	//Assignment operator
	Map<K, V>& operator = (const Map<K, V>&); //Assignment operator. Memory clean up and deep copy.

	//Destructor
	~Map(); //Destructor.

	//Getters, Setters, operators and other functions
	int getSize() const; //Return the common size of the map.
	int findKey(const K&) const; //Return the index of the first element of the Keys array == the argument. Return -1 if not found.
	int findValue(const V&) const; //Return the index of the first element of the Values array == the argument. Return -1 if not found.
	K getKey(const V&) const; //Assert the argument is found in the Values array and then return the first key with the given value 
	V getValue(const K&) const; //Assert the argument is found in the Keys array and then return the first value with the given key
	K getKeyAtIndex(const int&) const; //Assert the index argument and then return the key at the given index
	V getValueAtIndex(const int&) const; //Assert the index argument and then return the value at the given index
	void setKeyAtIndex(const int&, const K&); //Assert the index argument and then set the key at the given index
	void setValueAtIndex(const int&, const V&); //Assert the index argument and then set the value at the given index
	void append(const K&, const V&); //Append the key-value pair to the calling object
	bool remove(const int&); //If the index argument is a valid index, then remove the key-value pair at the index argument
							//from the calling object and return true. Otherwise return false. 
							//You don't need to assert the index argument.

	template <class KF, class VF>
	friend ostream& operator << (ostream&, const Map<KF, VF>&); //Implemented for you
};
template <class K, class V>
Map<K, V>::Map()
{
	//No code is needed here.
	//The member variables will automatically be initialized as default objects
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
	this->A1 = M.A1;
	this->A2 = M.A2;
	return *this;
}
template <class K, class V>
Map<K, V>::~Map()
{
	this->A1.~SmarterArray();
	this->A2.~SmarterArray();
}
template <class K, class V>
int Map<K, V>::getSize() const
{
	return this->A1.getSize();
}
template <class K, class V>
int Map<K, V>::findKey (const K& key) const
{
	for (int i = 0 ; i < this->getSize() ; i++)
		if (this->A1.operator[](i) == key)
			return i;
	return -1;
}
template <class K, class V>
int Map<K, V>::findValue (const V& value) const
{
	for (int i = 0 ; i < this->A2.getSize() ; i++)
		if (this->A2.operator[](i) == value)
			return i;
	return -1;
}
template <class K, class V>
K Map<K, V>::getKey (const V& value) const
{
	int index = A2.find(value);
	assert (index != -1);
	return this->A1[index];
}
template <class K, class V>
V Map<K, V>::getValue(const K& key) const
{
	int index = A1.find(key);
	assert (index != -1);
	return A2[index];
}
template <class K, class V>
K Map<K, V>::getKeyAtIndex(const int& index) const
{
	assert (index >= 0 && index < A1.getSize());
	return A1[index];
}
template <class K, class V>
V Map<K, V>::getValueAtIndex(const int& index) const
{
	assert (index >= 0 && index < A2.getSize());
	return A2[index];
}
template <class K, class V>
void Map<K, V>::setKeyAtIndex(const int& index, const K& key)
{
	assert (index >= 0 && index < A1.getSize());
	A1[index] = key;
}
template <class K, class V>
void Map<K, V>::setValueAtIndex(const int& index, const V& value)
{
	assert (index >= 0 && index < A2.getSize());
	A2[index] = value;
}
template <class K, class V>
void Map<K, V>::append(const K& key, const V& value)
{
	A1.append(key);
	A2.append(value);
}
template <class K, class V>
bool Map<K, V>::remove(const int& index)
{
	return (A1.remove(index) && A2.remove(index));
}
template <class KF, class VF>
ostream& operator << (ostream& out, const Map<KF, VF>& m)
{
	if (m.getSize() == 0)
		out << "[Empty Map]" << endl;
	else
	{
		for (int i = 0; i < m.getSize(); i++)
			out << m.A1[i] << ", " << m.A2[i] << endl;
	}
	return out;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Course
{
private:
	string name;
	int creditHours;
public:
	Course();
	Course(const string&, const int&);
	string getCourseName() const;
	int getCreditHours() const;
	void setCourseName(const string&);
	void setCreditHours(const int&);
	bool operator == (const Course&) const; //Return true if course names are equal and credit hours are also equal.
	friend ostream& operator << (ostream&, const Course&);
};
Course::Course()
{
	name = "None";
	creditHours = 0;
}
Course::Course(const string& new_name, const int& credithrs)
{
	name = new_name;
	creditHours = credithrs;
}
string Course::getCourseName() const
{
	return this->name;
}
int Course::getCreditHours() const
{
	return this->creditHours;
}
void Course::setCourseName (const string& new_name)
{
	this->name = new_name;
}
void Course::setCreditHours (const int& creditHrs)
{
	this->creditHours = creditHrs;
}
bool Course::operator == (const Course& course) const
{
	if (this->name == course.getCourseName())
		if (this->creditHours == course.getCreditHours())
			return true;
	return false;
}
ostream& operator << (ostream& out, const Course& c)
{
	out << "Course Name = " << c.name << ", Credit Hours = " << c.creditHours;
	return out;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Date
{
	int y, m, d;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Student
{
private:
	string fn, ln; //first name and last name
	Date dob;
public:
	Student(); //Implemented for you
	Student(const string& firstName, const string& lastName, const Date&);
	string getFirstName() const;
	string getLastName() const;
	Date getDob() const;
	void setFirstName(const string&);
	void setLastName(const string&);
	void setDob(const Date&);
	bool operator == (const Student&) const; //Return true if all the first names, last names, and date of births are equal
	friend ostream& operator << (ostream&, const Student&); //Implemented for you
};
Student::Student()
{
	fn = "None";
	ln = "None";
	dob.y = 0;
	dob.m = 0;
	dob.d = 0;
}
Student::Student(const string& firstName, const string& lastName, const Date& date)
{
	fn = firstName;
	ln = lastName;
	dob.d = date.d;
	dob.m = date.m;
	dob.y = date.y;
}
string Student::getFirstName() const
{
	return this->fn;
}
string Student::getLastName() const
{
	return this->ln;
}
Date Student::getDob() const
{
	return this->dob;
}
void Student::setFirstName (const string& new_firstname)
{
	this->fn = new_firstname;
}
void Student::setLastName (const string& new_lastname)
{
	this->ln = new_lastname;
}
void Student::setDob(const Date& date)
{
	dob.d = date.d;
	dob.m = date.m;
	dob.y = date.y;
}
bool Student::operator == (const Student& student) const
{
	if (this->fn == student.getFirstName())
		if (this->ln == student.getLastName())
			if (this->dob.d == student.getDob().d)
				if (this->dob.m == student.getDob().m)
					if (this->dob.y == student.getDob().y)
						return true;
	return false;
}
ostream& operator << (ostream& out, const Student& s)
{
	out << "Full Name = " << s.fn << " " << s.ln << ": ";
	out << "DOB (d-m-y) = " << s.dob.d << "-" << s.dob.m << "-" << s.dob.y;
	return out;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef Map<int, char> StudentMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class SchoolManagementSystem
{
private:
	SmarterArray<Student> studentList; //A SmarterArray to store the students in the school
	SmarterArray<Course> courseList; //A SmarterArray to store the courses in the school
	SmarterArray<StudentMap> studentMapList; //A SmarterArray to store the students' maps

public:
	//Constructors
	SchoolManagementSystem();

	//Getters
	int getNumberOfRegisteredStudents() const;
	int getNumberOfCoursesOffered() const;
	int findStudent(const string &firstName, const string &lastName) const;
	Student getStudent(const int &studentIndex) const;
	StudentMap getStudentMap(const int &studentIndex) const;
	int findCourse(const string &courseName) const;
	Course getCourse(const int &courseIndex) const;
	double getStudentGPA(const int &studentIndex) const;
	int getTopStudentIndex() const;
	
	//Setters
	bool registerStudent(const Student &s);
	bool enrolStudent(const int &studentIndex, const int &courseIndex);
	bool assignLetterGrade(const int &studentIndex, const int &courseIndex, const char &letterGrade);
	bool offerCourse(const Course &course);
	void removeStudent(const int &studentIndex);
	bool withdrawStudent(const int &studentIndex, const int &courseIndex);
	void removeCourse(const int &courseIndex);

	//Static functions
	static Student generateRandomStudent();
	static char generateRandomLetterGrade();

	//Friend functions
	friend ostream& operator << (ostream &, const SchoolManagementSystem &);
};
SchoolManagementSystem::SchoolManagementSystem()
{}
int SchoolManagementSystem::getNumberOfRegisteredStudents() const
{
	return this->studentList.getSize();
}
int SchoolManagementSystem::getNumberOfCoursesOffered() const
{
	return this->courseList.getSize();
}
int SchoolManagementSystem::findStudent(const string &firstName, const string &lastName) const
{
	for (int i = 0 ; i < this->studentList.getSize() ; i++)
		if (this->studentList[i].getFirstName() == firstName)
			if (this->studentList[i].getLastName() == lastName)
				return i;
	return -1;
}
Student SchoolManagementSystem::getStudent(const int &studentIndex) const
{
	assert (studentIndex >= 0 && studentIndex < this->studentList.getSize());
	return this->studentList[studentIndex];
}
StudentMap SchoolManagementSystem::getStudentMap(const int &studentIndex) const
{
	assert (studentIndex >= 0 && studentIndex < this->studentMapList.getSize());
	return this->studentMapList[studentIndex];
}
int SchoolManagementSystem::findCourse(const string &courseName) const
{
	for (int i = 0 ; i < this->courseList.getSize() ; i++)
		if (this->courseList[i].getCourseName() == courseName)
			return i;
	return -1;
}
Course SchoolManagementSystem::getCourse(const int &courseIndex) const
{
	assert (courseIndex >= 0 && courseIndex < this->courseList.getSize());
	return this->courseList[courseIndex];
}
double SchoolManagementSystem::getStudentGPA(const int &studentIndex) const
{
	assert (studentIndex >= 0 && studentIndex < this->getNumberOfRegisteredStudents());
	if (this->studentMapList[studentIndex].getSize() == 0)
		return 0.0;
	for (int i = 0 ; i < this->studentMapList[studentIndex].getSize() ; i++)
	{
		if (this->studentMapList[studentIndex].getValueAtIndex(i) != 'N')
			break;
		return 0.0;
	}
	int totalcreditHours = 0;
	double creditPoints = 0.0;
	for (int i = 0 ; i < this->studentMapList[studentIndex].getSize() ; i++)
	{
		if (this->studentMapList[studentIndex].getValueAtIndex(i) == 'A')
		{
			int creditHours = this->courseList[this->studentMapList[studentIndex].getKeyAtIndex(i)].getCreditHours();
			totalcreditHours += creditHours;
			creditPoints = creditPoints + 4.0 * creditHours;
		}
		else if (this->studentMapList[studentIndex].getValueAtIndex(i) == 'B')
		{
			int creditHours = this->courseList[this->studentMapList[studentIndex].getKeyAtIndex(i)].getCreditHours();
			totalcreditHours += creditHours;
			creditPoints += 3.0 * creditHours;
		}
		else if (this->studentMapList[studentIndex].getValueAtIndex(i) == 'C')
		{
			int creditHours = this->courseList[this->studentMapList[studentIndex].getKeyAtIndex(i)].getCreditHours();
			totalcreditHours += creditHours;
			creditPoints += 2.0 * creditHours;
		}
		else if (this->studentMapList[studentIndex].getValueAtIndex(i) == 'D')
		{
			int creditHours = this->courseList[this->studentMapList[studentIndex].getKeyAtIndex(i)].getCreditHours();
			totalcreditHours += creditHours;
			creditPoints += 1.0 * creditHours;
		}
		else if (this->studentMapList[studentIndex].getValueAtIndex(i) == 'F')
		{
			int creditHours = this->courseList[this->studentMapList[studentIndex].getKeyAtIndex(i)].getCreditHours();
			totalcreditHours += creditHours;
			creditPoints += 0.0 * creditHours;
		}
	}
	double GPA = creditPoints / totalcreditHours;
	return GPA;

}
int SchoolManagementSystem::getTopStudentIndex() const
{
	assert (this->getNumberOfRegisteredStudents() > 0);
	double maximumGPA = -1;
	int topStudentIndex;
	for (int i = 0 ; i < this->studentList.getSize() ; i++)
	{
		double GPA = this->getStudentGPA(i);
		if (GPA > maximumGPA)
		{
			topStudentIndex = i;
			maximumGPA = GPA;
		}
	}
	return topStudentIndex;
}

bool SchoolManagementSystem::registerStudent(const Student &s)
{
	for (int i = 0 ; i < this->getNumberOfRegisteredStudents() ; i++)
		if (this->getStudent(i) == s)
			return false;
	this->studentList.append(s);
	StudentMap EmptyStudentMap;
	this->studentMapList.append(EmptyStudentMap);
	return true;
}
bool SchoolManagementSystem::enrolStudent(const int &studentIndex, const int &courseIndex)
{
	assert (studentIndex >= 0 && studentIndex < this->getNumberOfRegisteredStudents());
	assert (courseIndex >= 0 && courseIndex < this->getNumberOfCoursesOffered());
	if (this->studentMapList[studentIndex].findKey(courseIndex) != -1)
		return false;
	this->studentMapList[studentIndex].append(courseIndex, 'N');
	return true;
}
bool SchoolManagementSystem::assignLetterGrade(const int &studentIndex, const int &courseIndex, const char &letterGrade)
{
	assert (studentIndex >= 0 && studentIndex < this->getNumberOfRegisteredStudents());
	assert (courseIndex >= 0 && courseIndex < this->getNumberOfCoursesOffered());
	assert (letterGrade == 'A' || letterGrade == 'B' || letterGrade == 'C' || letterGrade == 'D' || letterGrade == 'F');
	int indexOfCourseInMap = this->studentMapList[studentIndex].findKey(courseIndex);
	if (indexOfCourseInMap == -1)
		return false;
	this->studentMapList[studentIndex].setValueAtIndex(indexOfCourseInMap, letterGrade);
	return true;
}
bool SchoolManagementSystem::offerCourse(const Course &course)
{
	for (int i = 0 ; i < this->getNumberOfCoursesOffered() ; i++)
		if (this->courseList[i] == course)
			return false;
	this->courseList.append(course);
	return true;
}
void SchoolManagementSystem::removeStudent(const int &studentIndex)
{
	assert (studentIndex >= 0 && studentIndex < this->getNumberOfRegisteredStudents());
	this->studentList.remove(studentIndex);
	this->studentMapList.remove(studentIndex);
	return;
}
bool SchoolManagementSystem::withdrawStudent(const int &studentIndex, const int &courseIndex)
{
	assert (studentIndex >= 0 && studentIndex < this->getNumberOfRegisteredStudents());
	assert (courseIndex >= 0 && courseIndex < this->getNumberOfCoursesOffered());
	int indexOfCourseInMap = this->studentMapList[studentIndex].findKey(courseIndex);
	if (indexOfCourseInMap == -1)
		return false;
	this->studentMapList[studentIndex].remove(indexOfCourseInMap);
	return true;
}
void SchoolManagementSystem::removeCourse(const int &courseIndex)
{
	assert (courseIndex >= 0 && courseIndex < this->getNumberOfCoursesOffered());
	for (int i = 0 ; i < this->getNumberOfRegisteredStudents() ; i++)
		withdrawStudent(i, courseIndex);
	this->courseList.remove(courseIndex);
	for (int i = 0 ; i < this->getNumberOfRegisteredStudents() ; i++)
		for (int j = 0 ; j < this->studentMapList[i].getSize() ; j++)
			if (this->studentMapList[i].getKeyAtIndex(j) > courseIndex)
				this->studentMapList[i].setKeyAtIndex(j, this->studentMapList[i].getKeyAtIndex(j) - 1);
	return;
}
ostream& operator << (ostream &out, const SchoolManagementSystem &sms)
{
	out << endl << "Students List" << endl;
	if (sms.studentList.getSize() == 0)
		out << "No student has been registered yet." << endl;
	for (int studentIndex = 0; studentIndex < sms.studentList.getSize(); studentIndex++)
		out << "Student at index " << studentIndex << ": " << sms.studentList[studentIndex] << endl;

	out << endl << "Courses List" << endl;
	if (sms.courseList.getSize() == 0)
		out << "No course has been offered yet." << endl;
	for (int courseIndex = 0; courseIndex < sms.courseList.getSize(); courseIndex++)
		out << "Course at index " << courseIndex << ": " << sms.courseList[courseIndex] << endl;

	cout << endl << "Students Map" << endl;
	if (sms.studentMapList.getSize() == 0)
		out << "No student is enrolled in any course yet." << endl;
	for (int studentIndex = 0; studentIndex < sms.studentMapList.getSize(); studentIndex++)
	{
		out << "Student at index " << studentIndex << endl;
		out << sms.studentMapList[studentIndex];
		out << "GPA = " << sms.getStudentGPA(studentIndex) << endl << endl;
	}
	return out;
}
Student SchoolManagementSystem::generateRandomStudent()
{
	string fn, ln;
	Date dob;

	fn = rand() % 26 + 65;
	for (int i = 0; i < 9; i++)
		fn += char(rand() % 26 + 97);

	ln = rand() % 26 + 65;
	for (int i = 0; i < 9; i++)
		ln += char(rand() % 26 + 97);

	dob.y = 1998 + rand() % 5;
	dob.m = 1 + rand() % 12;
	dob.d = 1 + rand() % 30;

	return Student(fn, ln, dob);
}
char SchoolManagementSystem::generateRandomLetterGrade()
{
	int g = rand() % 11;
	if (g == 0)
		return 'A';
	else if (g <= 2)
		return'B';
	else if (g <= 5)
		return'C';
	else if (g <= 7)
		return 'D';
	else
		return 'F';
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	cout << "Welcome to Phantom College School Management System" << endl;
	cout << "===================================================" << endl;
	
	srand(1);
	const int STUDENT_SIZE = 10;
	const int COURSE_SIZE = 16;
	
	//Prepare the courses offered in the school
	Course course[] = {Course("CMPT120", 2), Course("CMPT130", 3), Course("CMPT135", 4),
		Course("MACM101", 2), Course("CALC151", 3), Course("CALC152", 4),
				  Course("MATH242", 4), Course("ECON101", 3), Course("ECON102", 4),
				  Course("ENGL100", 2), Course("HIST101", 3), Course("PHYS100", 2),
				  Course("PHYS101", 3), Course("PHYS102", 4), Course("CHEM101", 3),
				  Course("CHEM102", 4)};
	
	//Construct and print a school management system object
	SchoolManagementSystem sms;
	cout << sms << endl;
	
	//Add courses offered into the system
	for (int i = 0; i < COURSE_SIZE; i++)	//there are 16 courses initially
	{
		bool flag = sms.offerCourse(course[i]);
		if (flag)
			cout <<"Course offering successful." << endl;
		else
			cout << "Course offering failed. The same course already exists in the system." << endl;
	}
	cout << endl << "Some courses have been offered and added in to the system." << endl;
	cout << "The updated system information is..." << endl;
	cout << sms << endl;

	//See if CMPT135 course is offered in the school
	int courseIndex = sms.findCourse("CMPT225");
	if (courseIndex == -1)
		cout << "CMPT225 course is not offered in the school." << endl << endl;
	else
	{
		cout << "CMPT225 course is offered in the school. Details below..." << endl;
		cout << sms.getCourse(courseIndex) << endl;
	}
	
	//See if a randomly chosen course is offered in the school
	int randomCourseIndex = rand() % sms.getNumberOfCoursesOffered();
	Course c = sms.getCourse(randomCourseIndex);
	courseIndex = sms.findCourse(c.getCourseName());
	if (courseIndex == -1)
		cout << c.getCourseName() << " course is not offered in the school." << endl << endl;
	else
	{
		cout << c.getCourseName() << " course is offered in the school. Details below..." << endl;
		cout << sms.getCourse(courseIndex) << endl << endl;
	}

	//Register some new students into the system
	for (int i = 0; i < STUDENT_SIZE; i++)
	{
		bool flag = sms.registerStudent(Student(sms.generateRandomStudent()));
		if (flag)
			cout <<"Student registration successful." << endl;
		else
			cout << "Student registration failed. The same student already exists in the system." << endl;
	}
	cout << endl << "Some students have been registered in to the system." << endl;
	cout << "The updated system information is..." << endl;
	cout << sms << endl;
	
	//See if Yonas Weldeselassie is a student in the school
	int studentIndex = sms.findStudent("Yonas", "Weldeselassie");
	if (studentIndex == -1)
		cout << "Yonas Weldeselassie is not a student in the school." << endl << endl;
	else
	{
		cout << "Yonas Weldeselassie is a student in the school. Details below..." << endl;
		cout << sms.getStudent(studentIndex) << endl;
		cout << sms.getStudentMap(studentIndex) << endl;
		cout << "GPA = " << sms.getStudentGPA(studentIndex) << endl << endl;
	}

	//See if a randomly chosen student is a student in the school
	int randomStudentIndex = rand() % sms.getNumberOfRegisteredStudents();
	Student s = sms.getStudent(randomStudentIndex);
	studentIndex = sms.findStudent(s.getFirstName(), s.getLastName());
	if (studentIndex == -1)
		cout << s.getFirstName() << " " << s.getLastName() << " is not a student in the school." << endl << endl;
	else
	{
		cout << s.getFirstName() << " " << s.getLastName() << " is a student in the school. Details below..." << endl;
		cout << sms.getStudent(studentIndex) << endl;
		cout << sms.getStudentMap(studentIndex);
		cout << "GPA = " << sms.getStudentGPA(studentIndex) << endl << endl;
	}
	
	//Enroll students to some courses
	for (int studentIndex = 0; studentIndex < sms.getNumberOfRegisteredStudents(); studentIndex++)
	{
		int numberOfCourses = rand() % (sms.getNumberOfCoursesOffered()/2);
		for (int i = 0; i < numberOfCourses; i++)
		{
			int courseIndex = rand() % sms.getNumberOfCoursesOffered();
			sms.enrolStudent(studentIndex, courseIndex);
		}
	}
	cout << endl << "Some students have been enrolled in to some courses." << endl;
	cout << "The updated system information is..." << endl;
	cout << sms << endl;
	
	//Assign letter grades to the students
	for (int studentIndex = 0; studentIndex < sms.getNumberOfRegisteredStudents(); studentIndex++)
	{
		if (rand() % 4 == 0)
		{
			cout << "Skipping a student from letter grade assignments." << endl;
			continue;
		}
		int n = sms.getStudentMap(studentIndex).getSize(); //Assign letter grades to each course the student is enrolled in
		for (int j = 0; j < n; j++)
		{
			if (rand() % 5 == 0)
			{
				cout << "Skipping a course from letter grade assignment." << endl;
				continue;
			}
			int courseIndex = sms.getStudentMap(studentIndex).getKeyAtIndex(j);
			sms.assignLetterGrade(studentIndex, courseIndex, sms.generateRandomLetterGrade());
		}
	}
	cout << endl << "Students have been assigned letter grades." << endl;
	cout << "The updated system information is..." << endl;
	cout << sms << endl;
	
	//The operations below are performed several times in order to test our work rigorously.
	for (int i = 0; i < STUDENT_SIZE/2; i++)
	{
		if (sms.getNumberOfRegisteredStudents() == 0)
			continue;	//There is no any student in the system so we don't need to do anything

		//Remove a randomly chosen student from the system
		randomStudentIndex = rand() % sms.getNumberOfRegisteredStudents();
		sms.removeStudent(randomStudentIndex);
		cout << endl << "The student at index " << randomStudentIndex << " has been removed from the system." << endl;
		cout << "The updated system information is..." << endl;
		cout << sms << endl;
		
		if (sms.getNumberOfRegisteredStudents() == 0 || sms.getNumberOfCoursesOffered() == 0)
			continue;	//There is no any student or any course in the system so we don't need to do anything
		
		//Withdraw a student from a course
		randomStudentIndex = rand() % sms.getNumberOfRegisteredStudents();
		s = sms.getStudent(randomStudentIndex);
		studentIndex = sms.findStudent(s.getFirstName(), s.getLastName());
		if (studentIndex == -1)
			cout << s.getFirstName() << " " << s.getLastName() << " is not a student in the school." << endl << endl;
		else
		{
			cout << s.getFirstName() << " " << s.getLastName() << " is a student in the school. Details below..." << endl;
			cout << sms.getStudent(studentIndex) << endl;
			cout << sms.getStudentMap(studentIndex) << endl;

			if (sms.getStudentMap(studentIndex).getSize() == 0)
				continue; //The specified student is not enrolled in any course so nothing to do

			int randomCourseMapIndex = rand() % sms.getStudentMap(studentIndex).getSize();
			int courseIndex = sms.getStudentMap(studentIndex).getKeyAtIndex(randomCourseMapIndex);
			bool flag = sms.withdrawStudent(studentIndex, courseIndex);
			if (!flag)
				cout << "Withdrawing the student at index " << studentIndex << " from the course at index " << courseIndex << " failed." << endl << endl;
			else
			{
				cout << "Student at index " << studentIndex << " withdrawn from the course at index " << courseIndex << endl;
				cout << "The updated information for the student is now..." << endl;
				cout << sms.getStudent(studentIndex) << endl;
				cout << sms.getStudentMap(studentIndex) << endl;
			}
		}
	
		//Remove a randomly chosen course from the system
		randomCourseIndex = rand() % sms.getNumberOfCoursesOffered();
		c = sms.getCourse(randomCourseIndex);
		sms.removeCourse(randomCourseIndex);
		cout << c.getCourseName() << " has been removed from the system." << endl;
		cout << "The system has been updated. Below is the updated system information..." << endl;
		cout << sms << endl;

		//Compute and print the top student
		int topStudentIndex = sms.getTopStudentIndex();
		cout << "The top student is..." << endl;
		cout << sms.getStudent(topStudentIndex) << endl;
		cout << "GPA = " << sms.getStudentGPA(topStudentIndex) << endl << endl;
	}
	
	system("Pause");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
