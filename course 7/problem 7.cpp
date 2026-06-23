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

void transposd(int arr[3][3],int arrt[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arrt[j][i] = arr[i][j];
		}
		
	}
}

int main()
{
	int arr[3][3];
	int arrt[3][3];
	FillMatrix(arr, 3, 3);
	cout << "\nThe following is a 3x3 ordered matrix:\n";
	PrintMatrix(arr, 3, 3);
	transposd(arr, arrt, 3, 3);
	cout << "\n\nThe following is the transposed matrix:\n";	
	PrintMatrix(arrt, 3, 3);
}