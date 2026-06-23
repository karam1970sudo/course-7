#include<iostream>
#include<iomanip>
using namespace std;

void FillMatrix(int arr[3][3], short Rows, short Cols)
{
	short counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			counter++;
			arr[i][j] = counter;
		}
	}
}


void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	int arr[3][3];
	FillMatrix(arr, 3, 3);
	PrintMatrix(arr, 3, 3);
}