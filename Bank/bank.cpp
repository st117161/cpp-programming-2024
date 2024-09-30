
#include "bank.h"

#include <cstdlib>

#include "bankaccount.h"

Bank::Bank() {}

Bank::Bank(const std::vector<BankAccount>& initialAccounts)
    : bank(initialAccounts) {}

Bank::~Bank() {}

bool Bank::AddAccount(const BankAccount& account) {
  bank.push_back(account);
  isSorted = false;
  return true;
}

double Bank::GetTotalBalance() {
  double totalBalance = 0;
  for (auto& account : bank) {
    totalBalance += account.GetBalance();
  }
  return totalBalance;
}

std::vector<BankAccount>& Bank::GetAccounts() { return bank; }

void Bank::BubbleSortAccounts() {
  bool swapped;
  for (size_t i = 0; i < bank.size() - 1; ++i) {
    swapped = false;
    for (size_t j = 0; j < bank.size() - i - 1; ++j) {
      if (bank[j].GetAccountNumber() > bank[j + 1].GetAccountNumber()) {
        std::swap(bank[j], bank[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

void Bank::PrintAllAccounts() {
  if (!isSorted) {
    BubbleSortAccounts();
    isSorted = true;
  }
  for (auto& account : bank) {
    account.PrintAccountInfo();
  }
}

void Bank::GenerateRandomAccounts(int randomNumber) {
  std::vector<std::string> accountHolders = {
      "Андрей", "Иван",    "Илья",  "Петр",  "Даниил", "Данил",
      "Никита", "Евдокия", "Артём", "Елена", "Алёна"};

  for (int i = 0; i < randomNumber; ++i) {
    double balance = static_cast<double>(rand()) / RAND_MAX * 1200000;
    std::string accountHolder = accountHolders[rand() % accountHolders.size()];
    std::string accountNumber = GenerateAccountNumber();

    BankAccount newAccount(balance, accountNumber, accountHolder);
    AddAccount(newAccount);
  }
}

std::string Bank::GenerateAccountNumber() {
  std::string accountNumber;
  for (int i = 0; i < 16; ++i) {
    accountNumber += std::to_string(rand() % 10);
  }
  return accountNumber;
}
