#include<iostream>
#include<string>
using namespace std;

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

sClient RaedDataClient()
{
	sClient Client;
	cout << "\nEnter Account Number ?";
	getline(cin, Client.AccountNumber);
	cout << "\nEnter Pincode ?";
	getline(cin, Client.PinCode);
	cout << "\nEnter Name ?";
	getline(cin, Client.Name);
	cout << "\nEnter Phone ?";
	getline(cin, Client.Phone);
	cout << "\n Enter Account Balance ?";
	cin >> Client.AccountBalance;
	return Client;
}

string ConvertToLine(sClient Client, string Seprator = "#//#")
{
	string Line;
	Line += Client.AccountNumber + Seprator;
	Line += Client.PinCode + Seprator;
	Line += Client.Name + Seprator;
	Line += Client.Phone + Seprator;
	Line += to_string(Client.AccountBalance);
	return Line;
}

int main()
{
	sClient Client;
	cout << "\nPlease enter Client Data\n\n";
	Client = RaedDataClient();
	cout << "\nclient Record saving is\n";
	cout << ConvertToLine(Client);
	return 0;
}