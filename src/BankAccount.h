#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "DataTable.h"

class BankAccount {
    private:

    int userId; // UserId
    DataTable *table; // table connection

    bool updateMoney(int realMoney);

    public:

    BankAccount(int id, DataTable *tab = nullptr);

    void setTable(DataTable tab);

    bool withdraw(int minus);

    bool deposit(int plus);

    int checkBalance();
}; // class BankAccount

#endif