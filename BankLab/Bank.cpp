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
		output += std::to_string(account.getAccountNumber()) + " - " + account.getCustomerName() + " - " + std::to_string(account.getBalance()) + "\n";
	}
	return output;
}

std::string Bank::ListAccounts()
{
	std::string output = "Accounts for " + _name + "\n";
	for (Account account : _accounts)
	{
		output += std::to_string(account.getAccountNumber()) += "\n";
	}
	return output;
}

std::string Bank::getLog(int accountNumber)
{
	for (Account &account : _accounts) {
		if (account.getAccountNumber() == accountNumber) {
			return account.showLog();
		}
	}
}

void Bank::Deposit(int accountNumber, int amount)
{
	for (Account &account : _accounts) {
		if (account.getAccountNumber() == accountNumber) {
			std::string makeLog = "deposit";
			account.Deposit(amount);
			account.createLog(accountNumber, amount, makeLog);
			return;
		}
	}
	return;
}

void Bank::Withdraw(int accountNumber, int amount, bool &error)
{
	for (Account &account : _accounts) {
		if (account.getAccountNumber() == accountNumber) {
			std::string makeLog = "withdraw";
			if (account.getBalance() >= amount)
			{
				account.Withdraw(amount);
				account.createLog(accountNumber, amount, makeLog);
				return;
			}
			else
			{
				error = true;
				return;
			}
		}
	}
	return;
}




