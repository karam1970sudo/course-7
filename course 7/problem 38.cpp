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

string TrimLeft(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ') {
			return S1.substr(i, S1.length() - i);
		}
	}
	return "";
}

string TrimRight(string S1)
{
	for (short i = S1.length()- 1; i >= 0 ; i++)
	{
		if (S1[i] != ' ') {
			return S1.substr(0,i+1);
		}
	}
	return "";
}

string Trim(string S1)
{
	return TrimRight(TrimLeft(S1));
}

int main()
{
	string S1 = readstring();
	cout << "Trim Left : " << TrimLeft(S1) << endl;
	cout << "Trim Regit: " << TrimRight(S1) << endl;
	cout << "trim : " << Trim(S1) << endl;
}