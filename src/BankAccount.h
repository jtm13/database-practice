#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "DataBank.h"

class BankAccount {
    private:

    unsigned int money, debt; // money, debt of user
    int key;
    string username, password;
    DataBank *table; // table connection

    bool updateMoney(unsigned int mon, unsigned int det);

    public:

    BankAccount(unsigned int mon, unsigned int det, int ky, string user, string pass, DataBank *tab = nullptr);

    void setTable(DataBank* tab);

    bool withdraw(unsigned int minus);

    bool deposit(unsigned int plus);

    int checkBalance();
}; // class BankAccount

#endif