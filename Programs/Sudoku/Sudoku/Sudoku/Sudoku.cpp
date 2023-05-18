#include <iostream>
using namespace std;
void fillSudokuBoard(int **sudoku, const int& n)
{
}

int main()
{
	const int n = 9;
	int **sudoku = new int*[n];
	for (int i = 0; i < n; i++)
		sudoku[i] = new int[n];
	fillSudokuBoard(sudoku, n);
	cout << "An example an nxn sudoku board such that" << endl;
	cout << "\tEach row contains the integers 1,2,3,...,n" << endl;
	cout << "\tEach column contains the integers 1,2,3,...,n" << endl;
	cout << "is the following" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << sudoku[i][j] << " ";
		cout << endl;
	}

	for (int i = 0 ; i < n ; i++)
		delete[] sudoku[i];
	delete[] sudoku;
	system("Pause");
	return 0;
}