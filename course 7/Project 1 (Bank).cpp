#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;
const string FileName = "Client Data.txt";
void ShowMenu();
struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkDelete = false;
};

enum enManuOption{ eShow = 1 , eAdd = 2 , eDelete = 3 , eEdit = 4 , eSearch = 5 , eExit = 6};

vector<string> SplitString(string S1, string Delim)
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

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector <string> vClient = SplitString(Line, Seperator);
	Client.AccountNumber = vClient[0];
	Client.PinCode = vClient[1];
	Client.Name = vClient[2];
	Client.Phone = vClient[3];
	Client.AccountBalance = stod(vClient[4]);
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

vector <sClient> LoadCleintsDataFromFile(string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string line;
		sClient Client;
		while (getline(MyFile, line))
		{
			Client = ConvertLinetoRecord(line);
			vClients.push_back(Client);
		}
	}
	MyFile.close();
	return vClients;
}

bool FindClientByAccountNumber(string AccountNumber, sClient& client, vector <sClient> vClients)
{

	for (sClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			client = C;
			return true;
		}
	}
	return false;
}

bool SearchClientWithAccountNumber(string AccountNumber)
{
	vector <sClient> vClients = LoadCleintsDataFromFile(FileName);
	for (sClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			return true;
		}
	}
	return false;
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;
}

sClient RaedDataClient()
{
	sClient Client;
	cout << "Enter Account Number ?";
	getline(cin >> ws, Client.AccountNumber);
	if (SearchClientWithAccountNumber(Client.AccountNumber))
	{
		cout << "\a";
		cout << "Client With [" << Client.AccountNumber << "] already exists, enter another Account Number ?";
		getline(cin >> ws, Client.AccountNumber);
	}
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
		AddClient();
		cout << "\n\nClient Add successfly, Do you want to Add more client ? Y/N : ";
		cin >> AddMore;
	} while (AddMore == toupper('Y'));
}

void PrintRecord(sClient Client)
{
	cout << "\n\nThe following is the extracted client record:\n";
	cout << "-----------------------------------------------";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code :     " << Client.PinCode;
	cout << "\nName :         " << Client.Name;
	cout << "\nPhone :        " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\n-----------------------------------------------\n";
}

void PrintClientRecord(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(vector <sClient> vClients)
{
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	for (sClient c : vClients)
	{
		PrintClientRecord(c);
		cout << endl;
	}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

bool MarkClientForDeleteByAccountNumber(vector <sClient>& vClients, string AccountNumber)
{
	for (sClient& c : vClients)
	{
		if (c.AccountNumber == AccountNumber)
		{
			c.MarkDelete = true;
			return true;
		}
	}
	return false;
}

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	string DataLine;
	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{
			if (C.MarkDelete == false)
			{

				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	char Answer = 'N';
	if (FindClientByAccountNumber(AccountNumber, Client, vClients))
	{
		PrintRecord(Client);
		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(vClients, AccountNumber);
			SaveCleintsDataToFile(FileName, vClients);
			vClients = LoadCleintsDataFromFile(FileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}

sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client;
	Client.AccountNumber = AccountNumber;
	cout << "\n\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;
	return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, Client, vClients))
	{
		PrintRecord(Client);
		cout << "\n\nAre you sure you want update this client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}
			SaveCleintsDataToFile(FileName, vClients);
			cout << "\n\nClient Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber
			<< ") is Not Found!";
		return false;
	}
}

void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause > 0");
	ShowMenu();
}

void ShowClientList()
{
	vector <sClient> vClients = LoadCleintsDataFromFile(FileName);
	PrintAllClientsData(vClients);
}

void ShowAddNewClient()
{
	cout << "\n--------------------------------------\n";
	cout << "\tAdd New Clients Secreen";
	cout << "\n--------------------------------------\n";
	AddClients();
}

void ShowDeleteClient()
{
	cout << "\n--------------------------------------\n";
	cout << "\tDelete Clients Secreen";
	cout << "\n--------------------------------------\n";
	vector <sClient> vClients =
		LoadCleintsDataFromFile(FileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateClientInfo()
{
	cout << "\n--------------------------------------\n";
	cout << "\tUpdate Clients info Secreen";
	cout << "\n--------------------------------------\n";
	vector <sClient> vClients = LoadCleintsDataFromFile(FileName);
	string AccountNumber = ReadClientAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindClient()
{
	cout << "\n--------------------------------------\n";
	cout << "\tFind Clients Secreen";
	cout << "\n--------------------------------------\n";
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();
	vector <sClient> vClients = LoadCleintsDataFromFile(FileName);
	if (FindClientByAccountNumber(AccountNumber, Client,vClients))
	{
		PrintRecord(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
	}
}

short ReadMenuChoice(short From, short To)
{
	short Choice = 0;
	do
	{
		cout << "Choose what do you want to do? [1 to 6]: ";
		cin >> Choice;
	} while (Choice < From || Choice > To);
	return Choice;
}

void ShowExitSecreen()
{
	cout << "\n--------------------------------------\n";
	cout << "\tEnd Program :-)\n";
	cout << "\tDev.Mohammed Karam Hayek\n";
	cout << "\tTecher : Dr.Mohammed Abo-Hadhoud";
	cout << "\n--------------------------------------\n";
}

void PerformMainMenuOption(enManuOption Option)
{
	switch (Option)
	{
	case enManuOption::eShow:
	{
		system("cls");
		ShowClientList();
		GoBackToMainMenu();
		break;
	}
	case enManuOption::eAdd:
	{
		system("cls");
		ShowAddNewClient();
		GoBackToMainMenu();
		break;
	}
	case enManuOption::eDelete:
	{
		system("cls");
		ShowDeleteClient();
		GoBackToMainMenu();
		break;
	}
	case enManuOption::eEdit:
	{
		system("cls");
		ShowUpdateClientInfo();
		GoBackToMainMenu();
		break;
	}
	case enManuOption::eSearch:
	{
		system("cls");
		ShowFindClient();
		GoBackToMainMenu();
		break;
	}
	case enManuOption::eExit:
	{
		system("cls");
		ShowExitSecreen();
		system("pause");
		break;
	}
	}
}

void ShowMenu()
{
	system("cls");
	cout << "=========================================\n";
	cout << "\tMain Menue Secreen\n";
	cout << "=========================================\n";
	cout << "\t[1] Show Client List\n";
	cout << "\t[2] Add New Client\n";
	cout << "\t[3] Delete Client\n";
	cout << "\t[4] Update Client info\n";
	cout << "\t[5] Find Client\n";
	cout << "\t[6] Exit\n";
	cout << "=========================================\n";
	PerformMainMenuOption((enManuOption)ReadMenuChoice(1, 6));
}



int main()
{
	ShowMenu();
	return 0;
}