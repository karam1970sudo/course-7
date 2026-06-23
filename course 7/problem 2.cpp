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
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void printmataix(int arr[3][3],short rows , short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0;j < cols;j++)
		{
			cout << setw(3) << arr[i][j] << "   ";
		}
		cout << endl;
	}
}

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
	int Sum = 0;
	for (short j = 0; j <= Cols - 1; j++)
	{
		Sum += arr[RowNumber][j];
	}
	return Sum;
}

void PrintEachRowSum(int arr[3][3], int rows, int cols)
{
	cout << "\nThe the following are the sum of each row in the matrix : \n";
	for (int i = 0; i < rows; i++)
	{
			cout << " Row " << i + 1 << " Sum = " << RowSum(arr,i,cols) << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	fillmatrix(arr, 3, 3);

	cout << "The following is a 3 * 3 random matraix :" << endl;
	printmataix(arr, 3, 3);

	PrintEachRowSum(arr, 3, 3);
	return 0;
}