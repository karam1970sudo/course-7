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

bool IsVowel(char letter)
{
	letter = tolower(letter);
	return ((letter == 'a') || (letter == 'o') || (letter == 'e') || (letter == 'i') || (letter == 'u'));
}

void printVowels(string S1)
{
	short counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
		{
			cout << S1[i] << "  ";
		}
	}
	
}

int main()
{
	string S = readstring();
	cout << "Number is vowels is :";
	printVowels(S);
	system("pause > 0");
}