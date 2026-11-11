
#ifndef ATM_H
#define ATM_H

#include "BankAccount.h"

class ATM {
private:
    BankAccount &account;

    double dailyLimit;
    double withdrawnToday;
    double savingsTarget;
    double spendingLimit;

public:
    ATM(BankAccount &a);

    void securityLogin();
    void savingsTracker();
    void spendingAnalyzer();
    void menu();
};

#endif
