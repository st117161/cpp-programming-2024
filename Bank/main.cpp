#include <iostream>
#include <limits>

#include "bank.h"
#include "bankaccount.h"
#include "helper.h"

void displayMenu() {
  std::cout << "====== Bank Menu ======" << std::endl;
  std::cout << "1. Add Account" << std::endl;
  std::cout << "2. Print All Accounts" << std::endl;
  std::cout << "3. Get Total Balance" << std::endl;
  std::cout << "4. Generate Random Accounts" << std::endl;
  std::cout << "5. Deposit Money" << std::endl;
  std::cout << "6. Withdraw Money" << std::endl;
  std::cout << "7. Exit" << std::endl;
  std::cout << "=======================" << std::endl;
}

BankAccount* findAccountByNumber(Bank& bank, const std::string& accountNumber) {
  for (auto& account : bank.GetAccounts()) {
    if (account.GetAccountNumber() == accountNumber) {
      return &account;
    }
  }
  return nullptr;
}

int main() {
  Bank myBank;
  int choice;

  while (true) {
    displayMenu();
    correct(choice);

    switch (choice) {
      case 1: {
        std::string accountHolder, accountNumber;
        double initialBalance;

        std::cout << "Enter account holder name: ";
        std::cin >> accountHolder;

        std::cout << "Enter initial balance: ";
        while (!(std::cin >> initialBalance) || initialBalance < 0) {
          std::cout << "Invalid input. Balance should be non-negative. Please "
                       "try again: ";
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Enter account number (16 digits): ";
        while (!(std::cin >> accountNumber) || accountNumber.length() != 16) {
          std::cout << "Invalid account number. It should be 16 digits long. "
                       "Please try again: ";
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (findAccountByNumber(myBank, accountNumber) != nullptr) {
          std::cout << "An account with this number already exists. Please try "
                       "again with a different account number."
                    << std::endl;
          break;
        }

        BankAccount newAccount(initialBalance, accountNumber, accountHolder);
        if (myBank.AddAccount(newAccount)) {
          std::cout << "Account added successfully!" << std::endl;
        } else {
          std::cout << "Error adding account." << std::endl;
        }
        break;
      }
      case 2: {
        myBank.PrintAllAccounts();
        break;
      }
      case 3: {
        std::cout << "Total balance in the bank: " << myBank.GetTotalBalance()
                  << std::endl;
        break;
      }
      case 4: {
        int randomNumber;
        std::cout << "Enter the number of random accounts to generate: ";
        correct(randomNumber);
        myBank.GenerateRandomAccounts(randomNumber);
        std::cout << randomNumber << " random accounts generated." << std::endl;
        break;
      }
      case 5: {
        std::string accountNumber;
        std::cout << "Enter account number (16 digits): ";
        std::cin >> accountNumber;

        BankAccount* account = findAccountByNumber(myBank, accountNumber);
        if (account) {
          double depositAmount;
          std::cout << "Enter amount to deposit: ";
          while (!(std::cin >> depositAmount) || depositAmount <= 0) {
            std::cout << "Invalid input. Please enter a positive amount: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          }
          account->Deposit(depositAmount);
          std::cout << "Deposit successful. New balance: "
                    << account->GetBalance() << std::endl;
        } else {
          std::cout << "Account not found." << std::endl;
        }
        break;
      }
      case 6: {
        std::string accountNumber;
        std::cout << "Enter account number (16 digits): ";
        std::cin >> accountNumber;

        BankAccount* account = findAccountByNumber(myBank, accountNumber);
        if (account) {
          double withdrawAmount;
          std::cout << "Enter amount to withdraw: ";
          while (!(std::cin >> withdrawAmount) || withdrawAmount <= 0) {
            std::cout << "Invalid input. Please enter a positive amount: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          }
          if (account->Withdraw(withdrawAmount)) {
            std::cout << "Withdrawal successful. New balance: "
                      << account->GetBalance() << std::endl;
          } else {
            std::cout << "Error: Insufficient funds!" << std::endl;
          }
        } else {
          std::cout << "Account not found." << std::endl;
        }
        break;
      }
      case 7: {
        std::cout << "Exiting the program. Goodbye!" << std::endl;
        return 0;
      }
      default: {
        std::cout << "Invalid choice. Please try again." << std::endl;
        break;
      }
    }
  }

  return 0;
}
