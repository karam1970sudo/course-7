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

void Mul2Matraix(int arr1[3][3], int arr2[3][3], int mularr[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			mularr[i][j] = arr1[i][j] * arr2[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr1[3][3], arr2[3][3], mularr[3][3];
	fillmatrix(arr1, 3, 3);
	fillmatrix(arr2, 3, 3);
	cout << "Matrix 1: " << endl;
	printmataix(arr1, 3, 3);
	cout << "Matraix 2: " << endl;
	printmataix(arr2, 3, 3);
	Mul2Matraix(arr1, arr2, mularr, 3, 3);
	cout << "Mul matraix :" << endl;
	printmataix(mularr, 3, 3);
	cin.get();
}