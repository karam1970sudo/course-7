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

short CountVowel(string S1)
{
	short counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	string S = readstring();
	cout << "Number is vowels is :" << CountVowel(S);
	system("pause > 0");
}