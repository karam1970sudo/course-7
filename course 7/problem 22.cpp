#include<iostream>
using namespace std;
void fibfanction(int number , int v1 , int v2 )
{
	int fibnumber;
	fibnumber = v1 + v2;
	cout << fibnumber << "  ";
	v2 = v1;
	v1 = fibnumber;
	if (number > 0)
	{
		fibfanction(number - 1, v1, v2);
	}
	
}

int main()
{
	fibfanction(10, 1, 0);
}