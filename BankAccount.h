
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <vector>
#include <string>
#include "Transaction.h"

using namespace std;

class BankAccount {
protected:
    string name;
    int accountNumber;
    int pin;
    double balance;

    bool locked;
    int attempts;

    vector<Transaction> history;
    int transactionID;

public:
    BankAccount(string n, int acc, int p, double b);

    virtual string accountType() = 0;

    bool authenticate(int enteredPin);

    void deposit(double amount);
    bool withdraw(double amount);

    void addTransaction(string type, double amount);

    void showBalance();
    void receipt(string type, double amount);
    void miniStatement();

    double totalSpending();

    void changePIN(int oldPin, int newPin);

    void displayDetails();
    double getBalance();

    virtual ~BankAccount();
};

#endif
