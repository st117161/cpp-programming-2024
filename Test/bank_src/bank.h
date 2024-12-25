#ifndef BANK_H
#define BANK_H
#include <vector>

#include "bankaccount.h"

class Bank {
 private:
  std::vector<BankAccount> bank;
  bool isSorted = true;
  std::string GenerateAccountNumber();

 public:
  Bank();
  Bank(const std::vector<BankAccount>& initialAccounts);
  ~Bank();

  void BubbleSortAccounts();
  bool AddAccount(const BankAccount& account);
  double GetTotalBalance();
  std::vector<BankAccount>& GetAccounts();
  void PrintAllAccounts();
  void GenerateRandomAccounts(int randomNumber);
};

#endif  // BANK_H
