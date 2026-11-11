
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string n, int acc, int p, double b);

    string accountType() override;
};

#endif
