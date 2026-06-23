#include<iostream>
#include<iomanip>
using namespace std;
int randomnumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}
void fillmatraix(int arr[3][3],short rows , short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = randomnumber(1, 100);
		}
	}
}

void printmatraix(int arr[3][3],short rows,short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout <<setw(3)<< arr[i][j] << "   ";
		}
		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	fillmatraix(arr,3,3);
	cout << "Matrix 3*3 : " << endl;
	printmatraix(arr,3,3);
	return 0;
}