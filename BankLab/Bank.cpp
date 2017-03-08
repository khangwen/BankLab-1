#include "Bank.h"

Bank::Bank(std::string name) : _name(name)
{	
}

Bank::~Bank()
{
}

std::string Bank::getName()
{
	return _name;
}

void Bank::CreateAccount(Account newAccount)
{
	_accounts.push_back(newAccount);
}

std::string Bank::ShowAccounts()
{
	std::string output = "Accounts for " + _name + "\n";
	for (Account account : _accounts)
	{		
		//TODO: Display as Account Number - LastName, FirstName - Balance
		output += std::to_string(account.getAccountNumber()) + " - " + account.getCustomerName() + " - " + std::to_string(account.getBalance()) + "\n";
	}
	return output;
}

std::string Bank::ListAccounts()
{
	std::string output = "Accounts for " + _name + "\n";
	int index = 1;
	for (Account account : _accounts)
	{
		output += std::to_string(index) + ") " + std::to_string(account.getAccountNumber()) += "\n";
		index++;
	}
	return output;
}

// Bank.deposit(int accNum, amt, _accounts)

void Bank::Deposit(int accountNumber, int amount)
{

	/*for (int i = 0; i < _accounts.size(); i++)
	{

		if (_accounts[i].getAccountNumber)
			_accounts.deposit(amount);
	}*/

	for (Account &account : _accounts) {
		if (account.getAccountNumber() == accountNumber) {
			account.Deposit(amount);
			return;
		}
	}
	return;
}

void Bank::Withdraw(int accountNumber, int amount)
{
	for (Account &account : _accounts) {
		if (account.getAccountNumber() == accountNumber) {
			account.Withdraw(amount);
			return;
		}
	}
	return;
}


