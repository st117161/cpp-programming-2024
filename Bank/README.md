# Bank Management System

This is a simple bank management system implemented in C++ as part of my homework at Saint Petersburg University (SPbU) for the thirty semester of programming. The system allows users to manage bank accounts with various functionalities.

## Features

- **Add Account**: Create a new bank account with an account holder name, account number, and initial balance.
- **Print All Accounts**: Display all bank accounts sorted by account number.
- **Get Total Balance**: Calculate and display the total balance of all accounts.
- **Generate Random Accounts**: Create a specified number of random accounts for testing purposes.
- **Deposit Money**: Add a specified amount to an existing account.
- **Withdraw Money**: Remove a specified amount from an existing account, ensuring sufficient funds are available.

## Functions

- `Bank()`: Initializes a new bank with no accounts.
- `bool AddAccount(const BankAccount& account)`: Adds a new account to the bank. Returns `true` if successful, or `false` if the account already exists.
- `void PrintAllAccounts()`: Prints all accounts sorted by account number.
- `double GetTotalBalance()`: Returns the total balance of all accounts.
- `void GenerateRandomAccounts(int count)`: Generates a specified number of random bank accounts.
- `BankAccount* findAccountByNumber(const std::string& accountNumber)`: Finds an account by its account number.

## Requirements

- C++17 or later
- g++ compiler

## Build Instructions

To build the project, run the following commands in your terminal:

```bash
make
```

This will compile the code and generate the executable file `Bank`.

## Clean Up

To remove the object files and the compiled executable, run:

```bash
make clean
```

## License

This project is licensed under the Apache-2.0 License - see the [LICENSE](LICENSE) file for details.
