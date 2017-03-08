#include <iostream>
#include "Bank.h"
using namespace std;

Bank bank = Bank("Awesome Bank");

void DisplayMenu();
void TransactMenu();
void AddAccountMenu();
void DisplayAccountsMenu();
void DisplayLogMenu();

int main()
{
	DisplayMenu();

	system("pause");
	return 0;
}

void DisplayMenu()
{
	int choice = 0;
	while(choice != 10)
	{
		system("cls");
		cout << "Welcome to " << bank.getName() << endl;
		cout << "1) Add Account" << endl;
		cout << "2) Transact" << endl;
		cout << "3) Display accounts" << endl;
		cout << "4) See logs" << endl;
		cout << "What would you like to do? " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: AddAccountMenu(); break;
		case 2: TransactMenu(); break;
		case 3: DisplayAccountsMenu(); break;
		case 4: DisplayLogMenu(); break;
		default: break;
		}
	}


}

void AddAccountMenu()
{
	system("cls");
	cout << "Customer firstname: ";
	string firstName;
	cin >> firstName;

	cout << "Customer lastname: ";
	string lastName;
	cin >> lastName;

	cout << "Account Number: ";
	int accountNumber;
	cin >> accountNumber;

	Customer customer = Customer(firstName, lastName);
	Account newAccount = Account(customer, accountNumber);
	bank.CreateAccount(newAccount);
}

void TransactMenu()
{
	//Get account
	system("cls");
	cout << "Which Account?" << endl;
	cout << bank.ListAccounts() << endl;
	
	int chosenAccount;
	cin >> chosenAccount;

	//Get the transaction type
	system("cls");
	cout << "1) Deposit" << endl;
	cout << "2) Withdraw" << endl;

	int transactionType;
	cin >> transactionType;

	//get the amount
	system("cls");
	cout << "How Many Pennies? ";
	int pennies;
	cin >> pennies;


	switch (transactionType) 
	{
	case 1: bank.Deposit(chosenAccount, pennies); 
			
			break;
	case 2: bank.Withdraw(chosenAccount, pennies); 
			
			break;
	default: break;
	}
}

void DisplayAccountsMenu()
{
	system("cls");
	cout << bank.ShowAccounts();
	system("pause");
}

void DisplayLogMenu()
{

}