#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct NiceArray
{
float *arr; //pointer for a dynamic memory on the heap
int size; //size of the array
};
string toString(const NiceArray &A)
{
stringstream ss;
ss << "[";
for (int i = 0; i < A.size - 1; i++)
ss << A.arr[i] << ", ";
if (A.size > 0)
ss << A.arr[A.size-1];
ss << "]";
return ss.str();
}
int main()
{
//Create and print a NiceArray object A1
NiceArray A1;
A1.size = 0; //size is zero. Therefore no memory needs to be allocated on the heap
cout << "The array A1 is " << toString(A1) << endl;
//Create and print a NiceArray object A2
NiceArray A2;
A2.size = 3;
A2.arr = new float[A2.size];
for (int i = 0; i < A2.size; i++)
A2.arr[i] = i+1;
cout << "The array A2 is " << toString(A2) << endl;
//Assign A1 the value of A2
A1 = A2;
//Now print both A1 and A2
cout << "After assigning A2 to A1, the NiceArray A1 is " << toString(A1) << endl;
cout << "After assigning A2 to A1, the NiceArray A2 is " << toString(A2) << endl;
//Modify some elements of A1
A1.arr[0] = 5;
A1.arr[2] = 6;
//Modify some elements of A2
A2.arr[1] = -4;
//Now print both A1 and A2
cout << "After modifying some elements of A1 and A2, the NiceArray A1 is " << toString(A1) << endl;
cout << "After modifying some elements of A1 and A2, the NiceArray A2 is " << toString(A2) << endl;
//Delete all the dynamically allocated memories
delete[] A1.arr;
//delete[] A2.arr; //Commented because this will create a run-time error. Explain.
system("Pause");
return 0;
}