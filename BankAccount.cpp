
#include "BankAccount.h"
#include <iomanip>
using namespace std;

BankAccount::BankAccount(string n, int acc, int p, double b) {
    name = n;
    accountNumber = acc;
    pin = p;
    balance = b;

    locked = false;
    attempts = 0;
    transactionID = 1;
}

bool BankAccount::authenticate(int enteredPin) {
    if (locked) {
        cout << "\nACCOUNT LOCKED!\n";
        return false;
    }

    if (enteredPin == pin) {
        attempts = 0;
        cout << "\nLogin Successful!\n";
        return true;
    }

    attempts++;

    cout << "\nIncorrect PIN! Attempts left: "
         << 3 - attempts << endl;

    if (attempts >= 3) {
        locked = true;
        cout << "Security Alert: Account Locked!\n";
    }

    return false;
}

void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        cout << "Invalid amount!\n";
        return;
    }

    balance += amount;
    addTransaction("Deposit", amount);

    cout << "Amount Deposited Successfully!\n";
    receipt("Deposit", amount);
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        cout << "Invalid amount or Insufficient Balance!\n";
        return false;
    }

    balance -= amount;
    addTransaction("Withdrawal", amount);

    cout << "Withdrawal Successful!\n";
    receipt("Withdrawal", amount);

    return true;
}

void BankAccount::addTransaction(string type, double amount) {
    history.push_back(
        Transaction(transactionID++, type, amount, balance)
    );
}

void BankAccount::showBalance() {
    cout << fixed << setprecision(2);

    cout << "\nAvailable Balance: Rs. "
         << balance << endl;
}

void BankAccount::receipt(string type, double amount) {
    cout << "\n========== DIGITAL RECEIPT ==========\n";

    cout << "Account Holder: " << name << endl;
    cout << "Transaction ID: " << transactionID - 1 << endl;
    cout << "Transaction: " << type << endl;
    cout << "Amount: Rs. " << amount << endl;
    cout << "Remaining Balance: Rs. " << balance << endl;

    cout << "=====================================\n";
}

void BankAccount::miniStatement() {
    cout << "\n========== MINI STATEMENT ==========\n";
    cout << "ID\tType\tAmount\tBalance\n";

    if (history.empty()) {
        cout << "No transactions available.\n";
    }

    for (auto &t : history) {
        t.display();
    }

    cout << "====================================\n";
}

double BankAccount::totalSpending() {
    double total = 0;

    for (auto &t : history) {
        if (t.type == "Withdrawal") {
            total += t.amount;
        }
    }

    return total;
}

void BankAccount::changePIN(int oldPin, int newPin) {
    if (oldPin == pin &&
        newPin >= 1000 &&
        newPin <= 9999 &&
        newPin != oldPin) {

        pin = newPin;
        cout << "PIN Changed Successfully!\n";
    }
    else {
        cout << "Invalid old PIN or new PIN!\n";
    }
}

void BankAccount::displayDetails() {
    cout << "\nAccount Holder: " << name;
    cout << "\nAccount Number: " << accountNumber;
    cout << "\nAccount Type: " << accountType() << endl;
}

double BankAccount::getBalance() {
    return balance;
}

BankAccount::~BankAccount() {
    cout << "\nBankAccount object destroyed.\n";
}
