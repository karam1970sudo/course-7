#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const string FileName = "DataFile.txt";

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

stClient ReadNewclientData()
{
	stClient data;
	cout << "Enter Account Number : ";
	getline(cin >> ws, data.AccountNumber);
	cout << "\nEnter pincode :";
	getline(cin, data.PinCode);
	cout << "\nEnter Name : ";
	getline(cin, data.Name);
	cout << "\nEnter Phone : ";
	getline(cin, data.Phone);
	cout << "\nEnter Account Balance : ";
	cin >> data.AccountBalance;
	return data;
}

string ConvertRecordToLine(stClient data, string separator = "#//#")
{
	string stClientRecord = "";
	stClientRecord += data.AccountNumber + separator;
	stClientRecord += data.PinCode + separator;
	stClientRecord += data.Name + separator;
	stClientRecord += data.Phone + separator;
	stClientRecord += to_string(data.AccountBalance);
	return stClientRecord;
}

void AddLineToFile(string NameFile,string Line)
{
	fstream FileData;
	FileData.open(NameFile, ios::out | ios::app);
	if (FileData.is_open())
	{
		FileData << Line << endl;
	}
	FileData.close();
}

void AddNewClient()
{
	stClient Client;
	Client = ReadNewclientData();
	AddLineToFile(FileName, ConvertRecordToLine(Client));
}

void AddClients()
{
	char AddMore = 'Y';
	do
	{
		system("cls");
		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
			cin >> AddMore;
	} while (toupper(AddMore)=='Y');
}

int main()
{
		
	AddClients();
	system("pause>0");
	return 0;
}