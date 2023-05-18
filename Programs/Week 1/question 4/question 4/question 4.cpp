#include <iostream>
#include <cmath>
using namespace std;
struct Date
{
	int day;
	int month;
	int year;
};
int getDays(Date date1, Date date2)
{
	return (date1.day - date2.day) + (date1.month - date2.month) * 30 + (date1.year - date2.year) * 360;
}	
int getDaysBetween(Date date1, Date date2)
{
	return abs(date1.day + date1.month * 30 + date1.year * 360 - (date2.day + date2.month * 30 + date2.year * 360));
}
Date getDateBetween(Date date1, Date date2)
{
	Date d;
	if (date1.year >= date2.year)
	{
		d.year = date1.year - date2.year;
		if (date1.month >= date2.month)
		{
			d.month = date1.month - date2.month;
		}
		else
		{
			d.month = date2.month - date1.month;
			d.year--;
		}
		if (date1.day >= date2.day)
		{
			d.day = date1.day - date2.day;
		}
		else
		{
			d.day = date2.day - date1.day;
			d.month--;
		}
	}
	else
	{
		d.year = date2.year - date1.year;	
		if (date2.month <= date1.month)
		{
			d.month = date2.month - date1.month;
		}
		else
		{
			d.month = date1.month - date2.month;
			d.year--;
		}
		if (date2.day >= date1.day)
		{
			d.day = date2.day - date1.day;
		}
		else
		{
			d.day = date1.day - date2.day;
			d.month--;
		}
	}
	return d;
}

int main()
{
	//Create two Date objects
	Date d1, d2;
	//Read input values for d1 and d2. Assume user inputs are valid inputs
	cout << "Please enter the day, month and year of the first Date ";
	cin >> d1.day >> d1.month >> d1.year;
	cout << "Please enter the day, month and year of the second Date ";
	cin >> d2.day >> d2.month >> d2.year;
	//Compute the number of days from d1 to d2. The result can be negative, positive or zero
	int diff1 = getDays(d1, d2);
	cout << "There are " << diff1 << " days from d1 to d2." << endl;
	//Compute the number of days between the two Dates. The result must be non-negative integer
	int diff2 = getDaysBetween(d1, d2);
	cout << "There are " << diff2 << " days between the two dates." << endl;
	//Compute the number of days, month and years between the two Dates. 
	//The result must contain a day in the range [0, 29], month in the range [0, 11] and 
	//any non negative integer for the year
	Date diff3 = getDateBetween(d1, d2);
	cout << "There are " << diff3.day << " days, " << diff3.month << " months, and " << diff3.year << " years between the two dates" << endl;
	system("Pause");
	return 0;
}