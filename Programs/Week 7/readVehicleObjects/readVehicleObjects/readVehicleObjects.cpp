#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
struct Vehicle
{
	string make;
	int year;
	double hp;
};
vector<Vehicle> readVehicleInventory(const string &s)
{
	ifstream fin(s);
	if (fin.fail())
		cout << "Input file failed. Bye..." << endl;
	else
	{
		string make;
		int year;
		double hp;
		int size = 0;
		while (!fin.eof())
		{
			fin >> make >> year >> hp;
			size++;
		}
		fin.close();

		vector<Vehicle> A(size - 1);
		fin.open(s);
		for (int i = 0 ; i < size - 1 ; i++)
		{
			fin >> A[i].make >> A[i].year >> A[i].hp;
		}
		fin.close();
		return A;
	}
}
void printVehicleInventory(const vector<Vehicle> &V)
{
	for (int i = 0 ; i < V.size() ; i++)
		cout << V[i].make << '\t' << V[i].year << '\t' << V[i].hp << endl;
}

void reOrderObjects(vector<Vehicle> &V)
{
	Vehicle temp;
	vector<Vehicle> ans;
	
	for (int i = 0 ; i < V.size() ; i++)
	{
		if (isFound(ans, V[i]))
			i++;
		else
		{
			temp = V[i];
			for (int j = 0 ; j < V.size() ; j++)
			{
				if (V[j].make == temp.make)	
					ans.push_back(V[j]);
			}
		}
	}
	V = ans;

}

bool isFound(const vector<Vehicle> &V, const Vehicle &s)
{
	for (int i = 0 ; i < V.size() ; i++)
		if (V[i].make == s.make)
			return i;
	return -1;
}


int main()
{
	string s;
	cout << "Please enter the pathway with / between the interval : " << endl;
	cin >> s; //F:/FIC/Cmpt135/Programs/Week 7/readVehicleObjects/readVehicleObjects/readVehicleInvectory.txt
	s = "F:/FIC/Cmpt135/Programs/Week 7/readVehicleObjects/readVehicleObjects/readVehicleInvectory.txt";
	vector<Vehicle> V = readVehicleInventory(s);
	printVehicleInventory(V);
	reOrderObjects(V);
	printVehicleInventory(V);
	system("Pause");
	return 0;
}