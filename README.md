# BankSystem
A Program written in cpp that manages bank account and let you do basic (Operations) transaction...

+ This program simulates a basic banking system where users can create accounts,
check balances, deposit funds, and withdraw funds via a command-line interface.

### Usage
Compilation: Compile the program using a C++ compiler. For example:

```sh
make
```

- Execution: Run the compiled program:

```bash
./banksys
```
+ Commands:

- CREATE=<account_name>:<initial_deposit>: Creates a new account with the specified name and initial deposit amount.
- BALANCE=<account_number>: Displays the balance for the account with the specified account number.
- DEPOSIT=<account_number>:<amount>: Deposits the specified amount into the account with the specified account number.
- WITHDRAW=<account_number>:<amount>: Withdraws the specified amount from the account with the specified account number.
- EXIT: Exits the program.
+Example usage:

```bash
-> CREATE=John_Doe:1000
Account created for: John_Doe
Your account number is: 100
-> BALANCE=100
Balance for account 100: 1000
-> DEPOSIT=100:500
-> BALANCE=100
Balance for account 100: 1500
-> WITHDRAW=100:200
-> BALANCE=100
Balance for account 100: 1300
-> EXIT
```
### Notes
- The program handles user inputs and provides feedback accordingly.
If an input is invalid or incorrect, the program will display an error message and prompt the user to try again.
Accounts are represented by unique account numbers.
Deposits and withdrawals are allowed only for existing accounts with sufficient funds.