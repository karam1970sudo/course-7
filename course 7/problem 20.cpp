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

bool plendromnumber(int Matrix[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols/2; j++)
		{
			if (Matrix[i][j] != Matrix[i][cols - j - 1])
				return false;
		}
	}
	return true;
}

int main()
{
	int Matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
	cout << "\nMatrix1:\n";
	printmataix(Matrix1, 3, 3);
	if (plendromnumber(Matrix1, 3, 3))
	{
		cout << "\nYes: Matrix is Palindrome\n";
	}
	else
		cout << "\nNo: Matrix is NOT Palindrome\n";
	system("pause>0");
}