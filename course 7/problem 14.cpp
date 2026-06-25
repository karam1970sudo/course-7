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

bool checkscalarmatrix(int mat[3][3], int rows, int cols)
{
	int firstdiagonal = mat[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j && mat[i][j]!=firstdiagonal)
			{
				return false;
			}
			else if (i != j && mat[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int mat1[3][3];
	int mat2[3][3] = { {9,0,0},{0,9,0},{0,0,9} }; //Matrix test
	fillmatrix(mat1, 3, 3);
	cout << "Matrix 1: " << endl;
	printmataix(mat1, 3, 3);


	if (checkscalarmatrix(mat2,3,3))
	{
		cout << "Matrix is scalar" << endl;
	}
	else
	{
		cout << "Matrix is not scalar" << endl;
	}
}