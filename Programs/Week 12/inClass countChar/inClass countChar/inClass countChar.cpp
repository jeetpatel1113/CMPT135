#include <iostream>
#include <string>
using namespace std;
int countChar(string s, char ch)
{
	if (s.length() == 0)
		return 0;
	else
	{
		string temp;
		for (int i = 1 ; i < s.length() ; i++)
			temp += s[i];
		if (s[0] == ch)
			return 1 + countChar(temp, ch);
		else
			return countChar(temp, ch);
	}
}
int countChar(const string& s, const char& ch, const int& startindex, const int& lastindex)
{
	if (startindex > lastindex)
		return 0;
	else
	{
		if (s[startindex] == ch)
			return 1 + countChar(s, ch, startindex + 1, lastindex);
		else
			return countChar(s, ch, startindex + 1, lastindex);
	}
}

int main()
{
	string x = "international";
	cout << x << endl;
	cout << countChar(x, 'n', 0, x.length() - 1) << endl;
	
	system("Pause");
	return 0;
}