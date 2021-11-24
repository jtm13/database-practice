#include "Bank.h"

using namespace std;

bool over(string str) {
    return str.size() >= 17;
}

Bank::Bank(DataBank *tab = nullptr, vector<BankAccount*> accounts = {}):
    table(tab), bankAccounts(accounts), key(0){} // Constructor

BankAccount* Bank::login(string username, string password) {
    if (over(username) || over(password)) return nullptr;
    if (table->checkLogin(key, username, password) == 1) {
        unsigned int money = table->getMoney(key, username, password), debt = table->getDebt(key, username, password);
        bankAccounts.push_back(new BankAccount(money, debt, key, username, password, table));
    } // if
    return nullptr;
} // login

BankAccount* Bank::createUsername(string username, string password, unsigned int money) {
    static int accountNumber = 0;
    if (table->newAccount(key, accountNumber++, username, password, money)) {
        bankAccounts.push_back(new BankAccount(money, 0, key, username, password, table));
    } // if
    return nullptr;
} // createUsername

bool Bank::deleteUsername(string username, string password) {
    return table->deleteAccount(key, username, password);
} // deleteUsername
