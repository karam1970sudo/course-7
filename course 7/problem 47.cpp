#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
const string FileName = "Client Data.txt";

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
	cout << "Enter Account Number ?";
	getline(cin >> ws, Client.AccountNumber);
	cout << "Enter Pincode ?";
	getline(cin, Client.PinCode);
	cout << "Enter Name ?";
	getline(cin, Client.Name);
	cout << "Enter Phone ?";
	getline(cin, Client.Phone);
	cout << "Enter Account Balance ?";
	cin >> Client.AccountBalance;
	return Client;
}

string ConvertRecordToLine(sClient Client, string Seprator = "#//#")
{
	string Line;
	Line += Client.AccountNumber + Seprator;
	Line += Client.PinCode + Seprator;
	Line += Client.Name + Seprator;
	Line += Client.Phone + Seprator;
	Line += to_string(Client.AccountBalance);
	return Line;
}

void AddLineToFile(string Line, string FileName)
{
	fstream myFile;
	myFile.open(FileName, ios::out | ios::app);
	if (myFile.is_open())
	{
		myFile << Line << endl;
	}
	myFile.close();
}

void AddClient()
{
	
	string Line = ConvertRecordToLine(RaedDataClient());
	AddLineToFile(Line, FileName);
}

void AddClients()
{
	char AddMore = 'Y';
	do
	{
		cout << "Adding New Client\n\n";
		cout << "\a";
		system("cls");
		AddClient();
		cout << "\n\nClient Add successfly, Do you want to Add more client ? Y/N : ";
		cin >> AddMore;
	} while (AddMore == toupper('Y'));
}

int main()
{
	AddClients();
	system("pause > 0");
	return 0;
}