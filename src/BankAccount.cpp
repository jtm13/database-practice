#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount(unsigned int mon, unsigned int det, int ky, string user, string pass, DataBank* tab = nullptr):
    money(mon), debt(det), key(ky), username(user), password(password), table(tab) {};

bool BankAccount::updateMoney(unsigned int mon, unsigned int det) {
    return table->updateMoney(key, username, mon, det);
    money = mon;
    debt = det;
} // updateMoney

void BankAccount::setTable(DataBank* tab) {
    table = tab;
} // setTable

bool BankAccount::withdraw(unsigned int minus) {
    unsigned int mon = money, det = debt;
    if (money >= minus) mon -= minus;
    else {
        minus -= mon;
        det += minus;
        mon = 0;
    }
    return updateMoney(mon - minus, det);
} // withdraw

bool BankAccount::deposit(unsigned int plus) {
    return updateMoney(money + plus, debt);
} // deposit

int BankAccount::checkBalance() {
    return table->getNet(key, username, password);
} // checkBalance