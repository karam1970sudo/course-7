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

void printmataix(int arr[3][3], short rows, short cols)
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

int ColSum(int arr[3][3], int rows, int cols)
{
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		sum += arr[i][cols];
	}
	return sum;
}

void printsumcolos(int arr[3][3], int rows, int cols)
{
	cout << "\nThe the following are the sum of each row in the matrix : \n";
	for (int i = 0; i < cols; i++)
	{
		cout << "colo " << i + 1 << "sum = " << ColSum(arr, rows, i) << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	fillmatrix(arr, 3, 3);
	cout << "The following is a 3 * 3 random matraix :" << endl;
	printmataix(arr, 3, 3);
	printsumcolos(arr, 3, 3);
}