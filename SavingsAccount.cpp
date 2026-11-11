
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(string n, int acc, int p, double b)
    : BankAccount(n, acc, p, b) {
}

string SavingsAccount::accountType() {
    return "Savings Account";
}
