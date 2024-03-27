// Project Idea: Simple Banking System
// Develop a console-based application that simulates a basic banking system.
// It will allow users to create accounts, deposit money, withdraw money,
// and check their account balances.

// Core Features:
// Account Creation: Allow users to create a bank account by providing a name,
// an initial deposit amount, and generating an account number.
// Deposit: Enable users to deposit money into their accounts.
// Withdrawal: Allow users to withdraw money from their account,
// ensuring the account balance doesn't go negative.
// Balance Inquiry: Enable users to view their current account balance.
// Transaction History: (Optional) Keep a simple log of transactions for each account.

# include "header.hpp"

char buff[100] = {0};

int main(int ac, char **av)
{
    System bank;
    cout << "Usage: CREATE=<account_name>:<initial_deposit>\n";
    cout << "       BALANCE=<account_number>\n";
    cout << "       DEPOSIT=<account_number>:<amount>\n";
    cout << "       WITHDRAW=<account_number>:<amount>\n";
    cout << "       EXIT->To exit the Program\n\n";
    
    while (1)
    {
        cout << "-> ";
        cin.getline(buff, sizeof(buff));

        if (buff[0] == '\0')
        {
            cout << "Error in input. Try again.\n";
            continue;
        }

        char *token = strtok(buff, "=:");

        if (strcmp(token, "CREATE") == 0)
        {
            char *name = strtok(NULL, "=:");
            char *amountStr = strtok(NULL, "=:");
            if (name == NULL || amountStr == NULL)
            {
                cout << "Invalid command format. Usage: CREATE=<account_name>:<initial_deposit>\n";
                continue;
            }
            double initialDeposit = atof(amountStr);
            bank.create_account(name, initialDeposit);
        }
        else if (strcmp(token, "BALANCE") == 0)
        {
            char *accountNumStr = strtok(NULL, "=:");
            if (accountNumStr == NULL)
            {
                cout << "Invalid command format. Usage: BALANCE=<account_number>\n";
                continue;
            }
            int accountNumber = atoi(accountNumStr);
            bank.print_balance(accountNumber);
        }
        else if (strcmp(token, "DEPOSIT") == 0)
        {
            char *accountNumStr = strtok(NULL, "=:");
            char *amountStr = strtok(NULL, "=:");
            if (accountNumStr == NULL || amountStr == NULL)
            {
                cout << "Invalid command format. Usage: DEPOSIT=<account_number>:<amount>\n";
                continue;
            }
            int accountNumber = atoi(accountNumStr);
            double amount = atof(amountStr);
            bank.deposit(accountNumber, amount);
        }
        else if (strcmp(token, "WITHDRAW") == 0)
        {
            char *accountNumStr = strtok(NULL, "=:");
            char *amountStr = strtok(NULL, "=:");
            if (accountNumStr == NULL || amountStr == NULL)
            {
                cout << "Invalid command format. Usage: WITHDRAW=<account_number>:<amount>\n";
                continue;
            }
            int accountNumber = atoi(accountNumStr);
            double amount = atof(amountStr);
            bank.withdraw(accountNumber, amount);
        }
        else if (strcmp(token, "EXIT") == 0)
        {
            cout << "You Exited GL\n";
            break;
        }
        else
            cout << "Invalid command. Please try again.\n";
    }
    return 0;
}

