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

char InvertLetterCase(char ch)
{
	return (isupper(ch) ? tolower(ch) : toupper(ch));
}


string InvertAllStringLettersCase(string S)
{
	for (short i = 0; i < S.length(); i++)
	{
		S[i] = InvertLetterCase(S[i]);
	}
	return S;
}

int main()
{
	string S = readstring();
	cout << "\nString after Inverting All Letters Case:\n";
	S = InvertAllStringLettersCase(S);
	cout << S << endl;
}