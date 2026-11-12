
#include "Transaction.h"
#include <iostream>
#include <iomanip>
using namespace std;

Transaction::Transaction(int i, string t, double a, double b) {
 id = i;
 type = t;
 amount = a;
 balance = b;
}

void Transaction::display() {
    cout << id << "\t"
         << type << "\t"
         << fixed << setprecision(2)
         << amount << "\t"
         << balance << endl;
}
