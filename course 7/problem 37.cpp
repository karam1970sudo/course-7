#include<iostream>
#include<string>
#include<vector>
using namespace std;

string readstring()
{
	string s;
	cout << "please enter the text ?" << endl;
	getline(cin, s);
	return s;
}

vector <string> spilt(string S1, string dliem)
{
	short pos;
	string Sword;
	vector <string> S2;
	while ((pos = S1.find(dliem)) != std::string::npos)
	{
		Sword = S1.substr(0, pos);
		if (Sword != " ")
		{
			S2.push_back(Sword);
		}
		S1.erase(0, pos + dliem.length());
	}
	if (S1 != "")
	{
		S2.push_back(S1);
	}
	return S2;
}

void print(vector <string> spilt)
{
	
	for (string word : spilt)
	{
		cout << word << endl;
	}
}

int main()
{
	vector <string> S1 = spilt(readstring(), " ");
	cout << "Tokens :" << S1.size() << endl;
	for(string &S : S1)
	{
		cout << S << endl;
	}
	system("pause > 0");
}