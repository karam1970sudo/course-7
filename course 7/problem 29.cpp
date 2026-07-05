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

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
short CountLetters(string S1, enWhatToCount WhatCount)
{
	if (WhatCount == enWhatToCount::All)
	{
		return S1.length();
	}

	short counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (WhatCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
		{
			counter++;
		}

		if (WhatCount == enWhatToCount::SmallLetters && islower(S1[i]))
		{
			counter++;
		}

	} 
	return counter;
}

short CountCapitalLetters(string S1)
{
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
			Counter++;
	}
	return Counter;
}
short CountSmallLetters(string S1)
{
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
			Counter++;
	}
	return Counter;
}

int main()
{
	string S1 = readstring();
	cout << "\nString Length = " << S1.length();
	cout << "\nCapital Letters Count= " <<
		CountCapitalLetters(S1);
	cout << "\nSmall Letters Count= " << CountSmallLetters(S1);
	cout << "\n\nMethod 2\n";
	cout << "\nString Length = " << CountLetters(S1,enWhatToCount::All);
	cout << "\nCapital Letters Count= " << CountLetters(S1,
		enWhatToCount::CapitalLetters);
	cout << "\nSmall Letters Count= " <<
		CountLetters(S1, enWhatToCount::SmallLetters);
	system("pause>0");
}