#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};


vector <string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord;
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}

stClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	vector <string> vString = SplitString(Line, Seperator);
	stClient Client;
	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stod(vString[4]);
	return Client;
}

void PrintClientRecord(stClient Client)
{
	cout << "\n\nThe following is the extracted client record:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}
int main()
{
	string stLine = "A300#//#1234#//#Mohammed karam hayek#//#0909090909#//#5270.000000";
		cout << "\nLine Record is:\n";
	cout << stLine;
	stClient Client = ConvertLinetoRecord(stLine);
	PrintClientRecord(Client);
	system("pause>0");
	return 0;
}