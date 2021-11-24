#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>

#include "DataBank.h"
#include "BankAccount.h"


using namespace std;

class Bank {
    private:

    vector<BankAccount*> bankAccounts; // username as key
    DataBank *table; // not dynamic memory
    int key; // key for the data table

    BankAccount* login(string username, string password);

    public:

    Bank(DataBank *tab = nullptr, vector<BankAccount*> accounts = {}); // only doing this because it is just the constructor

    BankAccount* createUsername(string username, string pasword, unsigned int money);

    bool deleteUsername(string username, string password);
};

#endif