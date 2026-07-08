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

short PrintEachWordInString(string S1)
{
	string dliem = " ";
	short pos;
	string Sword;
	short counter = 0;
	while ((pos = S1.find(dliem)) != std::string::npos)
	{
		Sword = S1.substr(0, pos);
		if (Sword != " ")
		{
			counter++;
		}
		S1.erase(0, pos + dliem.length());
	}
	if (S1 != "")
	{
		counter++;
	}
	return counter;
}

int main()
{
	string S1 = readstring();
	cout << "\nYour number words are string : ";
	cout << PrintEachWordInString(S1);
}