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
int summatrix(int arr[3][3],int rows,int cols)
{
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	fillmatrix(arr, 3, 3);
	cout << "matraix :" << endl;
	printmataix(arr, 3, 3);
	cout << "sum is matrix : " << summatrix(arr, 3, 3) << endl;
}