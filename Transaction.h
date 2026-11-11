
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction {
public:
    int id;
    string type;
    double amount;
    double balance;

    Transaction(int i, string t, double a, double b);

    void display();
};

#endif
