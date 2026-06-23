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

void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols)
{
	int middlerow = Rows / 2;
	for (int i = 0; i < Cols; i++)
	{
		printf(" %0*d ", 2, arr[middlerow][i]);
	}
	cout << endl;
}

void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols)
{
	short MiddleCol = Cols / 2;
	for (short j = 0; j < Rows; j++)
	{
		printf(" %0*d ", 2, arr[j][MiddleCol]);
	}
	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	fillmatrix(arr, 3, 3);
	cout << "matraix :" << endl;
	printmataix(arr, 3, 3);
	cout << "\nMiddle Row of Matrix1 is:\n";
	PrintMiddleRowOfMatrix(arr, 3, 3);
	cout << "\nMiddle Col of Matrix1 is:\n";
	PrintMiddleColOfMatrix(arr, 3, 3);
	system("pause>0");
}