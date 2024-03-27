#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <new>
#include <cstring>

using namespace std;

class account {
private:
	string	name;
	double	balance;
	int		account_id;

public:

	account(string n, double b, int ac):
		name(n), balance(b), account_id(ac)
	{}
	// Geters
	int		get_balance()
	{
		return balance;
	}
	int		get_acc_num()
	{
		return account_id;
	}

	// Operations
	void	deposit(double val)
	{
		if (val < 0)
		{
			cout << "Error can't deposit negative value" << '\n';
			return ;
		}
		else
			balance += val;
	}
	void	withdraw(double val)
	{
		if (val < 0)
		{
			cout << "Error can't withdraw negative value" << '\n';
			return ;
		}
		else if (val > balance)
		{
            cout << "Error: Insufficient funds.\n";
            return;
        }
		else
			balance -= val;
	}

};

class System {
private:
	vector<account> accounts;
	int				index;

public:
	System(): index(100){}

	// geters
	void	create_account(const string name, double init_deposite)
	{
		account new_accout(name, init_deposite, index);
		accounts.push_back(new_accout);
		index++;
		cout << "Account created for Mr: " << name << '\n';
		cout << "Your account number is: " << new_accout.get_acc_num() << '\n';
	}
	void	print_balance(int account_number)
	{
		for (auto &acc : accounts)
		{
        	if (acc.get_acc_num() == account_number)
			{
            	cout << "Balance for account " << account_number << ": ";
				cout << acc.get_balance() << "DH" << '\n';
            	return;
        	}
    	}
    	cout << "Account number " << account_number << " not found.\n";
	}
	void	withdraw(int amount, int account_number)
	{
		for (auto &acc : accounts)
		{
        	if (acc.get_acc_num() == account_number)
			{
            	acc.withdraw(amount);
				cout << "Withraw with success" << '\n';
            	return;
        	}
    	}
    	cout << "Account number " << account_number << " not found.\n";
	}
	void	deposit(int amount, int account_number)
	{
		for (auto &acc : accounts)
		{
        	if (acc.get_acc_num() == account_number)
			{
            	acc.deposit(amount);
				cout << "Withraw with success" << '\n';
            	return;
        	}
    	}
    	cout << "Account number " << account_number << " not found.\n";
	}
};
