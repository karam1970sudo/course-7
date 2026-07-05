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

char InvertLetterCase(char ch)
{
	return (isupper(ch) ? tolower(ch) : toupper(ch));
}

int main()
{
	char ch = readchar();
	cout << InvertLetterCase(ch) << endl;
	system("pause > 0");
}