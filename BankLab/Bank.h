#pragma once
#include<vector>
#include<string>
#include "Account.h"

//changes
class Bank
{
private:
	std::string _name;
	std::vector<Account> _accounts;
public:
	Bank(std::string name);
	~Bank();

	std::string getName();
	void CreateAccount(Account newAccount);
	std::string ShowAccounts();
	std::string ListAccounts();

	void Deposit(int accountNumber, int amount);
	void Withdraw(int accountNumber, int amount);
};

