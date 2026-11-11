
#include "ATM.h"
#include <iostream>
#include <iomanip>
using namespace std;

ATM::ATM(BankAccount &a) : account(a) {
    dailyLimit = 10000;
    withdrawnToday = 0;
    savingsTarget = 50000;
    spendingLimit = 5000;
}

void ATM::securityLogin() {
    int enteredPin;

    cout << "\n========== SMART ATM 360 ==========\n";

    for (int i = 0; i < 3; i++) {
        cout << "Enter 4-digit PIN: ";
        cin >> enteredPin;

        if (account.authenticate(enteredPin)) {
            account.displayDetails();
            menu();
            return;
        }
    }

    cout << "\nAccess Denied!\n";
}

void ATM::savingsTracker() {
    double balance = account.getBalance();

    double percentage =
        (balance / savingsTarget) * 100;

    cout << "\n========== SAVINGS TRACKER ==========\n";

    cout << "Savings Target: Rs. "
         << savingsTarget << endl;

    cout << "Current Balance: Rs. "
         << balance << endl;

    if (balance >= savingsTarget) {
        cout << "Congratulations! Savings Goal Achieved!\n";
    }
    else {
        cout << "Remaining Amount: Rs. "
             << savingsTarget - balance << endl;
    }

    cout << "Goal Progress: "
         << fixed << setprecision(2)
         << percentage << "%\n";
}

void ATM::spendingAnalyzer() {
    double spent = account.totalSpending();

    cout << "\n========== SPENDING ANALYZER ==========\n";

    cout << "Total Withdrawals: Rs. "
         << spent << endl;

    cout << "Spending Limit: Rs. "
         << spendingLimit << endl;

    if (spent > spendingLimit) {
        cout << "WARNING: Spending limit crossed!\n";
    }
    else {
        cout << "You are within your spending limit.\n";
    }
}

void ATM::menu() {
    int choice;
    double amount;

    do {
        cout << "\n\n========== MAIN MENU ==========\n";
        cout << "1. Check Balance\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Deposit Money\n";
        cout << "4. Savings Goal Tracker\n";
        cout << "5. Smart Spending Analyzer\n";
        cout << "6. Mini Statement\n";
        cout << "7. Change PIN\n";
        cout << "8. Account Information\n";
        cout << "9. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            account.showBalance();
            break;

        case 2:
            cout << "Enter Withdrawal Amount: Rs. ";
            cin >> amount;

            if (amount > 0 &&
                amount <= dailyLimit - withdrawnToday) {

                if (account.withdraw(amount)) {
                    withdrawnToday += amount;

                    cout << "Remaining Daily Limit: Rs. "
                         << dailyLimit - withdrawnToday << endl;
                }
            }
            else {
                cout << "Daily Limit Exceeded or Invalid Amount!\n";
            }
            break;

        case 3:
            cout << "Enter Deposit Amount: Rs. ";
            cin >> amount;
            account.deposit(amount);
            break;

        case 4:
            savingsTracker();
            break;

        case 5:
            spendingAnalyzer();
            break;

        case 6:
            account.miniStatement();
            break;

        case 7: {
            int oldPin, newPin;

            cout << "Enter Old PIN: ";
            cin >> oldPin;

            cout << "Enter New PIN: ";
            cin >> newPin;

            account.changePIN(oldPin, newPin);
            break;
        }

        case 8:
            account.displayDetails();
            account.showBalance();
            break;

        case 9:
            cout << "\nThank You for Using Smart ATM 360!\n";
            break;

        default:
            cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 9);
}
