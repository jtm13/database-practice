#include "Bank.h"

using namespace std;

Bank::Bank(DataTable *tab = nullptr, vector<BankAccount> accounts = {}):
    table(tab), bankAccounts(accounts), key(0){} // Constructor