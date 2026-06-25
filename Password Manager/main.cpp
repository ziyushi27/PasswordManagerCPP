#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Password.h"

using namespace std;

void showMenu()
{
	cout << "\n===== PASSWORD MANAGER =====\n";
	cout << "1. Add Account\n";
	cout << "2. View Accounts\n";
	cout << "3. Show Password\n";
	cout << "4. Delete Account\n";
	cout << "5. Exit\n";
	cout << "Choice: ";
}

void addAccount(vector<Password>& accounts)
{
	string website;
	string username;
	string password;

	cin.ignore();

	cout << "Website: ";
	getline(cin, website);

	cout << "Username: ";
	getline(cin, username);

	cout << "Password: ";
	getline(cin, password);

	accounts.push_back(
		Password(website, username, password)
	);

	cout << "\nAccount Added!\n";
}

void viewAccounts(const vector<Password>& accounts)
{
	if (accounts.empty())
	{
		cout << "No accounts saved.\n";
		return;
	}

	for (size_t i = 0; i < accounts.size(); i++)
	{
		cout << "\nAccount " << i + 1 << endl;

		cout << "Website : "
			<< accounts[i].getWebsite() << endl;

		cout << "Username: "
			<< accounts[i].getUsername() << endl;

		cout << "Password: ********" << endl;
	}
}

void showPassword(const vector<Password>& accounts)
{
	if (accounts.empty())
	{
		cout << "No accounts saved.\n";
		return;
	}

	int index;

	cout << "Enter account number: ";
	cin >> index;

	if (index >= 1 && index <= static_cast<int>(accounts.size()))
	{
		cout << "\nWebsite : "
			<< accounts[index - 1].getWebsite() << endl;

		cout << "Username: "
			<< accounts[index - 1].getUsername() << endl;

		cout << "Password: "
			<< accounts[index - 1].getPassword() << endl;
	}
	else
	{
		cout << "Invalid account number.\n";
	}
}

void deleteAccount(vector<Password>& accounts)
{
	if (accounts.empty())
	{
		cout << "No accounts saved.\n";
		return;
	}

	int index;

	cout << "Enter account number to delete: ";
	cin >> index;

	if (index >= 1 && index <= static_cast<int>(accounts.size()))
	{
		accounts.erase(accounts.begin() + index - 1);
		cout << "Account deleted.\n";
	}
	else
	{
		cout << "Invalid account number.\n";
	}
}

void saveAccounts(const vector<Password>& accounts)
{
	ofstream file("passwords.txt");

	if (!file)
	{
		cout << "Error opening file.\n";
		return;
	}

	for (const auto& account : accounts)
	{
		file << account.getWebsite()
			<< ","
			<< account.getUsername()
			<< ","
			<< account.getPassword()
			<< endl;
	}

	file.close();

	cout << "Accounts saved.\n";
}

void loadAccounts(vector<Password>& accounts)
{
	ifstream file("passwords.txt");

	if (!file)
	{
		return;
	}

	string line;

	while (getline(file, line))
	{
		string website;
		string username;
		string password;

		stringstream ss(line);

		getline(ss, website, ',');
		getline(ss, username, ',');
		getline(ss, password);

		accounts.push_back(
			Password(website, username, password)
		);
	}

	file.close();
}

int main()
{
	vector<Password> accounts;

	loadAccounts(accounts);

	int choice;

	do
	{
		showMenu();

		cin >> choice;
		switch (choice)
		{
		case 1:
			addAccount(accounts);
			break;

		case 2:
			viewAccounts(accounts);
			break;

		case 3:
			showPassword(accounts);
			break;

		case 4:
			deleteAccount(accounts);
			break;

		case 5:
			saveAccounts(accounts);
			cout << "Goodbye!\n";
			break;

		}

	} while (choice != 5);

	return 0;
}