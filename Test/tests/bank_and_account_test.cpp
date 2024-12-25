#include "bank.h"
#include "bankaccount.h"
#include <gtest/gtest.h>

// BankAccount tests

// 1. Default constructor
TEST(BankAccountTest, DefaultConstructor)
{
    BankAccount account;
    EXPECT_EQ(account.GetBalance(), 0.0);
    EXPECT_EQ(account.GetAccountNumber(), "");
    EXPECT_EQ(account.GetAccountHolder(), "");
}

// 2. Parameterized constructor
TEST(BankAccountTest, ParameterizedConstructor)
{
    BankAccount account(1000.0, "1234567890123456", "John Doe");
    EXPECT_EQ(account.GetBalance(), 1000.0);
    EXPECT_EQ(account.GetAccountNumber(), "1234567890123456");
    EXPECT_EQ(account.GetAccountHolder(), "John Doe");
}

// 3. Deposit balance
TEST(BankAccountTest, Deposit)
{
    BankAccount account(500.0, "1234567890123456", "John Doe");
    EXPECT_TRUE(account.Deposit(200.0));
    EXPECT_EQ(account.GetBalance(), 700.0);
}

// 4. Withdraw balance (successful)
TEST(BankAccountTest, WithdrawSuccess)
{
    BankAccount account(500.0, "1234567890123456", "John Doe");
    EXPECT_TRUE(account.Withdraw(300.0));
    EXPECT_EQ(account.GetBalance(), 200.0);
}

// 5. Withdraw balance (failure)
TEST(BankAccountTest, WithdrawFailure)
{
    BankAccount account(500.0, "1234567890123456", "John Doe");
    EXPECT_FALSE(account.Withdraw(600.0)); // Insufficient funds
    EXPECT_EQ(account.GetBalance(), 500.0);
}

// 6. Get account information
TEST(BankAccountTest, GetAccountInfo)
{
    BankAccount account(500.0, "1234567890123456", "John Doe");
    EXPECT_EQ(account.GetAccountNumber(), "1234567890123456");
    EXPECT_EQ(account.GetAccountHolder(), "John Doe");
    EXPECT_EQ(account.GetBalance(), 500.0);
}

// 7. Print account information
TEST(BankAccountTest, PrintAccountInfo)
{
    BankAccount account(1000.0, "1234567890123456", "John Doe");

    testing::internal::CaptureStdout();
    account.PrintAccountInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Account Number: 1234567890123456"), std::string::npos);
    EXPECT_NE(output.find("Account Holder: John Doe"), std::string::npos);
    EXPECT_NE(output.find("Balance: 1000"), std::string::npos);
}

// Bank tests

// 1. Default constructor
TEST(BankTest, DefaultConstructor)
{
    Bank bank;
    EXPECT_TRUE(bank.GetAccounts().empty());
}

// 2. Add account
TEST(BankTest, AddAccount)
{
    Bank bank;
    BankAccount account(1000.0, "1234567890123456", "John Doe");
    EXPECT_TRUE(bank.AddAccount(account));
    EXPECT_EQ(bank.GetAccounts().size(), 1);
}

// 3. Total balance
TEST(BankTest, GetTotalBalance)
{
    BankAccount account1(1000.0, "1234567890123456", "John Doe");
    BankAccount account2(2000.0, "6543210987654321", "Jane Doe");
    Bank bank({account1, account2});
    EXPECT_EQ(bank.GetTotalBalance(), 3000.0);
}

// 4. Sort accounts
TEST(BankTest, BubbleSortAccounts)
{
    BankAccount account1(1000.0, "6543210987654321", "Jane Doe");
    BankAccount account2(2000.0, "1234567890123456", "John Doe");
    Bank bank({account1, account2});

    bank.BubbleSortAccounts();
    EXPECT_EQ(bank.GetAccounts()[0].GetAccountNumber(), "1234567890123456");
    EXPECT_EQ(bank.GetAccounts()[1].GetAccountNumber(), "6543210987654321");
}

// 5. Generate random accounts
TEST(BankTest, GenerateRandomAccounts)
{
    Bank bank;
    bank.GenerateRandomAccounts(5);
    EXPECT_EQ(bank.GetAccounts().size(), 5);
}

// 6. Print all accounts
TEST(BankTest, PrintAllAccounts)
{
    BankAccount account1(1000.0, "1234567890123456", "John Doe");
    BankAccount account2(2000.0, "6543210987654321", "Jane Doe");
    Bank bank({account1, account2});

    testing::internal::CaptureStdout();
    bank.PrintAllAccounts();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Account Number: 1234567890123456"), std::string::npos);
    EXPECT_NE(output.find("Account Holder: John Doe"), std::string::npos);
}
