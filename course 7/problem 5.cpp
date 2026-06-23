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
	for (int i = 0; i <= rows-1; i++)
	{
		sum += arr[i][cols];
	}
	return sum;
}

void addarry(int arr[3][3], int arrsum[3], int rows, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		arrsum[i] = ColSum(arr, rows, i);
	}
}

void printsumarry(int arr[3], int cols)
{
	cout << "\nThe the following are the sum of each row in the matrix : \n";
	for (int i = 0; i < cols; i++)
	{
		cout << "Row " << i + 1 << " sum = " << arr[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	int arrsum[3];
	fillmatrix(arr, 3, 3);
	cout << "The following is a 3 * 3 random matraix :" << endl;
	printmataix(arr, 3, 3);
	addarry(arr, arrsum, 3, 3);
	printsumarry(arrsum, 3);
	cin.get();
}