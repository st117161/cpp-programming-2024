#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>

class BankAccount {
 private:
  double balance;
  std::string accountNumber;
  std::string accountHolder;

 public:
  BankAccount();
  BankAccount(double initialBalance, const std::string& accountNumber,
              const std::string& accountHolder);
  ~BankAccount();
  bool Deposit(double amount);
  bool Withdraw(double amount);
  double GetBalance();
  std::string GetAccountNumber();
  std::string GetAccountHolder();
  void PrintAccountInfo();
};

#endif  // BANKACCOUNT_H
