#ifndef DATABANK_H
#define DATABANK_H

#include "DataTable.h"

using namespace sql::mysql;

class DataBank: private DataTable{
    public:

    // Procedures

    bool changePassword(int key, std::string username, std::string oldPassword, std::string newPassword);

    bool deleteAccount(int key, std::string username, std::string password);

    bool updateMoney(int key, std::string usename, unsigned int money, unsigned int debt);

    bool newAccount(int key, int accountNumber, std::string usename, std::string password, unsigned int money);

    // Functiostd::string
    int checkLogin(int key, std::string username, std::string password);

    int getMoney(int key, std::string username, std::string password);

    int getDebt(int key, std::string username, std::string password);

    int getNet(int key, std::string username, std::string password);
};

#endif