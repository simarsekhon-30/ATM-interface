#include <iostream>
#include "SavingsAccount.h"
#include "ATM.h"

using namespace std;

int main() {

    // Creating three separate accounts

    SavingsAccount simar(
        "Simar", 2514198, 1234, 20000
    );

    SavingsAccount suman(
        "Suman", 2514199, 2345, 15000
    );

    SavingsAccount sukhman(
        "Sukhman", 2514200, 0987, 25000
       );

    int choice;

    do {
        cout << "\n======= ATM INTERFACE =======\n";

        cout << "1. Simar's Account\n";
        cout << "2. Suman's Account\n";
        cout << "3. Sukhman's Account\n";
        cout << "4. Exit\n";

        cout << "\nSelect Account: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            ATM atm(simar);
            atm.securityLogin();
            break;
        }

        case 2: {
            ATM atm(suman);
            atm.securityLogin();
            break;
        }

        case 3: {
            ATM atm(sukhman);
            atm.securityLogin();
            break;
        }

        case 4:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
