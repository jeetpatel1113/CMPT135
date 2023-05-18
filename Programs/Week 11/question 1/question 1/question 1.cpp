#include <iostream>
using namespace std;
template<class T1, class T2>
T1 sum_up(T1 a, T2 b)
{
	 T1 result;
	 result = a + static_cast<T1>(b);
	 return result;
}
int main()
{
	int a = 3;
	double b = 2.7;
	double answer;
	answer = sum_up(a, b);
	cout<< answer <<endl;
	answer = sum_up(b, a);
	cout<< answer <<endl;

	system("Pause");
	return 0;
}