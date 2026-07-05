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

char readchar()
{
	char ch;
	cout << "please enter the letter ?" << endl;
	cin >> ch;
	return ch;
}

short count_letters(string S1,char letter)
{
	short counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i]==letter) {
			counter++;
		}
	}
	return counter;
}

int main()
{
	string S1 = readstring();
	char CH1 = readchar();
	cout << "Letter ' " << CH1 << " ' count = " << count_letters(S1, CH1);
	system("pause > 0");
}