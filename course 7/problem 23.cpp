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

void printFirstLetterOfEachWord(string s)
{
	bool checkfirst = true;
	cout << "\nFirst letters of this string: \n";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ' && checkfirst == true)
		{
			cout << s[i] << endl;
		}

		checkfirst = (s[i] == ' ' ? true : false);
	}
}
	
int main()
{
	printFirstLetterOfEachWord(readstring());
}
	
