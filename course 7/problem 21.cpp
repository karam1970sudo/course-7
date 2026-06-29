#include<iostream>
using namespace std;
void PrintFibonacciUsingLoop(short Number)
{
	int v1 = 1, v2 = 0 ,FibNumber = 0;
	cout << 1 << "  ";
	for (short i = 2; i <= Number; i++)
	{
		FibNumber = v2 + v1;
		cout << FibNumber<<"  ";
		v2 = v1;
		v1 = FibNumber;
	}
}

int main()
{
	PrintFibonacciUsingLoop(10);
}