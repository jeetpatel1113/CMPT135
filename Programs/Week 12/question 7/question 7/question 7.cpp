#include <iostream>
#include <string>
using namespace std;
bool checkSubString (const string& str, const string& sub)
{
	if (str.length() < sub.length())
		return false;
	if (str == sub)
		return true;
	else
	{
		string a;
		for (int i = 1 ; i < str.length() ; i++)
		{
			a = a + str[i];
		}
		checkSubString(a, sub);
	}
}


int main()
{
	string S = "International";
	cout << checkSubString (S, "national") << endl;
	system ("Pause");
	return 0;
}