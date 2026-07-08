#include<iostream>
#include<string>
#include<vector>
using namespace std;

string JoinString(vector <string> vStr, string dm)
{
	string S1 = "";
	for (string& str : vStr)
	{
		S1 = S1 + str + dm;
	}
	return S1.substr(0, S1.length() - dm.length());
}

string JoinString(string arr[100], short length, string dm)
{
	string S1 = "";
	for (short i = 0; i < length; i++)
	{
		S1 = S1 + arr[i] + dm;
	}
	return S1.substr(0, S1.length() + dm.length());
}

int main()
{
	string arr[] = { "Mohammed","Faid","Ali","Maher" };
	vector<string> vString = { "Mohammed","Faid","Ali","Maher" };
	cout << "\nVector after join: \n";
	cout << JoinString(vString, " ");
	cout << "\nArry after join: \n";
	cout << JoinString(arr,4," ");
	system("pause>0");
}