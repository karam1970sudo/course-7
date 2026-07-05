#include <string>
#include <iostream>
using namespace std;
string ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}

string UpperAll(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = toupper(S1[i]);
	}
	return S1;
}

string LowerAll(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}

int main()
{
	string S1 = ReadString();
	S1 = UpperAll(S1);
	cout << "\nString after Upper:\n";
	cout << S1 << endl;
	S1 = LowerAll(S1);
	cout << "\nString after Lower:\n";
	cout << S1 << endl;
}