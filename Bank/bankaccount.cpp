#include "bankaccount.h"

#include <iostream>

BankAccount::BankAccount()
    : balance(0.0), accountNumber(""), accountHolder("") {}

BankAccount::BankAccount(double initialBalance,
                         const std::string& accountNumber,
                         const std::string& accountHolder)
    : balance(initialBalance),
      accountNumber(accountNumber),
      accountHolder(accountHolder) {}

BankAccount::~BankAccount() {}

double BankAccount::GetBalance() { return balance; }

std::string BankAccount::GetAccountHolder() { return accountHolder; }

std::string BankAccount::GetAccountNumber() { return accountNumber; }

void BankAccount::PrintAccountInfo() {
  std::cout << "====================" << std::endl;
  std::cout << "Account Number: " << GetAccountNumber() << std::endl;
  std::cout << "Account Holder: " << GetAccountHolder() << std::endl;
  std::cout << "Balance: " << GetBalance() << std::endl;
}

bool BankAccount::Deposit(double amount) {
  balance += amount;
  return true;
}

bool BankAccount::Withdraw(double amount) {
  if (balance < amount) {
    std::cout << "Error: Insufficient funds!" << std::endl;
    return false;
  }
  balance -= amount;
  return true;
}
