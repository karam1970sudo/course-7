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

void PrintEachWordInString(string S1)
{
	string dliem = " ";
	cout << "\nYour string wrords are: \n\n";
	short pos;
	string Sword;
	while ((pos = S1.find(dliem)) != std::string::npos)
	{
		Sword = S1.substr(0, pos);
		if (Sword != " ")
		{
			cout << Sword << endl;
		}

		S1.erase(0, pos + dliem.length());
	}
	if (S1 != "")
	{
		cout << S1 << endl;
	}
}

int main()
{
	PrintEachWordInString(readstring());
	system("pause > 0");
}