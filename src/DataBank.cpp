#include "DataBank.h"
#include <iostream>

using namespace sql::mysql;
using std::string, std::to_string, std::cout, std::endl;

bool over(string str) {
    return str.size() >= 17;
} // over

bool DataBank::newAccount(int key, int accountNumber, string username, string password, unsigned int money) {
    if (over(username) || over(password)) return false;
    string str{"CALL new_account(" + to_string(accountNumber) + "," + username
        + "," + password + "," + to_string(money) + ");"};
    simpleQuery(key, str);
} // newAccount

bool DataBank::deleteAccount(int key, string username, string password) {
    if (over(username) || over(password)) return false;
    string str{"CALL delete_account(" + username + "," + password + ");"};
    simpleQuery(key, str);
} // deleteAccount

bool DataBank::updateMoney(int key, string username, unsigned int money, unsigned int debt) {
    if (over(username)) return false;
    string str{"CALL update_Money(" + username + "," + to_string(money) + + "," + to_string(debt) + ");"};
    simpleQuery(key, str);
} // update_oney

bool DataBank::changePassword(int key, string username, string oldPassword, string newPassword) {
    if (over(username) || over(oldPassword) || over(newPassword)) return false;
    string str{"CALL change_pass(" + username + "," + oldPassword + + "," + newPassword + ");"};
    simpleQuery(key, str);
} // changePassword

int DataBank::checkLogin(int key, string username, string password) {
    if (over(username) || over(password)) return -2;
    string str{"SELECT check_login(" + username + "," + password + ") FROM bank LIMIT 1;"};
    sql::ResultSet* res = query(key, str);
    if (res != nullptr) {
        try {
            int temp = res->getInt(1);
            delete res;
            return temp;
        } catch (sql::SQLException& e) {
            cout << "# ERR: SQLException in " << __FILE__ 
             << "(" << __FUNCTION__ << ") on line " 
             << __LINE__ << endl
             << "# ERR: " << e.what()
             << " (MySQL error code: " << e.getErrorCode()
             << ", SQLState: " << e.getSQLState() << " )" << endl;
        }
    }
    return -1;
} // checkLogin

int DataBank::getMoney(int key, string username, string password) {
    if (over(username) || over(password)) return false;
    string str{"SELECT getMoney(" + username + "," + password + ") FROM bank LIMIT 1;"};
    sql::ResultSet* res = query(key, str);
    if (res != nullptr) {
        try {
            int temp = res->getInt(1);
            delete res;
            return temp;
        } catch (sql::SQLException& e) {
            cout << "# ERR: SQLException in " << __FILE__ 
             << "(" << __FUNCTION__ << ") on line " 
             << __LINE__ << endl
             << "# ERR: " << e.what()
             << " (MySQL error code: " << e.getErrorCode()
             << ", SQLState: " << e.getSQLState() << " )" << endl;
        }
    }
    return -1;
} // getMoney

int DataBank::getDebt(int key, string username, string password) {
    if (over(username) || over(password)) return false;
    string str{"SELECT getDebt(" + username + "," + password + ") FROM bank LIMIT 1;"};
    sql::ResultSet* res = query(key, str);
    if (res != nullptr) {
        try {
            int temp = res->getInt(1);
            delete res;
            return temp;
        } catch (sql::SQLException& e) {
            cout << "# ERR: SQLException in " << __FILE__ 
             << "(" << __FUNCTION__ << ") on line " 
             << __LINE__ << endl
             << "# ERR: " << e.what()
             << " (MySQL error code: " << e.getErrorCode()
             << ", SQLState: " << e.getSQLState() << " )" << endl;
        }
    } // if
    return -1;
} // getDebt

int DataBank::getNet(int key, std::string username, string password) {
    if (over(username) || over(password)) return false;
    string str{"SELECT getNet(" + username + "," + password + ") FROM bank LIMIT 1;"};
    sql::ResultSet* res = query(key, str);
    if (res != nullptr) {
        try {
            int temp = res->getInt(1);
            delete res;
            return temp;
        } catch (sql::SQLException& e) {
            cout << "# ERR: SQLException in " << __FILE__ 
             << "(" << __FUNCTION__ << ") on line " 
             << __LINE__ << endl
             << "# ERR: " << e.what()
             << " (MySQL error code: " << e.getErrorCode()
             << ", SQLState: " << e.getSQLState() << " )" << endl;
        }
    } // if
    return -1;
} // getNet