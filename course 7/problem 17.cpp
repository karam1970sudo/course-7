#include<iostream>
#include<iomanip>
using namespace std;
int readpostivenumber(string massege)
{
	int number = 0;
	do
	{
		cout << massege << endl;
		cin >> number;
	} while (number < 0);
	return number;
}
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
		for (short j = 0; j< cols; j++)
		{
			if(mat[i][j]==number)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	srand((unsigned)time(NULL));

	int mat[3][3];
	fillmatrix(mat, 3, 3);
	cout << "Matrix 1: " << endl;
	printmataix(mat, 3, 3);
	int number = readpostivenumber("\nPlease Enter the number to look for in matrix? ");

	if (checktherenmber(mat, number, 3, 3))
		cout <<  "\nYes it is there.\n" << endl;
	else
		cout << "\nNo: It's NOT there.\n";
}