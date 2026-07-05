#include<iostream>
#include<string>
using namespace std;

string readstring()
{
	string s;
	cout << "please enter the text ?" << endl;
	getline(cin, s);
	return s;
}

string UpperAll(string S1)
{
	bool checkfirst = true;

	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && checkfirst)
		{
			S1[i] = toupper(S1[i]);
		}
		checkfirst = (S1[i] == ' ' ? true : false);
	}
	return S1;
}

int main()
{
	string S1 = readstring();
	cout << "\nString after conversion:\n";
	S1 = UpperAll(S1);
	cout << S1 << endl;
	system("pause > 0");
}