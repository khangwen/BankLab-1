#include "Account.h"

Account::Account(Customer customer, int accountNumber) : _accountOwner(customer), _accountNumber(accountNumber)
{		
}

Account::~Account()
{
}

void Account::Deposit(int numberOfPennies)
{
	_balanceInPennies += numberOfPennies;	
}

void Account::Withdraw(int numberOfPennies)
{
	_balanceInPennies -= numberOfPennies;

}

int Account::getBalance()
{
	return _balanceInPennies;
}

int Account::getAccountNumber()
{
	return _accountNumber;
}

std::string Account::getCustomerName()
{
	return _accountOwner.getFullName();
}

void Account::createLog(int accountNumber, int amount, std::string makeLog)
{
	if (makeLog == "deposit")
	{
		std::string output = "Deposited " + std::to_string(amount) + " pennies into Account #: " + std::to_string(accountNumber) + "\n";
		_log.push_back(output);
	}

	else if(makeLog == "withdraw")
	{
		std::string output = "Withdrew " + std::to_string(amount) + " pennies into Account # " + std::to_string(accountNumber) + "\n";
		_log.push_back(output);
	}
}

std::string Account::showLog()
{
	std::string output;
	for (std::string &log : _log)
	{
		output += log + "\n";
	}
	return output;
}
