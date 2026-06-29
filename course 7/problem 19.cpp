#include<iostream>
#include<iomanip>
using namespace std;
int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void fillmatrix(int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void printmataix(int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0;j < cols;j++)
		{
			printf("%0*d   ", 2, arr[i][j]);
			//cout << setw(3) << arr[i][j] << "   ";
		}
		cout << endl;
	}
}

int maxnumberinmatrix(int mat[3][3], int rows, int cols)
{
	int max = mat[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (mat[i][j] > max)
				max = mat[i][j];
		}
	}

	return max;
}

int minnumberinmatrix(int mat[3][3], int rows, int cols)
{
	int min = mat[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (mat[i][j] < min)
				min = mat[i][j];
		}
	}
	return min;
}

int main()
{
	srand((unsigned)time(NULL));

	int mat[3][3];
	fillmatrix(mat, 3, 3);
	cout << "Matrix 1: " << endl;
	printmataix(mat, 3, 3);

	cout << "\nMinimum Number is: ";
	cout << minnumberinmatrix(mat, 3, 3);
	cout << "\n\nMax Number is: ";
	cout << maxnumberinmatrix(mat, 3, 3);
	system("pause>0");
}