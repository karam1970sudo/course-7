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

bool checkmatrixidentity(int mat[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j && mat[i][j]!= 1)
			{
					return false;
			}
			else if(i != j && mat[i][j] != 0)
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
	int mat2[3][3] = { {1,0,0},{0,1,0},{0,0,1} }; //Matrix test
	fillmatrix(mat1, 3, 3);
	cout << "Matrix 1: " << endl;
	printmataix(mat1, 3, 3);

	
	
	if (checkmatrixidentity(mat1,3,3))
	{
		cout << "\nMatrix is identity" << endl;
	}
	else
	{
		cout << "\nMatrix is not identity" << endl;
	}
}