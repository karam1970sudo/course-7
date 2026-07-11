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
	double accountBalance;
};

stClient ReadNewclientData()
{
	stClient data;
	cout << "Enter Account Number : ";
	getline(cin, data.AccountNumber);
	cout << "\nEnter pincode :";
	getline(cin, data.PinCode);
	cout << "\nEnter Name : ";
	getline(cin, data.Name);
	cout << "\nEnter Phone : ";
	getline(cin,data.Phone);
	cout << "\nEnter Account Balance : ";
	cin >> data.accountBalance;
	return data;
}

string ConvertRecordToLine(stClient data, string separator = "#//#")
{
	string stClientRecord = "";
	stClientRecord += data.AccountNumber + separator;
	stClientRecord += data.PinCode + separator;
	stClientRecord += data.Name + separator;
	stClientRecord += data.Phone + separator;
	stClientRecord += to_string(data.accountBalance);
	return stClientRecord;
}

int main()
{
	cout << "\nPlease enter Client Data:\n\n";
	stClient Client = ReadNewclientData();
	cout << "\n\nClient Record for Saving is: \n";
	cout << ConvertRecordToLine(Client);
	system("pause>0");
	return 0;
}