#include<iostream>
#include<string>
#include<vector>
using namespace std;

string JoinString(vector <string> vStr, string dm)
{
	string S1 = "";
	for (string str : vStr)
	{
		S1 = S1 + str + dm;
	}
	return S1.substr(0, S1.length() - dm.length());
}

int main()
{
	vector<string> vString = { "Mohammed","Faid","Ali","Maher" };
	cout << "\nVector after join: \n";
	cout << JoinString(vString, "###");
	system("pause>0");
}