#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>

#include "DataTable.h"
#include "BankAccount.h"


using namespace std;

class Bank {
    private:

    vector<BankAccount> bankAccounts; // username as key
    DataTable *table; // not dynamic memory
    int key; // key for the data table

    bool login(string username, string password);

    public:

    Bank(DataTable *tab = nullptr, vector<BankAccount> accounts = {}); // only doing this because it is just the constructor

    bool createUsername(string username, string pasword, unsigned int money);

    bool deleteUsername(string username, string password);
};

#endif