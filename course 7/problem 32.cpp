#include<iostream>
#include<string>
using namespace std;

char readchar()
{
	char ch;
	cout << "please enter the letter ?" << endl;
	cin >> ch;
	return ch;
}

bool IsVowel(char letter)
{
	letter = tolower(letter);;
	return ((letter == 'a') || (letter == 'o') || (letter == 'e') || (letter == 'i') || (letter == 'u'));
}

int main()
{
	char Ch1 = readchar();
	if (IsVowel(Ch1))
	{
		cout << "Yes letter '" << Ch1 << "' is vowel" << endl;
	}
	else
	{
		cout << "No letter '" << Ch1 << "' is not vowel" << endl;
	}
	system("pause>0");
}