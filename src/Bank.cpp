#include "Bank.h"

using namespace std;

bool over(string str) {
    return str.size() >= 17;
}

Bank::Bank(DataBank *tab = nullptr, vector<BankAccount> accounts = {}):
    table(tab), bankAccounts(accounts), key(0){} // Constructor

bool Bank::login(string username, string password) {
    if (over(username) || over(password)) return false;
}