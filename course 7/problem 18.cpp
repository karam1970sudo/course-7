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

bool checktherenmber(int mat[3][3], int number, int rows, int cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			if (mat[i][j] == number)
			{
				return true;
			}
		}
	}
	return false;
}

void CheckTwoNumbersMatch(int mat1[3][3], int mat2[3][3], int rows, int cols)
{
	int number;
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			number = mat1[i][j];
			if (checktherenmber(mat2,number,3,3))
			{
				cout << setw(3) << number << "  ";
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int mat1[3][3], mat2[3][3];
	fillmatrix(mat1, 3, 3);
	cout << "Matrix 1: " << endl;
	printmataix(mat1, 3, 3);

	fillmatrix(mat2, 3, 3);
	cout << "Matrix 2: " << endl;
	printmataix(mat2, 3, 3);

	cout << "intersected number are : " << endl;
	CheckTwoNumbersMatch(mat1, mat2, 3, 3);

}